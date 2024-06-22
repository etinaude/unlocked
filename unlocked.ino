#include "pin.h"

bool isLocked = true;
Pin pins[PIN_STACKS] = { Pin(1), Pin(2), Pin(3) };
// Pin pins[0] = { };

// Servo testServo;


void setup() {
  // testServo.attach(3);


  Serial.begin(9600);
  for (int i = 0; i < PIN_STACKS; i++) {
    pins[i].init();
  }
  Serial.println("Ready");
}

void loop() {
  serialDebug();

  // testServo.write(0);
  // Serial.println("0");
  // delay(1000);

  // testServo.write(90);
  // Serial.println("90");
  delay(1000);

}


void serialDebug(){
  
  if(!Serial.available()) return;

  int pos = Serial.readString().toInt();

  pins[0].setDepth(pos);
  pins[1].setDepth(pos);
  pins[2].setDepth(pos);

  printState();

}


void bruteForce(){
 // Increment the least significant digit
  pins[PIN_STACKS - 1].incDepth();

  // Handle carry-over between digits
  for (int i = PIN_STACKS - 1; i >= 0; i--) {
    if (pins[i].depth == CUT_COUNTS) {
      pins[i].resetDepth();
      if (i > 0) {
        pins[i - 1].incDepth(); // Carry-over to the next digit
      }
    } else {
      break; // No more carry-over needed
    }
  }

  printState();
}


void printState() {
  for (int i = 0; i < PIN_STACKS; i++) {
    Serial.print(pins[i].printMotorPos());
    Serial.print(" ");
  }
  Serial.println();
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