#include "QuadVNH3SP30MotorDriver.h"

// Constructors ////////////////////////////////////////////////////////////////

QuadVNH3SP30MotorDriver::QuadVNH3SP30MotorDriver(unsigned char A1, unsigned char iB1, unsigned char PWM1, unsigned char A2, unsigned char B2, unsigned char PWM2,unsigned char A3, unsigned char B3, unsigned char PWM3, unsigned char A4, unsigned char B4, unsigned char PWM4)
{
    //Pin map
    _A1 = A1;
    _B1 = iB1;
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
    _direction = 1;
    _currentSpeedM1 = 0;
    _currentSpeedM2 = 0;
    _currentSpeedM3 = 0;
    _currentSpeedM4 = 0;
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
        setPinSpeed(_PWM1, _A1, _B1, speed, _currentSpeedM1);
    if (motor == 2)
        setPinSpeed(_PWM2, _A2, _B2, speed, _currentSpeedM2);
    if (motor == 3)
        setPinSpeed(_PWM3, _A3, _B3, speed, _currentSpeedM3);
    if (motor == 4)
        setPinSpeed(_PWM4, _A4, _B4, speed, _currentSpeedM4);
}

/*
 * @param   pwm         Pulse-width modulation
 * @param   digitalPin1 First digital pin
 * @param   digitalPin2 Second digital pin
 * @param   speed       Speed of motor
 *
 * Set speed for any motor, speed is a number betwenn -255 and 255
 */
void QuadVNH3SP30MotorDriver::setPinSpeed(int pwm, int digitalPin1, int digitalPin2, int speed, int currentSpeed)
{
    unsigned char reverse = 0;
    
    if (speed < 0)
    {
        speed = -speed;  // Make speed a positive quantity
        _direction = !_direction;  // Preserve the direction
    }
    if (speed > 255)  // Max PWM dutycycle
        speed = 255;
    
    speed = speed - currentSpeed;
    int i = speed / 20;
    int r = speed % 20;
    for(i;i>0;i--){
        analogWrite(pwm ,currentSpeed + 20);
        delay(100);
    }
    analogWrite(pwm, speed+ r);
    
    if (speed == 0)
    {
        digitalWrite(digitalPin1, LOW);   // Make the motor coast no
        digitalWrite(digitalPin2, LOW);   // matter which direction it is spinning.
    }
    else if (_direction)
    {
        digitalWrite(digitalPin1,LOW);
        digitalWrite(digitalPin2,HIGH);
    }
    else
    {
        digitalWrite(digitalPin1,HIGH);
        digitalWrite(digitalPin2,LOW);
    }
    if(pwm==_PWM1)
        _currentSpeedM1 = speed;
    else if(pwm==_PWM2)
        _currentSpeedM2 = speed;
    else if(pwm==_PWM3)
        _currentSpeedM3 = speed;
    else if(pwm==_PWM4)
        _currentSpeedM4 = speed;
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
    setMotorSpeed(1, m1Speed);
    setMotorSpeed(2, m2Speed);
    setMotorSpeed(3, m3Speed);
    setMotorSpeed(4, m4Speed);
}

/*
 * @param   pwm         Pulse-width modulation
 * @param   digitalPin1  First digital pin
 * @param   digitalPin2  Second digital pin
 * @param   hardStop    hard stop or lettong it roll
 *
 * Brake any motor, speed is set to 0
 */
void QuadVNH3SP30MotorDriver::setPinBrake(int pwm, int digitalPin1, int digitalPin2, bool hardStop)
{
    if(hardStop){
        digitalWrite(digitalPin1, HIGH);
        digitalWrite(digitalPin2, HIGH);
    }else{
        digitalWrite(digitalPin1, LOW);
        digitalWrite(digitalPin2, LOW);
    }
    analogWrite(pwm, 0);
    if (_direction)
    {
        digitalWrite(digitalPin1,LOW);
        digitalWrite(digitalPin2,HIGH);
    }
    else
    {
        digitalWrite(digitalPin1,HIGH);
        digitalWrite(digitalPin2,LOW);
    }
    if(pwm==_PWM1)
        _currentSpeedM1 = 0;
    else if(pwm==_PWM2)
        _currentSpeedM2 = 0;
    else if(pwm==_PWM3)
        _currentSpeedM3 = 0;
    else if(pwm==_PWM4)
        _currentSpeedM4 = 0;

}

/*
 * @param   motor       Select motor
 * @param   hardStop    hard stop or lettong it roll
 *
 * Brake one motor, speed is set to 0
 */
void QuadVNH3SP30MotorDriver::setMotorBrake(int motor,bool hardStop)
{
    if (motor == 1)
        setPinBrake(_PWM1, _A1, _B1, hardStop);
    if (motor == 2)
        setPinBrake(_PWM2, _A2, _B2, hardStop);
    if (motor == 3)
        setPinBrake(_PWM3, _A3, _B3, hardStop);
    if (motor == 4)
        setPinBrake(_PWM4, _A4, _B4, hardStop);
}

/*
 * @param   hardStop  hard stop or lettong it roll
 *
 * Brake all motors, speed is set to 0
 */
void QuadVNH3SP30MotorDriver::setBrakes(bool hardStop)
{
    setMotorBrake(1, hardStop);
    setMotorBrake(2, hardStop);
    setMotorBrake(3, hardStop);
    setMotorBrake(4, hardStop);
}

