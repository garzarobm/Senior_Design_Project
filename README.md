# Senior_Design_Project

In this repository, you will find our 2019-2020 Senior Design project. 

The structure of this repository is as follows (updated December 21, 2019)

--API--
#This has a folder for publishing of created apis under python-docs-samples and a folder for team member to edit our api as he pleases. SocialBitApi will be published to google cloud platform using a starter api package found online

--AndroidApp--
#In this folder contails the starter android application that the software team used to create at the beggining of the semester. We moved to native application for prototype testing and editing in the middle of the Fall 2019 but will most likely move back to Android as of Spring 2020

--Audio--
#In the folder audio, we have our python file that uses the raspberry pi to continously record audio and analyze this that will get sent to our api that we currently have running.


--HardwareTesting--
#We utilized python scripts to get the audio files from the MEMMS microphone to work 

--STL--
#folder that we placed our memms microphones in.

--ambiqMicro/AmbiqSuite-Rel2.2.0--
#this contains the sdk of the ambiq Micro if we are to develop using solely the sdk.


--bluetooth--
#this contains a script to connect an android device to a raspberry pi and send basic images to the device itself.

--nativeApp--
#This contains our prototype application that we displayed in our presentation.

--raspberryPi--
#This contains information if we are to manually boot our raspberry pi from a usb rather than using the sd card.

-Copy_of_Welcome_To_Colaboratory.ipynb-
#our current collaboratoery notebook that is online for configuration of our machine learning module.
-README.md- 
#the contents of this paper


Here lies our system design report that has a overview of our project as a whole below...

DATE:       	December 6th, 2019
TO:             	Edison Thomaz 
Rebecca Kurlak
FROM:       	Miguel Garza Robledo
Filipe Rubinstein
Rebecca Phung
Mircea Antonescu
Errol Williams
Michael Hernandez
Alexander Phillips 
SUBJECT:	Current design report for the SocialBit heading into EE464. We breakdown the background, system design, and project management for our device. 

1.0 INTRODUCTION 
The System Design Report summarizes our design problem objective, the progress we have made towards solving this problem, and the future steps we need to take to complete our design. First, we will discuss our design objective, which is to create a wearable device capable of providing analysis about its users’ social interactions. Our solution for this problem is to create a device that receives audio data in real-time, processes the data on-board to extract information about the audio, and sends the analysis of the data to an Android application to display the analysis. 
Next, we will discuss the progress that we have made to complete this project. We decided to divide our group into three teams to each focus on a specific component of the objective: hardware, software, and machine learning. Each team researched prior art and related patents to provide a foundation for our design choices. Furthermore, each team, as well as each individual, completed risk reductions to ensure the project would progress smoothly. One of these risk reductions from the hardware, software, and machine learning teams include moving forward with the decision to use the Ambiq Micro Apollo3 Blue processor chip to control the SocialBit system, creating a basic application to serve as the foundation of the UI, and exploring basic models to classify the audio. For the rest of the paper, we will refer to the Ambiq Micro Apollo3 Blue as the Ambiq Micro. The hardware team is tasked with designing and creating the physical device that will capture and process the audio. The machine learning team will focus on extracting features from the audio and performing analysis on it to gain insight about the user’s social interactions. The software team will create the application to receive the data analysis through Bluetooth and display the results in an intuitive user interface.
Lastly, we will outline what our next steps will be to complete our project and how we plan to ensure that we will be able to execute those next steps. We will describe our proposed timeline, the deliverables that we wish to have completed at each stage, and the project management skills we have employed to keep the project on track. We will also discuss the testing we will do for each team as well as how we will measure success for each team’s testing. 
 
2.0 DESIGN PROJECT BACKGROUND
Our device is called SocialBit, as it is a wearable device similar to a Fitbit®, but it analyzes social activity instead of physical activity. We believe that this project will benefit researchers that want to know more about the realm of human behavior. One of these researchers working in the study of human signals include Edison Thomaz, our faculty mentor, who wants to perform analysis on human behavior such as speech. Thomaz is interested in creating a device that is able to record audio containing human speech and extract features such as being able to track the number of people in a conversation. In addition, the device itself would obtain emotional information, and be able to make inferences on whether an individual is sad, angry, happy, or other relevant feelings during the course of a conversation. The problem we are trying to solve is that there is currently not a device capable of determining the number of conversations an individual has based off recorded audio. We are aiming to solve this problem by using an on-board machine learning model. There have been products related to capturing audio and giving users information related to those conversations, but they have not aimed to be as mobile as our project which gives users more data related to their conversations by wearing a wrist-device. 
Therefore, we have challenges to accomplish this task in regards to hardware, machine learning, and software in order to develop our system. Some of them are basic requirements needed to get our system running, while others are design choices we believe will get us to our final product. In the following sections, we list out the specifications in section 2.1 for our device in terms of hardware, software, and machine learning needed to create a device capable of recording conversations and making inferences from the recorded audio. Under hardware, we specify power efficiency, speed, and design size. Under software, we specify a traversable user interface. Lastly, we specify feature selection and model accuracy under machine learning. We also describe our project’s deliverables at the end of our project which includes a wrist-watch device, an on-board model, and an Android application to display our results in section 2.2. 

