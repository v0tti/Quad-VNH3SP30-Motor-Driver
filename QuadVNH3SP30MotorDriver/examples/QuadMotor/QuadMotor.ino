#include "QuadVNH3SP30MotorDriver.h"

QuadVNH3SP30MotorDriver *md = new QuadVNH3SP30MotorDriver((unsigned char)22,(unsigned char)23,(unsigned char)2,(unsigned char)25,(unsigned char)24,(unsigned char)3,(unsigned char)27,(unsigned char)26,(unsigned char)4,(unsigned char)28,(unsigned char)29,(unsigned char)5);

void setup() {
  md->init();
}

void loop() {
    md->setSpeeds(255,255,255,255);
    delay(500);
    md->setBrakes(0); 
}
