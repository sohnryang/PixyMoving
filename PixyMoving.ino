#include "Moving.h"

#include <SPI.h>  
#include <Pixy.h>

Pixy Camera;

void servoMove(int dir);

void setup() {
  Serial.begin(9600);
  
  Camera.init();
  
  motorInit();
}

void loop() {
  uint16_t blocks;
  int blockPos;

  blocks = Camera.getBlocks();

  if (blocks)
  {
    blockPos = Camera.blocks[0].x;

    if (blockPos < 50)
      Move(DIR_LEFT);
    else if (blockPos > 250)
      Move(DIR_RIGHT);
    else
      Move(DIR_STOP);
  }
}
