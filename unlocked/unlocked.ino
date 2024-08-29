#include "pin.h"

bool isLocked = true;
Pin pins[PIN_STACKS] = { Pin(1, 0) ,Pin(2, 135), Pin(3, 0), Pin(4, 0), Pin(5, 0) };

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < PIN_STACKS; i++) {
    pins[i].init();
  }
  Serial.println("Ready");
  Serial.println("~~~~~~~~~~~~");
}

void loop() {
  // serialDebug();
  // bruteForce();
  wearIn();
  // resetAll();
}

void swingTest() {
  pins[0].goToAngle(0);
  Serial.println("0");
  delay(1000);

  pins[0].goToAngle(90);
  Serial.println("90");
  delay(1000);
}


void serialDebug() {
  if (!Serial.available()) return;

  String input = Serial.readString();
  int pin = input.substring(0, 1).toInt();
  int depth = input.substring(2).toInt();

  Serial.print("Pin - ");
  Serial.println(pin);
  Serial.print("Depth - ");
  Serial.println(depth);

  pins[pin].setDepth(depth);

  printState();
  delay(1000);
}

void wearIn(){
  for (int i = PIN_STACKS - 1; i >= 0; i--) {
    pins[i].setDepth(5); 
    pins[i].resetDepth();
  }
}

void resetAll(){
  for (int i = PIN_STACKS - 1; i >= 0; i--) {
    pins[i].resetDepth();
  }
}


void bruteForce() {
  // Increment the least significant digit
  pins[PIN_STACKS - 1].incDepth();

  // Handle carry-over between digits
  for (int i = PIN_STACKS - 1; i >= 0; i--) {
    if (pins[i].depth == CUT_COUNTS) {
      pins[i].resetDepth();
      if (i > 0) {
        pins[i - 1].incDepth();  // Carry-over to the next digit
      }
    } else {
      break;  // No more carry-over needed
    }
  }
 
  printState();
}


void printState() {
  Serial.println("State");

  for (int i = 0; i < PIN_STACKS; i++) {
    Serial.print(i);
    Serial.print(":");
    Serial.print(pins[i].printMotorPos());
    Serial.print(" ");
  }
  Serial.println();
  Serial.println("~~~~~~~~~~~~");
}


void testLock() {
  // try rotate

  // check force/rotation
  int force = 0.2;

  printState();
  if (force > 0.5) {
    Serial.println("Failed to unlock");
  } else {
    Serial.println("Unlocked!!!");
    isLocked = false;
  }
}