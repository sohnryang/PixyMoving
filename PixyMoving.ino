#include "Moving.h"

#include <SPI.h>  
#include <Pixy.h>

Pixy Camera;

void setup() {
  Serial.begin(9600);
  Serial.print("Starting...\n");

  Camera.init();
  
  motorInit();
//  Move(DIR_RIGHT, 10);
}

void loop() {
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 

  blocks = Camera.getBlocks();

  if (blocks)
  {
    i++;

    if (i%50==0)
    {
      sprintf(buf, "Detected %d:\n", blocks);
      Serial.print(buf);
      for (j=0; j<blocks; j++)
      {
        sprintf(buf, "  block %d: ", j);
        Serial.print(buf);
        Camera.blocks[j].print();
      }
    }
  }  
}
