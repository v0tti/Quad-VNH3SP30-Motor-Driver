#include "QuadVNH3SP30MotorDriver.h"

// Constructors ////////////////////////////////////////////////////////////////

//QuadVNH3SP30MotorDriver::QuadVNH3SP30MotorDriver(unsigned char A1, unsigned char B1, unsigned char PWM1, unsigned char A2, unsigned char B2, unsigned char PWM2,unsigned char A3, unsigned char B3, unsigned char PWM3, unsigned char A4, unsigned char B4, unsigned char PWM4)
QuadVNH3SP30MotorDriver::QuadVNH3SP30MotorDriver(int A1, int B1, int PWM1, int A2, int B2, int PWM2,int A3, int B3, int PWM3, int A4, int B4, int PWM4)
{
    //Pin map
    _A1 = A1;
    _B1 = B1;
    _PWM1 = PWM1;
    _A2 = A2;
    _B2 = B2;
    _PWM2 = PWM2;
    _A3 = A3;
    _B3 = B3;
    _PWM3 = PWM3;
    _A4 = A4;
    _B4 = B4;
    _PWM4 = PWM4;
}

// Public Methods //////////////////////////////////////////////////////////////
void QuadVNH3SP30MotorDriver::init()
{
    // Define pinMode for the pins
    pinMode(_A1,OUTPUT);
    pinMode(_B1,OUTPUT);
    pinMode(_PWM1,OUTPUT);
    pinMode(_A2,OUTPUT);
    pinMode(_B2,OUTPUT);
    pinMode(_PWM2,OUTPUT);
    pinMode(_A3,OUTPUT);
    pinMode(_B3,OUTPUT);
    pinMode(_PWM3,OUTPUT);
    pinMode(_A4,OUTPUT);
    pinMode(_B4,OUTPUT);
    pinMode(_PWM4,OUTPUT);
}

/*
 * @param   motor       Select motor
 * @param   speed       Speed of motor
 *
 * Set speed for one motor, speed is a number betwenn -255 and 255
 */
void QuadVNH3SP30MotorDriver::setMotorSpeed(int motor, int speed)
{
    if (motor == 1)
        setPinSpeed(_PWM1, _A1, _B1, speed);
    if (motor == 2)
        setPinSpeed(_PWM2, _A2, _B2, speed);
    if (motor == 3)
        setPinSpeed(_PWM3, _A3, _B3, speed);
    if (motor == 4)
        setPinSpeed(_PWM4, _A4, _B4, speed);
}

/*
 * @param   pwm         Pulse-width modulation
 * @param   analogPin1  First analog pin
 * @param   analogPin2  Second analog pin
 * @param   speed       Speed of motor
 *
 * Set speed for any motor, speed is a number betwenn -255 and 255
 */
void QuadVNH3SP30MotorDriver::setPinSpeed(int pwm, int analogPin1, int analogPin2, int speed)
{
    unsigned char reverse = 0;
    
    if (speed < 0)
    {
        speed = -speed;  // Make speed a positive quantity
        reverse = 1;  // Preserve the direction
    }
    if (speed > 255)  // Max PWM dutycycle
        speed = 255;
    
    analogWrite(pwm, speed);
    
    if (speed == 0)
    {
        digitalWrite(analogPin1, LOW);   // Make the motor coast no
        digitalWrite(analogPin2, LOW);   // matter which direction it is spinning.
    }
    else if (reverse)
    {
        digitalWrite(analogPin1,LOW);
        digitalWrite(analogPin2,HIGH);
    }
    else
    {
        digitalWrite(analogPin1,HIGH);
        digitalWrite(analogPin2,LOW);
    }
}

/*
 * @param   m1Speed   Speed of motor 1
 * @param   m2Speed   Speed of motor 2
 * @param   m3Speed   Speed of motor 3
 * @param   m4Speed   Speed of motor 4
 *
 * Set speed all motors
 */
void QuadVNH3SP30MotorDriver::setSpeeds(int m1Speed, int m2Speed, int m3Speed, int m4Speed)
{
    setMotorSpeed(1, int m1Speed);
    setMotorSpeed(2, int m2Speed);
    setMotorSpeed(3, int m3Speed);
    setMotorSpeed(4, int m4Speed);
}

/*
 * @param   pwm         Pulse-width modulation
 * @param   analogPin1  First analog pin
 * @param   analogPin2  Second analog pin
 * @param   brake       Amount of brake
 *
 * Brake any motor, brake is a number between 0 and 255
 */
void QuadVNH3SP30MotorDriver::setPinBrake(int pwm, int analogPin1, int analogPin2, int brake)
{
    // normalize brake
    if (brake < 0)
    {
        brake = -brake;
    }
    if (brake > 255)  // Max brake
        brake = 255;
    digitalWrite(analogPin1, LOW);
    digitalWrite(analogPin2, LOW);
    analogWrite(pwm, brake);
}

/*
 * @param   motor       Select motor
 * @param   brake       Brake of motor
 *
 * Brake one motor, brake is a number between 0 and 255
 */
void QuadVNH3SP30MotorDriver::setMotorBrake(int motor, int brake)
{
    if (motor == 1)
        setPinBrake(_PWM1, _A1, _B1, brake);
    if (motor == 2)
        setPinBrake(_PWM2, _A2, _B2, brake);
    if (motor == 3)
        setPinBrake(_PWM3, _A3, _B3, brake);
    if (motor == 4)
        setPinBrake(_PWM4, _A4, _B4, brake);
}

/*
 * @param   m1Brake   Amount of braking for motor 1
 * @param   m2Brake   Amount of braking for motor 2
 * @param   m3Brake   Amount of braking for motor 3
 * @param   m4Brake   Amount of braking for motor 4
 *
 * Brake all motors, brake is a number between 0 and 255
 */
void QuadVNH3SP30MotorDriver::setBrakes(int m1Brake, int m2Brake, int m3Brake, int m4Brake)
{
    setMotorBrake(1, m1Brake);
    setMotorBrake(2, m2Brake);
    setMotorBrake(3, m3Brake);
    setMotorBrake(4, m4Brake);
}
