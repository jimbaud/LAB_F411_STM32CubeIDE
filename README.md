# LAB_F411_STM32CubeIDE
![Vue 3D NUCLEO](./Images/Logo_repository.bmp) 

# Français : 

#### Description :
Ce dépôt GitHub contient une série d'exemples de code sous STM32CubeIDE et HAL destinée aux projets pratiques du cours sur le microcontrôleur STM32F411. Chaque fichier compressé correspond à un projet spécifique qui exploite des fonctionnalités particulières du microcontrôleur et vise à démontrer son utilisation dans divers scénarios.

<details>

<summary>Comment importer les projets dans STM32CubeIDE</summary>

Dans GitHub, les projets ne contiennent pas les fichiers de définition du projet. La première étape est de télécharger les fichiers sur GitHub. Pour cela, allez sur le bouton "Code" puis dans la liste déroulante, choisissez "Download ZIP".

![Vue Github](./Images/GitHub.jpg) 

Copiez ensuite le ou les répertoires dans votre répertoire de Workspace.

![Vue Step1](./Images/Step1.jpg)   

Cliquez dans le menu "File" sur "Import", puis dans la fenêtre, déroulez le répertoire "General" et sélectionnez "Import an Existing STM32CubeMX Configuration File (.ioc)". Une nouvelle fenêtre s’ouvre, cliquez sur le bouton "Browse" puis sélectionnez dans l’explorateur le fichier .ioc du projet (ici F411_LED.ioc).

![Vue Step2](./Images/Step2.jpg)        
 
Une fois cette étape réalisée, le fichier sélectionné apparaît dans la fenêtre. Ensuite, il faut cliquer sur le bouton "Finish". Si le projet a été réalisé avec une version ultérieure de drivers ou de CubeMX, il vous sera proposé de migrer vers la dernière version. Cliquez sur "Migrate" pour accepter.

![Vue Step3](./Images/Step3.jpg)       

Le projet est maintenant correctement importé. Vous pouvez générer le code (Alt + K) et compiler le projet (Ctrl + B).

![Vue Step4](./Images/Step4.jpg) 

</details>

<details>
<summary>Liste des fichiers :</summary>

* F411_ADC : Fournit un exemple de code illustrant l'utilisation du convertisseur analogique-numérique (CAN) du microcontrôleur STM32F411. Ce projet montre comment réaliser des mesures analogiques converties en données numériques.

* F411_ADC_multi : Fournit un exemple de code démontrant l'utilisation de plusieurs canaux du convertisseur analogique-numérique (CAN) du microcontrôleur STM32F411. Ce projet montre comment configurer et lire les valeurs analogiques de plusieurs entrées (IN0, IN1 et IN4) puis les convertir en données numériques, qui sont affichées en temps réel sur le terminal via UART.

* F411_BLE : Contient un exemple qui exploite la fonctionnalité Bluetooth Low Energy (BLE) du STM32F411. Il démontre la mise en œuvre de la communication sans fil à faible consommation d'énergie.

* F411_I2C_LCD : Présente un projet pratique pour contrôler un écran LCD via le protocole I2C. Il montre comment utiliser le microcontrôleur pour piloter un écran de cette manière.

* F411_LED : Un exemple simple de contrôle d'une LED à l'aide du microcontrôleur STM32F411. Il vise à illustrer les bases du contrôle des sorties GPIO pour allumer et éteindre une LED.

* F411_LED_debug : Propose un projet simple pour comprendre l'utilisation du débogage dans le contexte de l'allumage d'une LED. Il offre un exemple pratique pour les étudiants en ingénierie sur la façon d'utiliser le débogage pour vérifier le comportement de la LED.

* F411_LM35 : Contient un exemple mettant en œuvre un capteur de température LM35 avec le microcontrôleur. Ce projet vise à mesurer et à interpréter les données de température provenant de ce capteur.

* F411_PID : Présente un exemple implémentant un contrôleur PID (Proportionnel, Intégral, Dérivé). Ce fichier vise à illustrer la régulation de systèmes dynamiques par un contrôleur PID.

* F411_PID_APPLI_2 : Suite de l'application PID, partie plus avancée pour la mise en œuvre du contrôleur PID.

* F411_PID_APPLI_3 : Continuation de l'application PID, troisième partie du projet pour le contrôleur PID.

* F411_PWM : Contient un exemple de code démontrant la modulation de largeur d'impulsion (PWM). Le projet illustre comment générer des signaux PWM à l'aide du microcontrôleur STM32F411.

