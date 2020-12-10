# ESProject

This project is done as a fulfillment to the module Embedded Systems of my degree program BSc. (Hons.) in Information Technology. 
This project is about a basic concept 'Burglar Alarm System' using Passive Infrared Sensors and Arduino micro controller.

This repository contains the source code for the Arduino Uno board which is powered by ATMega 328P. The source code is written in C language. 
The system conains 3 Passive Infrared Sensors, a servo motor, a LED other than to the Arduino board. 
The PIR sensors are positioned in 3 directions.
The PIR sensors are connected to the digital pins 7,6 and 5.
LED is connected to the digital pin 2 and Servo motor is connected to the digital pin 0.

Once any of the PIR sensors gives feedback, the servo motor will turn the LED to that specific PIR sensor and LED will light up. 
