#include "pin.h"

bool isLocked = true;
Pin pins[4] = { Pin(12), Pin(13), Pin(14), Pin(15) };

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Increment the least significant digit
  pins[PIN_STACKS - 1].incDepth();

  // Handle carry-over between digits
  for (int i = PIN_STACKS - 1; i >= 0; i--) {
    if (pins[i].depth == CUT_COUNTS) {
      pins[i].depth = 0;
      if (i > 0) {
        pins[i - 1].incDepth(); // Carry-over to the next digit
      }
    } else {
      break; // No more carry-over needed
    }
  }

  printState();
  delay(100);
}

void printState() {
  for (int i = 0; i < PIN_STACKS; i++) {
    Serial.print(pins[i].depth);
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