* F411_PWM2 : Suite de l'exemple précédent pour la modulation de largeur d'impulsion. Propose des fonctionnalités avancées ou des applications supplémentaires concernant le PWM.

* F411_Push_Button : Un projet pratique pour manipuler un bouton poussoir à l'aide du microcontrôleur STM32F411. L'exemple montre comment réagir à l'état du bouton pour contrôler une LED, par exemple.

* F411_Push_Button_IT : Variation du projet précédent, mais cette fois, la détection d'appui sur le bouton est effectuée via des interruptions matérielles (External Interrupt).

* F411_RTC : Contient un exemple illustrant la configuration et l'utilisation de l'horloge temps réel (RTC) du microcontrôleur STM32F411. Montre comment configurer et exploiter les fonctionnalités de l'horloge RTC.

* F411_Rotary_Encoder : Présente un projet mettant en œuvre un encodeur rotatif avec le microcontrôleur STM32F411. Il détaille comment interpréter les signaux de l'encodeur rotatif pour différentes applications.

* F411_SPI_7735_Screen : Contient un exemple montrant l'utilisation d'un écran 7735 via le protocole de communication SPI. Le projet met en évidence la configuration et le contrôle de l'écran 7735 à l'aide du microcontrôleur.

* F411_SampleApp_BLE : Propose un exemple d'application utilisant la connectivité Bluetooth Low Energy (BLE) du microcontrôleur STM32F411. Il offre un exemple d'application BLE simple et détaillée pour l'ingénierie logicielle.

* F411_Sensor_Demo_BLE : Suite de l'exemple précédent, fournissant une démonstration d'application liée à un capteur via la communication BLE.

* F411_TC74 : Contient un exemple mettant en œuvre le capteur de température TC74 avec le microcontrôleur. Montre comment collecter et traiter les données de température via ce capteur spécifique.

* F411_Timer : Démontre l'utilisation des fonctionnalités de minuterie du microcontrôleur. Il explique comment configurer et exploiter les minuteries internes pour différentes applications.

* F411_UART : Contient un exemple pour établir une communication UART (Universal Asynchronous Receiver Transmitter) avec le microcontrôleur STM32F411. Cet exemple couvre l'envoi et la réception de données via l'UART.

* F411_UART_BLE : Extension de l'exemple précédent, mais cette fois, en intégrant la communication UART avec Bluetooth Low Energy.

* F411_UART_HMI : Propose un exemple d'interaction avec une interface homme-machine (HMI) via la communication UART.

* F411_UART_IT : Contient un exemple montrant la gestion des interruptions pour la communication UART du microcontrôleur.

* F411_UART_Update_BLE : Exemple mettant en œuvre la mise à jour du micrologiciel (firmware) via la communication UART et Bluetooth Low Energy.

* F411_UART_read : Propose un exemple illustrant la lecture de données via la communication UART.

* F411_UART_write : Détaille un exemple décrivant l'écriture et l'envoi de données via la communication UART.

Chacun de ces répertoires contient des exemples de code, des projets STM32 CubeIDE, des configurations matérielles et logicielles spécifiques à chaque projet. Ces ressources sont conçues pour aider les étudiants à apprendre et à explorer les diverses fonctionnalités du microcontrôleur STM32F411 dans le cadre de leur formation.

</details>

# English: 

#### Description:
This GitHub repository contains a series of code examples in STM32CubeIDE and HAL for practical projects in the STM32F411 microcontroller course. Each compressed file corresponds to a specific project that exploits particular functionalities of the microcontroller and aims to demonstrate its use in various scenarios.

<details>
 
<summary>How to import projects into STM32CubeIDE:</summary>

In GitHub, projects do not contain project definition files. The first step is to download the files from GitHub. To do this, go to the "Code" button and choose "Download ZIP" from the dropdown list.

![GitHub View](./Images/GitHub.jpg) 

Then copy the directory/directories into your Workspace directory.

![Step 1 View](./Images/Step1.jpg)   

Click on the "File" menu, then "Import". In the window, expand the "General" directory and select "Import an Existing STM32CubeMX Configuration File (.ioc)". A new window will open, click the "Browse" button and select the .ioc file of the project from the explorer (here F411_LED.ioc).

![Step 2 View](./Images/Step2.jpg)        
 
Once this step is done, the selected file will appear in the window. Then, click on the "Finish" button. If the project was created with a later version of drivers or CubeMX, you will be prompted to migrate to the latest version. Click "Migrate" to accept.

![Step 3 View](./Images/Step3.jpg)       

The project is now properly imported. You can generate the code (Alt + K) and compile the project (Ctrl + B).