2.1 Specifications 
We have broken down our specifications based on the teams we have: hardware, machine learning, and software. For hardware, our design specifications will focus on power efficiency, speed, and design size. For software, our design specifications will include a user interface and app communication with the prototype device. Lastly, our machine learning team focus on specifications related to feature selection and model accuracy. In each section, we explain why we chose each specific requirement and list any material that is similar to what we have chosen in comparable fields. These requirements will help us meet our end goal deliverables.

2.1.1 Hardware Specifications
Our team’s hardware design focuses on power efficiency, speed, and design size. We used the characteristics of an Apple Watch as a basis to create our hardware specifications. Our design, just like the Apple Watch, will be in the shape of a rectangular box and will aim to have a similar power efficiency. 
For power efficiency, we have decided to build a device based on other similar wearable devices in the market that consumes under 1.4Wh rating and lasts 5-7 hours [1]. We selected a power consumption slightly higher than any Apple Watch produced to date because our device is similar to an Apple Watch [2, pp. 5-8]. We selected a battery life at a third of an Apple Watch because our device is aimed towards higher performance than the Apple Watch. The next specification is speed, as we must be able to process audio in nearly real-time. By processing the audio as close to real-time as possible, we can analyze  and send data to the user without missing any additional information. Lastly, our device’s area has to be under 1936mm2, which falls within the area of usual smartwatch devices so the user will be able to wear this device on their wrist[3]. 

2.1.2 Software Specifications
For the Android application, there are two main specifications. The first one is a user interface that is traversable and appealing. The second is successful communication between the physical device and application. The focus is on user friendliness, which means keeping all of the available features in plain sight and making navigation between activities painless. To achieve this, all of the activities are seen as tabs at the top of the screen. This makes it so that no activities are hidden from the user. We have also maximized the functionality of each activity and therefore kept the total number of activities at a minimum, namely 3. Communication is currently done through a web server API. This was chosen since we encountered some difficulties with Bluetooth. Ultimately, however, to increase data security, we shall move over to Bluetooth as the primary form of communication. Bluetooth will increase the overall security of the system because of its short range and its independence from the internet.

2.1.3 Machine Learning Specifications
The main specifications guiding the machine learning team are feature selection and model accuracy for both the audio classification and speaker diarization models. Our focus on feature selection is done so we can identify which audio features produce the best results for our models while still allowing for fast processing. We focus on accuracy because we want to ensure that the conclusions drawn from each model’s output are relevant.
To address feature selection, we looked into prior art in the areas of audio classification and speaker diarization for guidance. The G.729 patent, an audio compression patent which includes information about voice activity detection, has helped us determine some of the features that are important for audio classification such as zero crossing rate and Mel Frequency Cepstral Coefficients [4].  Similarly, the paper Fully Supervised Speaker Diarization, a paper that details Google’s state of the art speaker diarization system, has allowed us to determine important features in speaker diarization such as MFCC coefficients and full-band energy [5].  Using these features as a starting point we will then tune further to ensure that the model is able to inference in real-time. For model accuracy, each model should achieve at least 80% accuracy when tested with any set of audio samples outside of our dataset. To test the accuracy of our audio classification model, we are using audio data and labels from the Freesound General-Purpose Audio Tagging Challenge hosted by Google [6]. To test the accuracy of our speaker identification model, we are using the NIST SRE 2000 CALLHOME dataset [7].

2.2 Deliverables
This project will present multiple deliverables to Professor Thomaz needed to satisfy the SocialBit specifications and design requirements. We will need to create a wrist-watch version of our device, install a machine learning model onto the device, and create an Android App that will communicate with the device and serve as the main display of information.
The wrist-watch will be able to capture and analyze audio as close to real-time as possible, and it will need to send data to the Android application frequently, around every minute. The machine learning model will be responsible for classifying audio and extracting key features related to social interactions. It will serve as a framework to classify audio as speech, music, or ambient noise. The framework will then breakdown speech to provide more analysis based on the number of people within the conversation.  Lastly, the Android application will display the recorded metrics that were communicated from the wrist-watch device. It will need to display them in a user-friendly manner.

3.0 SYSTEM DESIGN 
The following sections describe an overview of our SocialBit design as well as activities taken to reduce the risk of our project. The SocialBit consists of three different subsystems: hardware, software, and machine learning. For hardware, the fundamental design consists of using an Ambiq Micro chip, MEMS microphones, and a Bluetooth/Wi-fi module for communicating data to the user encased in a watch-like structure. For software, the basic design consists of a mobile app with different options for the user to view the rate of their social interactions with others and has Bluetooth connectivity to the physical device. For machine learning, the design shall use free online audio data sets to train classification models. 
For each subsystem design choice, our team will thoroughly discuss the reasons for choosing that characteristic of the SocialBit as well as how that choice interacts with the other subsystems of the SocialBit. In addition, our team will also discuss each of the ten risk reduction activities performed and will demonstrate how each activity contributed towards the progression of the SocialBit prototype. All risk reduction activities were successful. We completed activities such as being able to record audio, analyze said audio, and subsequently send the analysis results to the user. These activities were among the most important due to incorporating the total process of our SocialBit system.
Finally, we will discuss the testing our team will perform in the next semester. For hardware, our team will transition to using an Ambiq Micro microcontroller development board and test its audio recognition potentials. We will also optimize the casing structure that our board will be enclosed in. For software, our team will test the effective range of the Bluetooth communication with the SocialBit device and display real-time data. The machine learning team will first test the model using a Python notebook for features and accuracy, and later move the model to the Ambiq Micro and adjust for microphone audio quality capture.

