#include "env.h"
#include <Servo.h>



class Pin {
public:
  int ardPin;
  int depth;
  Servo servoMotor;  // create servo object to control a servo

  Pin(int ardPinIn) {
    ardPin = ardPinIn;
    depth = 0;

    servoMotor.attach(ardPin);
  }

  void setDepth(int depthIn) {
    depth = depthIn;
    moveServo();
  }

  void incDepth() {
    depth++;
    moveServo();
  }

  void moveServo() {
    Serial.print(".");
    int pos = calcServoPos();

    servoMotor.write(pos);
  }

  int calcServoPos(){
    int min = 20;
    int max = 160;
    // TODO math with dist from servo
    
    return map(depth, 0, CUT_COUNTS, min, max);
  }
  

};