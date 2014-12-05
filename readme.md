# Arduino library to controll 4 VNH3SP30 Motor Drivers

This is a school project an currently under construction!

Version: 0.1

Original Project from:
[www.pololu.com](http://www.pololu.com/)

## Summary

This is a library for the Arduino that interfaces with the VNH3SP30 H-Bridge Motor Driver from ST. It makes it simple to drive four brushed, DC motors.

## Getting Started

### Software

Download the archive from [GitHub](http://github.com/v0tti/Quad-VNH3SP30-Motor-Driver), decompress it, and move the "QuadVNH3SP30MotorDriver" folder into the "libraries" subdirectory inside your Arduino sketchbook directory. You can view your sketchbook location by selecting File->Preferences in the Arduino environment; if there is not already a "libraries" folder in that location, you should create it yourself. After installing the library, restart the Arduino environment so it can find the QuadVNH3SP30MotorDriver library.

### Hardware

You can get a Board with four VNH3SP30 Motor Drivers from [ELMOD](http://elmod.eu), just ask the support.
The Dual VNH5019 Motor Driver Shield from the original Project can be purchased on [Pololu's website](http://www.pololu.com/catalog/product/2507). See the [motor shield user's guide](http://www.pololu.com/docs/0J49) for more details.

## Library Reference


- ```QuadVNH3SP30MotorDriver(int A1, int B1, int PWM1, int A2, int B2, int PWM2,int A3, int B3, int PWM3, int A4, int B4, int PWM4)```Default constructor, the pins for each motor are assigned here.

- ```void init()```Initialize pinModes and timer1.

- ```void setMotorSpeed(int pwm, int analogPin1, int analogPin2, int speed)```Set speed and direction for any motor. Speed should be between -255 and 255. 255 corresponds to motor current flowing from M1A to M1B. -255 corresponds to motor current flowing from M1B to M1A.  0 corresponds to full coast.
- ```void setSpeeds(int m1Speed, int m2Speed, int m3Speed, int m4Speed)``` Set speed and direction for motor 1, 2, 3 and 4. 

- ```void setMotorBrake(int pwm, int analogPin1, int analogPin2, int brake)```Set brake for any motor. Brake should be between 0 and 255. 0 corresponds to full coast, and 255 corresponds to full brake.
- ```void setBrakes(int m1Brake, int m2Brake, int m3Brake, int m4Brake)```Set brake for motor 1, 2, 3 and 4.

## Version History

From Polulu Project:

- 1.2.3 (2014-03-24): Added 20 kHz PWM support for ATmega32U4. Thanks blacksound.
- 1.2.2 (2014-03-18): Add keywords.txt file. Thanks eatonphil.
- 1.2.1 (2013-01-06): Fixed a bug in setM2Speed that was introduced in 1.2.0.
- 1.2.0 (2012-12-26): Changes the behavior of the library at speed 0 so that it makes the motor coast regardless of which direction the motor is spinning.
- 1.1.0 (2011-12-15): Arduino 1.0 compatibility.
- 1.0.1 (2011-11-07): Adds support for Arduinos not based on ATmega168/328.
- 1.0.0 (2011-10-28): Original release.