3.1 Design Concepts 
The following sections describe the specifications of our system design used to create the SocialBit. The design details are broken up in three different subsystems: hardware, software, and machine learning. For hardware, the design consists of using the Ambiq Micro chip to control the entire system,a pair of microelectromechanical system microphones and a Bluetooth module. For software, the design consists of a user-friendly phone app that actively receives data from the SocialBit device through Bluetooth. For machine learning, the design shall consist of a LibROSA Python library that extracts characteristics from a given audio segment and XGBoost that is capable of classifying the audio as noise, music, or speech.  Our team will describe the process that each subsystem performs and describe the reasoning for selecting that process.

3.1.1 Hardware Design
For the hardware design, Figure 1 describes the high-level system of the SocialBit prototype board. The system is comprised of the Ambiq Micro chip, microelectromechanical system (MEMS) microphones, and a Bluetooth/Wi-fi module chip. The board continuously samples audio from the microphones and then extracts audio features using the on-board model.Once the audio has been analyzed, the system will send the results to the user’s mobile app using Bluetooth/Wi-fi. A power management submodule on our board will manage the power supply of all other components. 
More specifically, our system uses a MEMS microphone with an appropriate baud rate to extract precise audio recordings at a low power consumption. Once the audio has been sampled, our models will classify that audio on the board. The system will then send data through our ESP8266 which handles Bluetooth/Wi-fi communication. We have selected the Ambiq Micro to perform this task due to its ability to use TensorFlow to perform audio analysis as well as its small form factor and its low power consumption [8].

Figure 1. SocialBit Hardware Subsystem Block Diagram

For the aesthetic of the Socialbit, our team decided that our physical design would be watch-like. We did this based off of two sources: a patent listing a device that was similar to what we are aiming to do, and another source indicating social constructs associated with a watch. The patent gives us a general template to follow because it answers questions we would have from creating a watch such as the common components needed, and where to place the components [9]. Some of the components the patent addresses includes the band, case structure, and dimensions of the watch. However, our design would be different because the patent does not use machine learning or real-time processing. The patent lists that the processing method they use analyzes 60 seconds of audio [9, pp. 2]. Our structure would also be different because we would have an opening on the side to allow us to provide updates via USB, and charge the device if needed.  In regards to placement of different components within the structure, we would place the microphones on top to reduce size and increase recording capabilities. We would also enclose the Ambiq Micro chip and Bluetooth/Wi-fi chip in the center because these parts do externally connect to other components like a charger. This will allow us to save space for our structure, and would protect the Ambiq Micro chip from being exposed. 

From the social construct article, we found that using a watch-like structure is useful because it allows a user to be comfortable wearing the device [10, pp. 277-278]. A smart-watch is seen as a fashion item because it is visible for others to see and it will not attract negative perceptions. It will appear normal to others. A user will also be more comfortable wearing the device because of its usefulness to them. They will be able to use the device with little effort, and continue about their daily tasks. From the article, they found a positive correlation to acceptance of smart-watches when visibility and usefulness were factors they considered, and we believe these two features will drive users to wear our device and use it throughout the day [10, pp. 280]. By being on a user’s wrist, we will be able to collect more data from their conversations.

3.1.2 Software Design
The goal of the software team is to create a phone app that will allow the user to easily see and interact with the data provided by the physical device. For this to happen, the app must have the capability to communicate with the device and display a user friendly interface. 
The overall structure of the app right now has three basic activities: where one can see the interactions for the current day, interactions for the week, and another activity for settings. There are tabs for the three activities at the top of the screen so it’s all in plain sight. Often with new applications, users tend to miss important features because they do not know how to access them, so we decided to avoid this issue by using the tab format. 
For communication, it was decided that the best way to interact with the device would be through Bluetooth. The app uses the phone’s built in Bluetooth feature to quickly connect to the physical device and receive data. This data then updates the existing graphs on the first two activities. Our rationale for choosing Bluetooth was because unlike near field communication (NFC), Bluetooth has longer range and unlike Wi-fi, Bluetooth does not require internet and is more robust against data leaks.

