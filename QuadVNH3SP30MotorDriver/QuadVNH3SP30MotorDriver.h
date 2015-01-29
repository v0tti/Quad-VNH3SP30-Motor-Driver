#ifndef QuadVNH3SP30MotorDriver_h
#define QuadVNH3SP30MotorDriver_h

#include <Arduino.h>

class QuadVNH3SP30MotorDriver
{
public:
    // CONSTRUCTORS
    QuadVNH3SP30MotorDriver(unsigned char A1, unsigned char iB1, unsigned char PWM1,unsigned char A2, unsigned char B2, unsigned char PWM2, unsigned char A3, unsigned char B3, unsigned char PWM3, unsigned char A4, unsigned char B4, unsigned char PWM4);
    // PUBLIC METHODS
    void init();    // Pinmodes

    void setMotorSpeed(int motor, int speed);   // Set speed for motor.
    void setPinSpeed(int pwm, int digitalPin1, int digitalPin2, int speed);
    void setSpeeds(int m1Speed, int m2Speed,int m3Speed, int m4Speed);      // Set speed for all Motors.

    void setMotorBrake(int motor, int brake, bool hardStop);   // Brake motor.
    void setPinBrake(int pwm, int digitalPin1, int digitalPin2, int brake,bool hardStop);
    void setBrakes(int m1Brake, int m2Brake, int m3Brake, int m4Brake, bool hardStop);     // Brake all Motors.
    
private:
    int _currentSpeed;
    bool _direction;
    unsigned char _A1;
    unsigned char _B1;
    unsigned char _PWM1;
    unsigned char _A2;
    unsigned char _B2;
    unsigned char _PWM2;
    unsigned char _A3;
    unsigned char _B3;
    unsigned char _PWM3;
    unsigned char _A4;
    unsigned char _B4;
    unsigned char _PWM4;
};

#endif