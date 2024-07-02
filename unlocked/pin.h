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
  float offsetAngle = 0;

  Pin(int ID, float offset) {
    DXL_ID = ID;
    depth = 0;
    offsetAngle = offset;
  }

  Pin(int ID) {
    Pin(ID, 0);
  }


  void init() {
    setupMotors();
    resetDepth();
  }

  void setupMotors() {
    dxl.begin(115200);
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

  void goToAngle(float angle) {
    dxl.setGoalPosition(DXL_ID, angle, UNIT_DEGREE);
    delay(600);
    current_pos = dxl.getPresentPosition(DXL_ID, UNIT_DEGREE);
  }

  void moveServo() {
    float pos = baseAngles[depth] + offsetAngle;

    goToAngle(pos);
  }

  float printMotorPos() {
    current_pos = dxl.getPresentPosition(DXL_ID, UNIT_DEGREE);
    return current_pos;
  }
};