3.1.3 Machine Learning Design
The goal of our machine learning design is to extract various features from sampled audio and classify it as noise, speech, or music. Additionally, if the audio is classified as speech, a different machine learning algorithm will extract more information from the audio, such as how many speakers are present or features describing emotional content. For our feature extraction, we use the LibROSA Python library, and for our current machine learning model, we use an XGBoost classification model.
Our training data comes mostly from the Freesound Dataset, a labelled collection of many short audio samples. To train our model, we split each audio file into shorter segments of equal length and extracted key features. Each set of features is then used to train the classification model that outputs if the audio is speech, noise, or music. For future models that can determine other information about the audio, we will use either TensorFlow, or similar models using XGBoost.
In order to determine which audio features would be most useful in classifying audio, we looked at a patent involving detecting voice activity in audio [4]. We will start our design by using the same features used by the algorithm. These features include spectral frequencies, full-band energy, low-band energy, and zero-crossing rate and are calculated as the primary features for distinguishing if speech is present [4, pp. 66]. For the SocialBit, we also calculate the estimated tempo and onset strength of the audio sample, as these features can help determine if audio contains music. The patent also incorporates a smoothing algorithm that uses data from recently recorded audio to help determine what the classification of the next audio sample should be, since both classifications will likely be the same [4, pp. 67]. We ultimately will end up using a similar algorithm for the SocialBit, as we also expect most audio inputs to the device to be somewhat constant over time.

3.2 Risk Reduction
In total, we completed 10 risk reductions. We had 3 team risk reductions and then 7 individual risk reductions. Our team risk reductions were divided to give each team (hardware, machine learning, and software) a task to complete while the individual risk reductions were based on where team members lied within their respective teams. All of our risk reduction activities proved to be successful. Within the following sections, we list out what our risk reductions are, how we tested them to ensure they worked, and how they helped us reach our end goal of developing the SocialBit.

3.2.1 Hardware Risk Reductions
The overall hardware team’s risk reduction was to capture audio on the Raspberry Pi and classify that audio using one of our models. Our team decided that this team risk reduction activity was important to the completion of the project as being able to capture and process audio, fulfilled two-thirds of the full requirements of our SocialBit system. To test the successful completion of this risk reduction activity, our team used several USB microphones attached to the Raspberry Pi and recorded live speech. We then used internal features of the Raspberry Pi to playback the audio to confirm it was recorded. After we determined it was recorded, we used the model to classify the audio. Here, we said it was successful because each recording was classified and we classified over one-hundred samples. Our team was able to guarantee two-thirds of the core requirements of the SocialBit as described in section 2.0 as completed.
Filipe’s risk reduction was to design a PCB file of the prototype SocialBit system. The PCB is shown in Figure 2 below. It consists of 4 separate routing layers, and its length and width are 39.00mm by 34.52mm respectively. Filipe decided that designing the PCB would be a major milestone towards the completion of the SocialBit as it would allow all of the circuits required for the SocialBit system to be implemented into a very small form factor. The dimensions of the board are small enough to fit the criteria of our SocialBit such that it must be a wearable device. Virtually, we performed testing of the board by having computer-assisted drawing software analyze the PCB for unrouted connections and overlapping wires. Once the software confirmed that no unrouted connections or overlapping wires existed, we were able to say that our board was functional. By having the PCB designed with a small operating area, our team is able to create a prototype of the SocialBit device that will be able to fit into a wearable device, which is one of our design requirements described above in section 3.1. In addition, our team will be capable of designing a full casing for the board with the previously described 3D-printed casing to create an aesthetically pleasing design for the wearer of the SocialBit. 

Figure 2. SocialBit Prototype PCB
Miguel’s risk reduction was to create the STL file as shown in Figure 3 and to 3D print the encasing that would hold our prototype. Here, we created the STL file with SolidWorks and based the structure similar to an Apple Watch casing. We did this because we wanted our casing to match common smartwatches on the market. Our design was a rectangular box where there was one opening on the side to allow for us to upload code to the Ambiq Micro development board. We tested our casing by checking if the Ambiq Micro development board fit within it, which it did. Once we create our PCB, we will change the STL file to encase a smaller structure that will still be in the shape of our choosing. This will be our final STL design. Again we will confirm by ensuring the PCB can fit within the casing.

Figure 3 STL Case Structure for Ambiq Micro Development Board
Michael’s risk reduction was to build upon the team risk reduction for hardware by being able to send processed audio results to the Android application. We completed this goal by setting up a web server API that accepted HTTP requests such as POST and GET. We sent the results of the data to the web app using POST commands which allowed the application to collect the information using GET commands. We tested if our system worked by setting up a display that would list the results on a website to see if we were posting from the microcontroller. We visually confirmed that our website was being updated with the results by slowing down the rate of posts to five seconds. We used this testing method over forty times to determine that our risk reduction activity was successful. Out of the forty tests, we were able to get twenty-two successful and twenty of them occurred in a row to complete our testing. With this risk reduction, we were able to fulfill all the requirements of the SocialBit as described in section 2.0. However, for our final design, we will move to Bluetooth to send results because it is more secure. Bluetooth works within close proximity between devices (our watch and a user’s phone) and keeps the user’s data private since it will not be on display or stored on a website.

3.2.2 Software Risk Reductions
The software team’s risk reduction was to create a basic Android application with 3 pages that display placeholder text. This risk reduction was done to provide a basis for the software team to build on as more components got added to the application. We developed the application on Android Studio and tested it by debugging on both the built-in emulator and our own Android devices.
Mircea’s risk reduction was to successfully receive data from the device and display it on the app. He made a separate activity in the Android app where he successfully sent the GET request to the web server API. This returned a simple JSON string that was then displayed on the app. This was done twenty times to make sure that it was bug free. For now, this serves as the only form of communication between hardware and software. This risk reduction activity ensured that we are capable of communicating in some form between the device and the app.
Rebecca’s risk reduction was to improve the UI of the Android application from the basic one created in the software team’s risk reduction, as seen in Figure 4. She added a tabular interface, so users can easily navigate between the different features they want more information about. She also added an area graph and a bar graph to display randomly generated data to represent the number of social interactions in a day and in a week. To make the UI more intuitive and easy to gain information at a glance, she also added in different colors to represent how much social interaction was had within that day. This risk reduction will provide a foundation for future real-time display of data from the hardware.

