#ifndef QuadVNH5019MotorDriver_h
#define QuadVNH5019MotorDriver_h

#include <Arduino.h>

class QuadVNH5019MotorDriver
{
public:
    // CONSTRUCTORS
    QuadVNH5019MotorDriver(unsigned char A1, unsigned char B1, unsigned char PWM1, unsigned char A2, 		unsigned char B2, unsigned char PWM2, unsigned char A3, unsigned char B3, unsigned char 	PWM3, unsigned char A4, unsigned char B4, unsigned char PWM4);
    // PUBLIC METHODS
    void init(); // Pinmodes
    void setM1Speed(int speed); // Set speed for M1.
    void setM2Speed(int speed); // Set speed for M2.
    void setM3Speed(int speed); // Set speed for M3.
    void setM4Speed(int speed); // Set speed for M4.
    void setSpeeds(int m1Speed, int m2Speed,int m3Speed, int m4Speed); // Set speed for all Motors.
    void setM1Brake(int brake); // Brake M1.
    void setM2Brake(int brake); // Brake M2.
    void setM3Brake(int brake); // Brake M3.
    void setM4Brake(int brake); // Brake M4.
    void setBrakes(int m1Brake, int m2Brake,int m3Brake, int m4Brake); // Brake all Motors.
    
private:
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