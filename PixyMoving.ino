#include "Moving.h"
#include "SerialComm.h"

#include <SPI.h>
#include <Pixy.h>
#include <string.h>

Pixy Camera;
boolean findMode;

void setup() {
    Serial.begin(57600);

    Camera.init();

    motorInit();

    
}

void loop() {
    uint16_t blocks;
    int blockPos;
    int blockWidth;
    int blockHeight;
    int blockArea;
    String outByte;
    char temp[127];

    blocks = Camera.getBlocks();

    if (blocks)
    {
        blockPos = Camera.blocks[0].x;
        blockWidth = Camera.blocks[0].width;
        blockHeight = Camera.blocks[0].height;
        blockArea = blockWidth * blockHeight;

        Serial.println('\r' + String(Camera.blocks[0].x) + '\n' + String(Camera.blocks[0].y) + '\n' +
            String(Camera.blocks[0].width) + '\n' + String(Camera.blocks[0].height) + '\n');

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
            {
                Move(DIR_FORWARD);
                delay(10);
            }
            else
            {
                Move(DIR_STOP);
                delay(500);
                Move(DIR_BACKWARD);
                delay(250);
                Move(DIR_STOP);
                delay(10);
            }
        }
    }
//    else
//    {
//        Serial.println(String(-1));
//    }
}