Figure 4. SocialBit Application UI

3.2.3 Machine Learning Risk Reductions
The machine learning team’s risk reduction activity was to show basic training capability using a known dataset and platform. We used 9 different audio files, each about five minutes long, and segmented them into 5 second intervals and labelled each segment as speech, noise, or music. Using a Python notebook, we extracted some basic features from our labelled audio using LibROSA and used an XGBoost classification algorithm to determine if audio could be labelled as speech, noise, or music. With this basic initial model, we were able to classify training audio with roughly 91% accuracy, though this high score was due partially to some overfitting as a result of our small dataset.
Alexander’s individual risk reduction activity was to expand both the training dataset and the amount of features we use to train the model. The expanded dataset will help prevent overfitting, allowing us to more accurately classify real-world audio.  To expand the training dataset, we used the Freesound audio dataset, which contains 19,000 labelled audio files with lengths between 15 and 30 seconds. These files were labelled using Google’s AudioSet Ontology, a set of 80 labels for audio files. By converting their large variety of labels to match our labels of speech, noise, and music, we can use this more diverse dataset to train our model. To expand the features, we now extract the first 13 Mel Frequency Cepstral Coefficients (MFCC) coefficients, as these are commonly used in machine learning to identify properties of human speech in audio. Using this expanded dataset and new features, we are able to classify audio from our dataset with about 82% accuracy, which while lower than before, is expected considering the major differences between our current and initial dataset.
Errol’s risk reduction was to implement the audio classification model on our Raspberry Pi. This involved installing both LibROSA and XGBoost on the pi, ensuring that the pi captured and formatted audio correctly, and developing a system to save and later load models created in our Python notebook. The implementation involved writing a Python script that loads the specified model. Once the model is loaded, the script connects to the audio capture device on the pi, and continuously record 5 seconds of audio and then extract features from the audio using LibROSA. The Python script then passes the features into the classifier, and outputs results that can be communicated to the application. This risk reduction showed that we were able to fully perform our model analysis on a platform other than our Python notebook with real inputs. 

3.3 Test Plan
The following sections describe the new activities that will be taking place over the Spring semester to ensure that the design selections for our SocialBit system will be successful in the requirements we have set forth above. Under the hardware test plan, we will test 3 parameters for the Ambiq Micro, we will test pins on our PCB, and we will run durability and resistance testing for our casing. Under the software test, we will test the communication with the hardware through Bluetooth and test the results display. Lastly, under machine learning, we will test the machine learning models on a Python notebook and on the Ambiq Micro.

3.3.1 Hardware Test Plan
For the hardware test plan, the team will focus on the Ambiq Micro, our designed PCB, and our 3D-printed casing. For the Ambiq Micro, our team will test its functionality under different noise settings (low, medium, and high) and then measure the classification accuracy and power consumption of the system. For each setting, we are aiming for the accuracy of our classifiers to be above 80% and for the power consumption of the system to be under 1.4 Wh. We selected these numbers based off of the specifications in sections 2.1.1 and 2.1.3. To test the PCB, our team will confirm our design by ensuring we have no errors related to unrouted connections or overlapping wires. We will then physically check the board by testing the different pins to ensure we have made the proper connections to each component. For the 3D-printed casing, our team will test the durability of the casing by repeatedly dropping it and identifying any scratches, chips, or marks. With the damage documented, our team will be able to assess which parts of the casing are most susceptible to damage and redesign the casing as necessary. Our final test to check our overall hardware system will be to compare it against the development board. Here, the development board include all proper connections, and runs with a constant power supply. When we compare the two systems, we are looking to see if our system can output the same results as the developmental board, and we will only be able to say we are successful when we can output the same result from both devices with 95% accuracy.

3.3.2 Software Test Plan 
The testing of software components will focus on two main areas: communicating with the hardware through Bluetooth and displaying real-time social interaction analysis from the audio processing. The communication with the hardware through Bluetooth will be tested with different types of information. We will send both properly and improperly formatted data to ensure the application is robust enough to handle anything the hardware sends. We will also test sending data from various distances to see how far apart the hardware and Android phone can be while still maintaining Bluetooth connection. Lastly, we will also test that in the case of lost Bluetooth connection during data transfer, we will still be able to access any of the information that was being sent.
The other phase of testing is displaying real-time social interaction data on the application. This phase will be broken down into testing with dummy data and testing with real data. We will first periodically generate random data and send it to the application. We want to ensure that we can update the UI to display new data whenever it is received. After we ensure we can display consistent data, we will start testing with data from the hardware, which may not be as consistent due to factors such as the hardware losing connection with the application or the hardware being turned off to not record any more audio.

 3.3.3 Machine Learning Test Plan 
