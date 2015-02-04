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


- ```QuadVNH3SP30MotorDriver(unsigned char A1, unsigned char B1, unsigned char PWM1, unsigned char A2, unsigned char B2, unsigned char PWM2,unsigned char A3, unsigned char B3, unsigned char PWM3, unsigned char A4, unsigned char B4, unsigned char PWM4)```Default constructor, the pins for each motor are assigned here.

- ```void init()```Initialize pinModes.

- ```void setMotorSpeed(int pwm, int digitalPin1, int digitalPin2, int speed)```Set speed and direction for any motor. Speed should be between -255 and 255. 255 corresponds to motor current flowing from M1A to M1B. -255 corresponds to motor current flowing from M1B to M1A.  0 corresponds to full coast.
- ```void setPinSpeed(int pwm, int digitalPin1, int digitalPin2, int speed);```
- ```void setSpeeds(int m1Speed, int m2Speed, int m3Speed, int m4Speed)``` Set speed and direction for motor 1, 2, 3 and 4. 

- ```void setMotorBrake(int pwm, int digitalPin1, int digitalPin2, bool hardstop)```Set brake for any motor. speed is set to 0
- ```void setPinBrake(int pwm, int digitalPin1, int digitalPin2, bool hardstop);```
- ```void setBrakes(bool hardstop)```Set brake for motor 1, 2, 3 and 4.

## Version History

From Polulu Project:

- 1.2.3 (2014-03-24): Added 20 kHz PWM support for ATmega32U4. Thanks blacksound.
- 1.2.2 (2014-03-18): Add keywords.txt file. Thanks eatonphil.
- 1.2.1 (2013-01-06): Fixed a bug in setM2Speed that was introduced in 1.2.0.
- 1.2.0 (2012-12-26): Changes the behavior of the library at speed 0 so that it makes the motor coast regardless of which direction the motor is spinning.
- 1.1.0 (2011-12-15): Arduino 1.0 compatibility.
- 1.0.1 (2011-11-07): Adds support for Arduinos not based on ATmega168/328.
- 1.0.0 (2011-10-28): Original release.