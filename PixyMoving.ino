#include "Moving.h"

#include <SPI.h>
#include <Pixy.h>

Pixy Camera;
boolean findMode;

void setup() {
    Serial.begin(9600);

    Camera.init();

    motorInit();
}

void loop() {
    uint16_t blocks;
    int blockPos;
    int blockWidth;
    int blockHeight;
    int blockArea;

    blocks = Camera.getBlocks();

    if (blocks)
    {

        blockPos = Camera.blocks[0].x;
        blockWidth = Camera.blocks[0].width;
        blockHeight = Camera.blocks[0].height;
        blockArea = blockWidth * blockHeight;

        if (blockPos < 50)
        {
            Move(DIR_LEFT);
        }
        else if (blockPos > 250)
        {
            Move(DIR_RIGHT);
        }
        else
        {
           // Move(DIR_STOP);
            //delay(10);
             if (blockArea < 20000)
                 {Move(DIR_FORWARD); delay(10);}
             else
                 {Move(DIR_STOP); delay(10);}
        }
    }
    else
    {
        // Move(DIR_STOP);
    }
}