Our machine learning models will be tested in two different environments. Firstly, we will perform testing in a Python notebook. Here we test the accuracy of our models on a portion of the dataset that was not used to train the model. We do this to ensure that our accuracy is not due to overfitting on the training data and that our model will sufficiently be able to classify audio outside of our dataset. Our second testing environment will be on the development board. We will use the Ambiq Micro to record short audio segments and perform feature extraction on those segments. We will then test if the feature measurements extracted from these segments are comparable to those used to train the classifiers in the notebook environment. Furthermore, we will input the feature measurements into our models and test their accuracy. This second method of testing presents some challenges as the microphone quality on the board can introduce noise into our feature measurements. Most noticeably, the full-band and low-band energy calculations on the board are much different from the calculations in the Python notebook. Ultimately, we can likely account for this problem by normalizing the data in such a way that the feature calculations are similar both on and off the board.

4.0 PROJECT MANAGEMENT
Under project management, we list out the project activities we need to complete our project.  The goal of doing this is to make a plan that we can follow next semester to get our SocialBit developed and working as quickly as possible. It helps us look at what tasks we have to achieve, who has to complete these tasks, the amount of time we spend on these tasks, and the potential costs of our project. We have twelve tasks to complete within our project and we define them across the hardware, software, and machine learning teams. We then go on within section 4.2 to describe the task assignments for each task in terms of who will be responsible for the task, and who will assist in completing those tasks. Then within section 4.3, we describe the project schedule we have in place for ten key tasks, and how we plan on moving from task to task. We list four phases and each phase builds upon the previous phase. Lastly, within section 4.4, we describe the project budget by listing what we have paid for, and items we plan on paying for in the Spring. We also go on to say that we are within our project budget and expected to stay under costs.

4.1 Project Activities
For the coming semester, we have identified our next steps in our work breakdown structure in Appendix B. Each team will be responsible for various tasks that must be completed before our SocialBit is finalized. The hardware team will need to build the PCB and the prototype device, then improve the power efficiency and prototype appearance if necessary. The hardware team will also need to work with the software team to connect the device with the app via Bluetooth. The Software team will need to be able to display data on the app and improve the app UI and appearance in a way that compliments the method for displaying data. Finally, the machine learning team will need to improve our current model’s accuracy on-board and begin training additional models to perform speaker diarization and determine emotional information.

4.2 Task Assignments
We break down the tasks in the work breakdown structure based on three factors: the individual with the most knowledge on the task, the team the task relates to, and if it is a cross-functional task. 
Hardware tasks have been broken down as follows. Michael will take charge of sending data to the app via Bluetooth and building the prototype device. He has the most experience with device driver communications and he has built multiple embedded systems in the past. For sending data to the app via Bluetooth, he will be assisted by members from all teams because it is a cross-functional task. For building the prototype, he will be assisted by the entire hardware team since it is a large task that falls under hardware development. Filipe will take charge of building the PCB and optimizing power efficiency because he designed the schematics for the PCB and he has the most knowledge in power electronics. For the PCB, Miguel will assist him, and for power efficiency, the entire hardware team will assist him. Miguel will take charge of selecting hardware components and improving the prototype appearance. He has the most knowledge in building breadboards, and he is tasked with the watch casing design which a large portion of our prototype’s appearance. For both of his tasks, the hardware team will assist him as needed and for the prototype appearance Rebecca will confirm if the appearance is acceptable. 
The software team has split their tasks as such. Mircea will take charge of integrating Bluetooth with the app since he integrated the web server results to the app. He will be assisted by Rebecca, Errol, and Michael since it is a cross-functional task. Rebecca will take charge of displaying data on the app and improving the app UI because she has the most experience in designing web applications. For displaying data on the app, Mircea will assist her from the software team, and Alexander will check the final design. Lastly, for improving the app UI, Rebecca will be assisted by Mircea since it is primarily a software task. 
With respect to machine learning tasks, Alexander will take charge of improving the model accuracy on-board and extracting basic emotional information since he focused on finding the features and classifiers for the model. He will be assisted by Errol on all his tasks and Michael will assist with improving the on-board accuracy. Errol will take charge of determining the number of people in a conversation since he focused on finding the diarization of audio and he will be assisted by Alexander.

4.3 Project Schedule
From our Gantt chart, we have planned our project to include 10 major tasks to complete. We break down these 10 major tasks across four phases. We begin in the first phase by starting where we ended with our risk reductions. In this phase, we want to connect our android application via Bluetooth, build our PCB, and increase on-board model accuracy. Once we are able to achieve these three tasks, we can move on to the second phase where we will build our prototype device, display real-time data on the app, and determine the number of people in a conversation. We can move on to those tasks because the first phase tasks are smaller parts within the second phase. We can build our prototype once we have a PCB to build around, we can display real-time data on the application once we make a Bluetooth connection, and we can move towards determining the number of people in a conversation once we improve our model accuracy. Once we complete phase two, we can move towards phase three, where we would optimize for power efficiency and extract basic emotional intelligence. Here, we can test our prototype device for power consumption and we can extract more information from the data we receive. Lastly, in phase four, we would focus on optimizing the prototype appearance, and move closer towards real-time analysis. The goal in the fourth phase, is that we are cleaning up our prototype, so that we can create a version of our device that we can showcase.  The overall goal of our schedule is to build from the ground up until we complete our project. Furthermore, we can break down the chart into four phases where each will take approximately three weeks. 