![Step 4 View](./Images/Step4.jpg)   

</details>

<details>
 
<summary>List of files:</summary>

* F411_ADC: Provides sample code illustrating the use of the STM32F411 microcontroller's analogue-to-digital converter (ADC). This project shows how to carry out analogue measurements converted into digital data.

* F411_ADC_multi: Provides sample code demonstrating the use of multiple channels of the STM32F411 microcontroller's analogue-to-digital converter (ADC). This project shows how to configure and read analogue values from multiple inputs (IN0, IN1, and IN4), then convert them into digital data, which is displayed in real time on the terminal via UART.

* F411_BLE: Contains an example that exploits the Bluetooth Low Energy (BLE) functionality of the STM32F411. It demonstrates the implementation of low energy wireless communication.

* F411_I2C_LCD: Presents a practical project for controlling an LCD display via the I2C protocol. It shows how to use the microcontroller to drive a display in this way.

* F411_LED: A simple example of controlling an LED using the STM32F411 microcontroller. It aims to illustrate the basics of controlling GPIO outputs to turn an LED on and off.

* F411_LED_debug : Provides a simple project to understand the use of debugging in the context of turning on an LED. It provides a practical example for engineering students of how to use debugging to check LED behaviour.

* F411_LM35 : Contains an example implementing an LM35 temperature sensor with the microcontroller. The aim of this project is to measure and interpret temperature data from this sensor.

* F411_PID: Contains an example implementing a PID (Proportional, Integral, Derivative) controller. The purpose of this file is to illustrate the regulation of dynamic systems using a PID controller.

* F411_PID_APPLI_2p : Continuation of the PID application, more advanced part for the implementation of the PID controller.

* F411_PID_APPLI_3 : Continuation of the PID application, third part of the project for the PID controller.

* F411_PWM : Contains sample code demonstrating pulse width modulation (PWM). The project illustrates how to generate PWM signals using the STM32F411 microcontroller.

* F411_PWM2: Continuation of the previous example for pulse width modulation. Offers advanced functionalities or additional applications concerning PWM.

* F411_Push_Button : A practical project for manipulating a push button using the STM32F411 microcontroller. The example shows how to react to the state of the button to control an LED, for example.

* F411_Push_Button_IT: Variation on the previous project, but this time the button is detected using hardware interrupts (External Interrupt).

* F411_Push_Button_IT : Variation on the previous project, but this time the button press detection is carried out via hardware interrupts (External Interrupt).

* F411_RTC: Contains an example illustrating the configuration and use of the STM32F411 microcontroller's real-time clock (RTC). It shows how to configure and use the RTC functions.

* F411_Rotary_Encoder: Presents a project implementing a rotary encoder with the STM32F411 microcontroller. It details how to interpret the rotary encoder signals for different applications.

* F411_SPI_7735_Screen : Contains an example showing the use of a 7735 screen via the SPI communication protocol. The project highlights the configuration and control of the 7735 screen using the microcontroller.

* F411_SampleApp_BLE: Provides an example of an application using the Bluetooth Low Energy (BLE) connectivity of the STM32F411 microcontroller. It provides a simple and detailed BLE application example for software engineering.

* F411_Sensor_Demo_BLE : Continuation of the previous example, providing a demonstration of an application linked to a sensor via BLE communication.

* F411_TC74: Contains an example implementing the TC74 temperature sensor with the microcontroller. It shows how to collect and process temperature data via this specific sensor.

* F411_Timer: Demonstrates the use of the microcontroller's timer functions. It explains how to configure and use the internal timers for different applications.

* F411_UART : Contains an example of how to establish a UART (Universal Asynchronous Receiver Transmitter) communication with the STM32F411 microcontroller. This example covers the sending and receiving of data via the UART.

* F411_UART_BLE: Extension of the previous example, but this time integrating UART communication with Bluetooth Low Energy.

* F411_UART_HMI: Provides an example of interaction with a human-machine interface (HMI) via UART communication.

* F411_UART_IT: Contains an example showing interrupt management for the microcontroller's UART communication.

* F411_UART_Update_BLE: Example implementing firmware update via UART and Bluetooth Low Energy communication.

* F411_UART_read: Provides an example of reading data via UART communication.

* F411_UART_write: Details an example describing the writing and sending of data via UART communication.

Each of these directories contains code examples, STM32 CubeIDE projects, hardware and software configurations specific to each project. These resources are designed to help students learn and explore the various functionalities of the STM32F411 microcontroller as part of their training.

</details>
