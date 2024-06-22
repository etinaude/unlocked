// Please refer to e-Manual(http://emanual.robotis.com/docs/en/parts/interface/dynamixel_shield/) for available range of value.
#include "env.h"
#include <Dynamixel2Arduino.h>

#define DXL_SERIAL Serial1

Dynamixel2Arduino dxl(DXL_SERIAL);

using namespace ControlTableItem;

class Pin {
public:
  int DXL_ID;
  int depth;
  float current_pos = 0;

  Pin(int ardPinIn) {
    DXL_ID = ardPinIn;
    depth = 0;
  }

  void init() {
    setupMotors();
  }

  void setupMotors() {
    dxl.begin(1000000);
    dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
    dxl.ping(DXL_ID);  // Get DYNAMIXEL information

    // Turn off torque when configuring items in EEPROM area
    dxl.torqueOff(DXL_ID);
    dxl.setOperatingMode(DXL_ID, OP_POSITION);
    dxl.torqueOn(DXL_ID);

    // Limit the maximum velocity in Position Control Mode. Use 0 for Max speed
    dxl.writeControlTableItem(PROFILE_VELOCITY, DXL_ID, SPEED);
  }

  void setDepth(int depthIn) {
    depth = depthIn;
    moveServo();
  }

  void incDepth() {
    depth++;
    moveServo();
  }

  void resetDepth() {
    depth = 0;
    moveServo();
  }

  void moveServo() {
    int pos = calcServoPos();

    dxl.setGoalPosition(DXL_ID, pos, UNIT_DEGREE);
    delay(800);
    current_pos = dxl.getPresentPosition(DXL_ID, UNIT_DEGREE);
  }

  int calcServoPos() {
    int min = 100;
    int max = 200;
    // TODO math with dist from servo

    return map(depth, 0, CUT_COUNTS, min, max);
  }

  int printMotorPos() {
    current_pos = dxl.getPresentPosition(DXL_ID, UNIT_DEGREE);
    return current_pos;
  }
};