4.4 Project Budget
The bill of materials in Appendix E summarizes materials utilized for the development of the SocialBit. It includes quantity, item price and description for each purchased component of our device. We included the microcontrollers we have tested on and the microcontrollers we expect to test on such as the Raspberry Pi W Zero, the Raspberry Pi W, and the Sparkfun Edge Development Board. We plan on using these development boards to determine if we can use their specific chips for our prototype before we go on and create our PCB. We also included costs for extension parts to the Apollo 3 board, so that we could run the device. We included the 3D printed material casing used for our casing, even though it was free. Lastly, we have included the PCB even though we have not received a final cost for this item. We have not ordered our PCB and we cannot be certain as to the cost yet. The total costs we have spent on our system to-date is $90.83 which is manageable for our project at this point. The end goal of our project is not to exceed the industry budget of $1000 even though we have an honors project, and we do believe we will stay within budget.
 
5.0 CONCLUSION
In this report we detailed how we plan to design the SocialBit to accurately quantify social interactions and the steps we will take to fully realize the device by the end of Spring. We discussed how we split the design into three subsystems; one for hardware, another for software, and the final for machine learning. For each subsystem, we detailed the requirements our design must meet for success, our current design of the subsystem, the design work completed this semester, the design work that needs to be completed next semester, and the methods we will use to test whether the subsystem meets the requirements. We also communicate how we will breakdown project work for the upcoming semester using a work breakdown structure, linear breakdown chart, and Gantt chart. 
The hardware team is responsible for building the wearable device that will capture and process audio. The final design of their subsystem must be fast, power efficient, and resemble an Apple Watch. The current design utilizes an Ambiq Micro with several MEMS microphones and transmits data to the user through a Bluetooth module. Currently, the hardware team has completed work in implementing the audio capture and data communication functions on a Raspberry Pi, and created a PCB and 3D-printed casing design for the SocialBit device. Next semester, the hardware team will work to implement the audio capture and data communication features on the Ambiq Micro development board, selecting the hardware components that will be used in our PCB, and optimize our 3D-printed case structure to mitigate potential damage. They will test that their design is complete by ensuring that the prototype SocialBit device is capable of performing the audio sampling and analysis features we want within a certain operation time and power consumption. 
The software team is responsible for developing the application that will connect to the device and display the results. The requirements guiding the design of the application are that it must communicate with the hardware device via Bluetooth and be easy to navigate. The application is currently designed as three pages that display randomly generated data that will later be replaced with real data received from the hardware. The software team has completed a basic application that can communicate with the hardware through web API calls. In Spring, the software team will focus on integrating Bluetooth communication and displaying the data in real-time. To ensure that the final design is complete, the software team will send data and analysis from the hardware to the device and ensure the correct information is displayed on the device.
The machine learning team is responsible for the development of classifiers that will be able to extract information from the audio captured by the device. The model designs are constrained by the features extracted from the audio and the model accuracy. The classifier responsible for discriminating between noise, speech, and music is currently designed as a random forests classifier trained using extreme gradient boosting with the Freesound audio dataset. The team has successfully trained a model capable of performing audio classification with 81% validation accuracy in our notebook environment. The team has also interfaced the model with a Raspberry Pi, though the accuracy will need to be improved. In the upcoming semester the team will continue to improve the accuracy of the model responsible for audio classification as well as develop a new model responsible for determining the number of speakers in a given audio segment. The machine learning team will test whether our model designs satisfy the project requirements by monitoring the accuracy of our models in our notebook environment and also on our developmental boards.
Finally, we elaborate on how we will manage the project and what the work breakdown will look like in the future. We list all of the tasks that need to be completed next semester in the work breakdown structure located in Appendix B. We then assign those tasks to the appropriate team member in our linear responsibility chart found in Appendix C. We provide a timeline for when those tasks should be completed in our Gantt chart located in Appendix D. We also provide a bill of materials in Appendix E to showcase the materials we have used so far as well as the overall cost of our project at this point. 











