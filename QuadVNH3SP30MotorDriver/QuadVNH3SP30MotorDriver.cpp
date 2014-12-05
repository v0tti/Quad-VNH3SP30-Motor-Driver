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
 * @param   speed   Speed of motor 1
 *
 * Set speed for motor 1, speed is a number betwenn -255 and 255
 */
void QuadVNH3SP30MotorDriver::setM1Speed(int speed)
{
    unsigned char reverse = 0;
    
    if (speed < 0)
    {
        speed = -speed;  // Make speed a positive quantity
        reverse = 1;  // Preserve the direction
    }
    if (speed > 255)  // Max PWM dutycycle
        speed = 255;
    
    analogWrite(_PWM1,speed);
    
    if (speed == 0)
    {
        digitalWrite(_A1,LOW);   // Make the motor coast no
        digitalWrite(_B1,LOW);   // matter which direction it is spinning.
    }
    else if (reverse)
    {
        digitalWrite(_A1,LOW);
        digitalWrite(_B1,HIGH);
    }
    else
    {
        digitalWrite(_A1,HIGH);
        digitalWrite(_B1,LOW);
    }
}

/*
 * @param   speed   Speed of motor 2
 *
 * Set speed for motor 2, speed is a number betwenn -255 and 255
 */
void QuadVNH3SP30MotorDriver::setM2Speed(int speed)
{
    unsigned char reverse = 0;
    
    if (speed < 0)
    {
        speed = -speed;  // Make speed a positive quantity
        reverse = 1;  // Preserve the direction
    }
    if (speed > 255)  // Max PWM dutycycle
        speed = 255;
    
    analogWrite(_PWM2,speed);
    
    if (speed == 0)
    {
        digitalWrite(_A2,LOW);   // Make the motor coast no
        digitalWrite(_B2,LOW);   // matter which direction it is spinning.
    }
    else if (reverse)
    {
        digitalWrite(_A2,LOW);
        digitalWrite(_B2,HIGH);
    }
    else
    {
        digitalWrite(_A2,HIGH);
        digitalWrite(_B2,LOW);
    }
}

/*
 * @param   speed   Speed of motor 3
 *
 * Set speed for motor 3, speed is a number betwenn -255 and 255
 */
void QuadVNH3SP30MotorDriver::setM3Speed(int speed)
{
    unsigned char reverse = 0;
    
    if (speed < 0)
    {
        speed = -speed;  // Make speed a positive quantity
        reverse = 1;  // Preserve the direction
    }
    if (speed > 255)  // Max PWM dutycycle
        speed = 255;
    
    analogWrite(_PWM3,speed);
    
    if (speed == 0)
    {
        digitalWrite(_A3,LOW);   // Make the motor coast no
        digitalWrite(_B3,LOW);   // matter which direction it is spinning.
    }
    else if (reverse)
    {
        digitalWrite(_A3,LOW);
        digitalWrite(_B3,HIGH);
    }
    else
    {
        digitalWrite(_A3,HIGH);
        digitalWrite(_B3,LOW);
    }
}

/*
 * @param   speed   Speed of motor 3
 *
 * Set speed for motor 3, speed is a number betwenn -255 and 255
 */
void QuadVNH3SP30MotorDriver::setM4Speed(int speed)
{
    unsigned char reverse = 0;
    
    if (speed < 0)
    {
        speed = -speed;  // Make speed a positive quantity
        reverse = 1;  // Preserve the direction
    }
    if (speed > 255)  // Max PWM dutycycle
        speed = 255;
    
    analogWrite(_PWM4,speed);
    
    if (speed == 0)
    {
        digitalWrite(_A4,LOW);   // Make the motor coast no
        digitalWrite(_B4,LOW);   // matter which direction it is spinning.
    }
    else if (reverse)
    {
        digitalWrite(_A4,LOW);
        digitalWrite(_B4,HIGH);
    }
    else
    {
        digitalWrite(_A4,HIGH);
        digitalWrite(_B4,LOW);
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
    setM1Speed(m1Speed);
    setM2Speed(m2Speed);
    setM3Speed(m3Speed);
    setM4Speed(m4Speed);
}

/*
 * @param   brake   Amount of braking
 *
 * Brake motor 1, brake is a number between 0 and 255
 */
void QuadVNH3SP30MotorDriver::setM1Brake(int brake)
{
    // normalize brake
    if (brake < 0)
    {
        brake = -brake;
    }
    if (brake > 255)  // Max brake
        brake = 255;
    digitalWrite(_A1, LOW);
    digitalWrite(_B1, LOW);
    analogWrite(_PWM1,brake);
}

/*
 * @param   brake   Amount of braking
 *
 * Brake motor 2, brake is a number between 0 and 255
 */
void QuadVNH3SP30MotorDriver::setM2Brake(int brake)
{
    // normalize brake
    if (brake < 0)
    {
        brake = -brake;
    }
    if (brake > 255)  // Max brake
        brake = 255;
    digitalWrite(_A2, LOW);
    digitalWrite(_B2, LOW);
    analogWrite(_PWM2,brake);
}

/*
 * @param   brake   Amount of braking
 *
 * Brake motor 3, brake is a number between 0 and 255
 */
void QuadVNH3SP30MotorDriver::setM3Brake(int brake)
{
    // normalize brake
    if (brake < 0)
    {
        brake = -brake;
    }
    if (brake > 255)  // Max brake
        brake = 255;
    digitalWrite(_A3, LOW);
    digitalWrite(_B3, LOW);
    analogWrite(_PWM3,brake);
}

/*
 * @param   brake   Amount of braking
 *
 * Brake motor 4, brake is a number between 0 and 255
 */
void QuadVNH3SP30MotorDriver::setM4Brake(int brake)
{
    // normalize brake
    if (brake < 0)
    {
        brake = -brake;
    }
    if (brake > 255)  // Max brake
        brake = 255;
    digitalWrite(_A4, LOW);
    digitalWrite(_B4, LOW);
    analogWrite(_PWM4,brake);
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
    setM1Brake(m1Brake);
    setM2Brake(m2Brake);
    setM3Brake(m3Brake);
    setM4Brake(m4Brake);
}
