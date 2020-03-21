/*************************************************************************************************/
/*!
 *  \file   app_slave_leg.c
 *
 *  \brief  Application framework module for legacy slave.  This module can be used with both
 *          DM legacy and extended advertising.
 *
 *          $Date: 2016-12-28 16:12:14 -0600 (Wed, 28 Dec 2016) $
 *          $Revision: 10805 $
 *
 *  Copyright (c) 2016-2017 ARM Ltd., all rights reserved.
 *  ARM confidential and proprietary.
 *
 *  IMPORTANT.  Your use of this file is governed by a Software License Agreement
 *  ("Agreement") that must be accepted in order to download or otherwise receive a
 *  copy of this file.  You may not use or copy this file for any purpose other than
 *  as described in the Agreement.  If you do not agree to all of the terms of the
 *  Agreement do not use this file and delete all copies in your possession or control;
 *  if you do not have a copy of the Agreement, you must contact ARM Ltd. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/

#include <string.h>
#include "wsf_types.h"
#include "wsf_assert.h"
#include "wsf_trace.h"
#include "dm_api.h"
#include "app_api.h"
#include "app_main.h"

/*************************************************************************************************/
/*!
 *  \fn     appSlaveLegAdvStart
 *
 *  \brief  Utility function to start legacy advertising.
 *
 *  \return None.
 */
/*************************************************************************************************/
static void appSlaveLegAdvStart(void)
{
  uint8_t  advHandle;
  uint8_t  maxEaEvents;
  uint16_t interval;

  interval = pAppAdvCfg->advInterval[appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT]];

  /* if this advertising state is being used */
  if (interval > 0)
  {
    advHandle = DM_ADV_HANDLE_DEFAULT;
    maxEaEvents = 0;

    appAdvStart(1, &advHandle, &interval,
                &(pAppAdvCfg->advDuration[appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT]]),
                &maxEaEvents, TRUE);
  }
  else
  {
    /* done with all advertising states */
    appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT] = APP_ADV_STOPPED;
  }
}

/*************************************************************************************************/
/*!
 *  \fn     appSlaveLegAdvTypeChanged
 *
 *  \brief  Utility function to handle change in advertising type.
 *
 *  \param  pMsg    Pointer to DM callback event message.
 *
 *  \return None.
 */
/*************************************************************************************************/
static void appSlaveLegAdvTypeChanged(dmEvt_t *pMsg)
{
  /* clear advertising type changed flag */
  appSlaveCb.advTypeChanged[DM_ADV_HANDLE_DEFAULT] = FALSE;

  /* set advertising state */
  appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT] = APP_ADV_STATE1;

  /* start advertising */
  appSlaveLegAdvStart();
}

/*************************************************************************************************/
/*!
 *  \fn     appSlaveNextLegAdvState
 *
 *  \brief  Set the next advertising state.
 *
 *  \param  pMsg    Pointer to DM callback event message.
 *
 *  \return None.
 */
/*************************************************************************************************/
static void appSlaveNextLegAdvState(dmEvt_t *pMsg)
{
  /* go to next advertising state */
  appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT]++;

  /* if haven't reached stopped state then start advertising */
  if (appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT] < APP_ADV_STOPPED)
  {
    appSlaveLegAdvStart();
  }
}

/*************************************************************************************************/
/*!
 *  \fn     appSlaveLegAdvStop
 *
 *  \brief  Handle DM_ADV_SET_STOP_IND and DM_ADV_STOP_IND events.
 *
 *  \param  pMsg      Pointer to DM callback event message.
 *
 *  \return None.
 */
/*************************************************************************************************/
static void appSlaveLegAdvStop(dmEvt_t *pMsg)
{
  /* if legacy advertising PDUs are used with advertising extensions feature */
  if (pMsg->hdr.event == DM_ADV_SET_STOP_IND)
  {
    /* if advertising successfully ended with connection being created */
    if (pMsg->advSetStop.status == HCI_SUCCESS)
    {
      /* connection open indication event will determine next advertising state */
      return;
    }
  }

  /* if advertising was stopped for change to advertising type */
  if (appSlaveCb.advTypeChanged[DM_ADV_HANDLE_DEFAULT])
  {
    appSlaveLegAdvTypeChanged(pMsg);
  }
  /* else advertising ended for another reason */
  else
  {
    appSlaveNextLegAdvState(pMsg);
  }
}

/*************************************************************************************************/
/*!
 *  \fn     appSlaveLegAdvRestart
 *
 *  \brief  Restart advertising.
 *
 *  \param  pMsg    Pointer to DM callback event message.
 *
 *  \return None.
 */
/*************************************************************************************************/
static void appSlaveLegAdvRestart(dmEvt_t *pMsg)
{
  if (pMsg->hdr.event == DM_CONN_OPEN_IND)
  {
    /* advertising is stopped once a connection is opened */
    appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT] = APP_ADV_STOPPED;
  }

  /* if advertising stopped restart advertising */
  if (appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT] == APP_ADV_STOPPED)
  {
    /* set advertising state */
    appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT] = APP_ADV_STATE1;

    /* start advertising */
    appSlaveLegAdvStart();
  }
}

/*************************************************************************************************/
/*!
 *  \fn     appSlaveAdvMode
 *
 *  \brief  Check if current advertising mode is legacy advertising.
 *
 *  \return TRUE if legacy advertising mode. FALSE, otherwise.
 */