REFERENCES
[1]    Apple Watch Battery, Apple Inc., Cupertino, CA, 2019 [Online]. Available: https://www.apple.com/watch/battery/
[2]    Apple Product Information Sheet, Apple Inc., Cupertino, CA, Nov. 2019, pp. 5-8 [Online]. Available: https://www.apple.com/legal/more-resources/docs/apple-product-information-sheet.pdf
[3]    Apple Watch Series 4 - Technical Specifications, Apple Inc., Cupertino, CA, Sept. 2019 [Online]. Available: https://support.apple.com/kb/SP778?locale=en_US
[4] 	A. Benyassine, E. Shlomot, and H. Y. Su, “ITU-T Recommendation G.729 Annex B: a silence compression scheme for use with G.729 optimized for V.70 digital simultaneous voice and data applications,” in IEEE Communications Magazine, vol. 35, no. 9, pp 64-73, September 1997.doi: 10.1109/35.620527 URL: https://ieeexplore.ieee.org/document/620527 (Source is cited in 3.1.3)
[5]	A. Zhang, Q. Wang, Z. Zhu, J. Paisley and C. Wang, "Fully Supervised Speaker Diarization," ICASSP 2019 - 2019 IEEE International Conference on Acoustics, Speech and Signal Processing (ICASSP), Brighton, United Kingdom, 2019, pp. 6301-6305, URL: https://ieeexplore.ieee.org/document/8683892
[6]	“Freesound General-Purpose Audio Tagging Challenge.” Kaggle, https://www.kaggle.com/c/freesound-audio-tagging/data.
[7]	Przybocki, Mark, and Alvin Martin. 2000 NIST Speaker Recognition Evaluation LDC2001S97. Web Download. Philadelphia: Linguistic Data Consortium, 2001.
[8]    Lindbloom, J. (2019). SparkFun Edge Development Board - Apollo3 Blue - DEV-15170 - SparkFun Electronics. [online] Sparkfun.com. Available at: https://www.sparkfun.com/products/15170 [Accessed 8 Nov. 2019].
[9]   	Time Cycle Audio Recording Device, by M. Sarow, T. Humphrey. (2014, Jan., 23). WO 2014/015031 Al. Accessed on: Nov. 1, 2019 [Online]. Available: https://patentimages.storage.googleapis.com/34/b3/b6/2024d0170fbcb0/WO2014015031A1.pdf
[10]  S. Chuah et al, “Wearable technologies: The role of usefulness and visibility in smartwatch adoption,” Elsevier, Computers in Human Behavior. Vol. 65, pp.276-284, DEC. 2016 [Online]: doi: https://doi.org/10.1016/j.chb.2016.07.047
[11]   LII / Legal Information Institute. (2017). 47 CFR § 15.19 - Labeling requirements.. [online] Available at: https://www.law.cornell.edu/cfr/text/47/15.19 [Accessed 4 Oct. 2019]
[12]  LII / Legal Information Institute. (2000). 47 U.S. Code § 302a - Devices which interfere with radio reception. [online] Available at: https://www.law.cornell.edu/uscode/text/47/302a [Accessed 4 Oct. 2019].
[13]  Bluetooth.org. (2019). Bluetooth Core Specifications. [online] Available at: https://www.bluetooth.org/docman/handlers/downloaddoc.ashx?doc_id=457080 [Accessed 4 Oct. 2019]

APPENDIX A – APPLICABLE STANDARDS

Complying with the Electronic Code of Federal Regulations and the Federal Communications Commission, our SocialBit device shall comply with the regulations set forth by docket § 15.19 Labeling requirements [11]:

“This device complies with part 15 of the FCC Rules. Operation is subject to the following two conditions: (1) This device may not cause harmful interference, and (2) this device must accept any interference received, including interference that may cause undesired operation.”

In addition, our SocialBit device shall also comply with 47 U.S. Code § 302a.Devices which interfere with radio reception, which states that our device shall follow “minimum performance standards which will reduce their susceptibility to interference from radio frequency energy” [12].

Since our device shall communicate with other devices through the use of Bluetooth, we shall ensure to follow the core protocols set forth  by Bluetooth to ensure secure data communication [13]. 




















APPENDIX B - WORK BREAKDOWN STRUCTURE

Table 1. Work Breakdown Structure of SocialBit














APPENDIX C - LINEAR RESPONSIBILITY CHART

Table 2. Linear Responsibility Chart of SocialBit
Linear Responsibility Chart
Rebecca
Mircea
Alexander
Errol
Michael
Miguel
Filipe
Send data to app via Bluetooth


2


2
1
2


Build PCB










2
1
Build prototype device








1
2
2
Select hardware components








2
1
2
Optimize power efficiency








2
2
1
Improve prototype appearance
3






2
1
2
Integrate Bluetooth with app
2
1


2
2






Display data on app
1
2
3








Improve app UI
1
2










Improve model accuracy on-board




1
2
2




Determine number of people in conversation




2
1






Extract basic emotional information




1
2






Key:














1 - Primary














2 - Support














3 - Review/Final Approval 
















APPENDIX D - GANTT CHART

Table 3. Project Schedule of SocialBit



APPENDIX E  – BILL OF MATERIALS
Table 4. Bill of Materials for SocialBit


Qty.
Item
Description
Date Ordered
Price


1
Raspberry Pi W Zero
Development board with Bluetooth/Wi-fi chips.
October 29, 2019
$19.20


1
Raspberry Pi W Zero
Development board with Bluetooth/Wi-fi chips. Comes with a case, 32 SD card, and cables.
October 16, 2019
$43.78


1
SparkFun Edge Development Board - Apollo3 Blue
Development board with Bluetooth.Wi-fi chip and TensorFlow.
October 30, 2019
$14.95


1
SparkFun Apollo 3 - USB Board Extension
Board-to-board USB UART connection.
November 2, 2019
$8.95


1
SparkFun Apollo 3 - USB A to C Cord
Connection from computer to board.
November 6, 2019
$3.95


N/A
3D Printing material
Case structure for our prototype board.
N/A
FREE


1
PCB
Smaller adaptation of Ambiq Micro Apollo3 Blue board for prototype.
N/A
N/A
Totals:
6






$90.83



