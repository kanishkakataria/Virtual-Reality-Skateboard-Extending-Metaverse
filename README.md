# Virtual-Reality-Skateboard-Extending-Metaverse
Implementing a virtual reality skateboard which would be further expanded into the metaverse, a cyberspace where multiple people can come together virtually and interact virtually.The motive behind the project was to let people experience certain activities which are hard to realize in the physical world. The project consists of 2 parts, hardware and software. Hardware consists of a skateboard, arduino, VR headset, Jumper wires,Mini breadboard, An HC-06 bluetooth module, An MPU-6050 accelerometer/gyro and A 9V battery with battery box that has a on/off switch and a barrel plug (to power the Arduino board). Software is a mobile app which is developed using the Unreal Engine, on which different terrains are built that can be selected by the user. The software and hardware will be connected using the plugins which are available in Unreal. 
![system archi](https://user-images.githubusercontent.com/85161519/201523031-e436443b-43cd-41de-965d-dfae9e390d18.png)"
![dataflow](https://user-images.githubusercontent.com/85161519/201523660-cb69d4af-1ca6-4809-9458-866fb9cc133a.png)
<br>Use Case Diagram<br>
MATERIALS AND METHODS<br>
In this paper, we designed a prototype of metaverse implementation of a virtual reality skateboard. It is a single player game, where the player will be standing on the skateboard, which has an arduino connected to it capturing all the player movements, and will be wearing a VR headset, which will show the terrain on which the player is playing.<br>
1) The terrain built using the Unreal Engine gives the virtual reality experience of riding a skateboard. This is created using the assets and props provided by the Engine. By simple drag, drop and resize the virtual world for the player to ride the skateboard is created. The collision option allows the props to become opaque so that the player does not go through it.<br>
2)The character with the game is created by downloading the required FBX file, which contains the character mesh, and the animation mesh required is also downloaded as the FBX file. These files are loaded to the Engine, the character axes are adjusted to the terrain mesh, speed and movements are adjusted and finally the character can move according to the player's movements.<br>
3)The frontend is exported as an APK file to be loaded into the Android platform and using the VR headset the player is able to ride the skateboard virtually.
4)The hardware consists of an Arduino with an accelerometer and bluetooth module connected to it. All these components are connected to the skateboard. The bluetooth module is used to connect it to the mobile phone connected to the VR. The accelerometer is used to detect the motion of the player and the Arduino, a microcontroller controls the bluetooth module and the accelerometer.<br>
5)The entire implementation is divided into two parts, one is the hardware part and the other is the frontend part. The hardware part captures all the players movement and is connected to the frontend part.<br>
6)The hardware and frontend part will be connected using the plugins available in Unreal Engine<br>
Hardware requirements<br>
1)Arduino UNO:It is an ATmega328P-based microcontroller board with 6 PWM outputs, 14 digital input/output pins, 6 analogue inputs, a 16 MHz ceramic resonator, a USB port, a power jack, an ICSP header, and a reset button. It already has everything needed to support the microcontroller, so all that is required to get it going is a USB connection to a computer, AC-to-DC power converter, or battery.<br>
2)HC06 Bluetooth module: For transparent wireless serial communication, the HC-06 is a class two slave Bluetooth module. The user can operate it with complete transparency once it has been associated with a master Bluetooth device, such as a computer, smartphone, or tablet. All information received via the serial input is immediately broadcast over the radio.<br>
3)MPU6050 - Triple Axis Gyro Accelerometer Module: The MPU6050 module makes use of the well-liked MPU6050 Sensor, which combines a three-axis gyroscope and an accelerometer into a single unit. A sensor and microcontroller can easily and directly communicate with one another thanks to an I2C connection.<br>
VR headset: Virtual reality headsets allow users to experience information in a 360-degree environment that allows them to turn and gaze about just like they would in the real world. This replaces the player's natural environment.<br>
4)Skateboard: The skateboard has IOT technology installed on it, which will provide a virtual reality experience of the metaverse.<br>
Software Requirements<br>
1) Unreal Engine<br>
2) Visual Studio<br>
3) Android