/*************************************************************************************************/
static bool_t appSlaveAdvMode(void)
{
  /* legacy app slave works with both DM legacy and extended advertising */

  /* if first time since last power-on or reset */
  if (appSlaveCb.advStopCback == NULL)
  {
    appSlaveCb.advStopCback = appSlaveLegAdvStop;
    appSlaveCb.advRestartCback = appSlaveLegAdvRestart;

    return TRUE;
  }

  if (appSlaveCb.advStopCback == appSlaveLegAdvStop)
  {
    return TRUE;
  }

  APP_TRACE_WARN0("Invalid DM advertising mode; mode configured as extended");

  return FALSE;
}

/*************************************************************************************************/
/*!
 *  \fn     AppAdvSetData
 *
 *  \brief  Set advertising data.
 *
 *  \param  location  Data location.
 *  \param  len       Length of the data.  Maximum length is 31 bytes.
 *  \param  pData     Pointer to the data.
 *
 *  \return None.
 */
/*************************************************************************************************/
void AppAdvSetData(uint8_t location, uint8_t len, uint8_t *pData)
{
  if (appSlaveAdvMode())
  {
    /* legacy advertising data length cannot exceed 31 bytes */
    if (len > HCI_ADV_DATA_LEN)
    {
      len = HCI_ADV_DATA_LEN;
    }

    /* maximum advertising data length supported by Controller is 31 bytes */
    appAdvSetData(DM_ADV_HANDLE_DEFAULT, location, len, pData, HCI_ADV_DATA_LEN, HCI_ADV_DATA_LEN);
  }
}

/*************************************************************************************************/
/*!
 *  \fn     AppAdvStart
 *
 *  \brief  Start advertising using the parameters for the given mode.
 *
 *  \param  mode      Discoverable/connectable mode.
 *
 *  \return None.
 */
/*************************************************************************************************/
void AppAdvStart(uint8_t mode)
{
  uint8_t advHandle;
  uint8_t maxEaEvents;

  if (appSlaveAdvMode())
  {
    advHandle = DM_ADV_HANDLE_DEFAULT;
    maxEaEvents = 0;

    /* initialize advertising state */
    appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT] = APP_ADV_STATE1;

    appSlaveAdvStart(1, &advHandle, &(pAppAdvCfg->advInterval[APP_ADV_STATE1]),
                     &(pAppAdvCfg->advDuration[APP_ADV_STATE1]), &maxEaEvents, TRUE, mode);
  }
}

/*************************************************************************************************/
/*!
 *  \fn     AppAdvStop
 *
 *  \brief  Stop advertising.
 *
 *  \return None.
 */
/*************************************************************************************************/
void AppAdvStop(void)
{
  uint8_t advHandle;

  if (appSlaveAdvMode())
  {
    advHandle = DM_ADV_HANDLE_DEFAULT;

    appAdvStop(1, &advHandle);
  }
}

/*************************************************************************************************/
/*!
 *  \fn     AppAdvSetAdValue
 *
 *  \brief  Set the value of an advertising data element in the advertising or scan
 *          response data.  If the element already exists in the data then it is replaced
 *          with the new value.  If the element does not exist in the data it is appended
 *          to it, space permitting.
 *
 *          There is special handling for the device name (AD type DM_ADV_TYPE_LOCAL_NAME).
 *          If the name can only fit in the data if it is shortened, the name is shortened
 *          and the AD type is changed to DM_ADV_TYPE_SHORT_NAME.
 *
 *  \param  location  Data location.
 *  \param  adType    Advertising data element type.
 *  \param  len       Length of the value.  Maximum length is 31 bytes.
 *  \param  pValue    Pointer to the value.
 *
 *  \return TRUE if the element was successfully added to the data, FALSE otherwise.
 */
/*************************************************************************************************/
bool_t AppAdvSetAdValue(uint8_t location, uint8_t adType, uint8_t len, uint8_t *pValue)
{
  if (appSlaveAdvMode())
  {
    return appAdvSetAdValue(DM_ADV_HANDLE_DEFAULT, location, adType, len, pValue);
  }

  return FALSE;
}

/*************************************************************************************************/
/*!
 *  \fn     AppSetAdvType
 *
 *  \brief  Set advertising type.
 *
 *  \param  advType   Advertising type.
 *
 *  \return None.
 */
/*************************************************************************************************/
void AppSetAdvType(uint8_t advType)
{
  if (appSlaveAdvMode())
  {
    appSetAdvType(DM_ADV_HANDLE_DEFAULT, advType,
                  pAppAdvCfg->advInterval[appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT]],
                  pAppAdvCfg->advDuration[appSlaveCb.advState[DM_ADV_HANDLE_DEFAULT]], 0, TRUE);
  }
}

/*************************************************************************************************/
/*!
 *  \fn     AppConnAccept
 *
 *  \brief  Accept a connection to a peer device with the given address.
 *
 *  \param  advType   Advertising type.
 *  \param  addrType  Address type.
 *  \param  pAddr     Peer device address.
 *
 *  \return None.
 */
/*************************************************************************************************/
void AppConnAccept(uint8_t advType, uint8_t addrType, uint8_t *pAddr)
{
  if (appSlaveAdvMode())
  {
    appConnAccept(DM_ADV_HANDLE_DEFAULT, advType, pAppAdvCfg->advInterval[APP_ADV_STATE1],
                  pAppAdvCfg->advDuration[APP_ADV_STATE1], 0, addrType, pAddr);
  }
}
