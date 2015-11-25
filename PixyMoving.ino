#include "Moving.h"

#include <SPI.h>  
#include <Pixy.h>

Pixy Camera;

void servoMove(int dir);

void setup() {
  Serial.begin(9600);
  Serial.print("Starting...\n");

  Camera.init();
  
  motorInit();
}

void loop() {
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];
  int32_t panError, tiltError;

  walkTime = millis();

  blocks = pixy.getBlocks();

  if (blocks)
  {
    panError = X_CENTER - pixy.blocks[0].x;                      //현재 상태에서 화면 중심을 기준으로 오차 계산
    tiltError = pixy.blocks[0].y - Y_CENTER;

    panLoop.update(panError);                                    //2개의 모터(X,Y) 조작량 계산
    tiltLoop.update(tiltError);

    servoMove(panLoop.m_pos, tiltLoop.m_pos);                   //현재 계산된 위치에 따른 서보 각도 이동
  }
}
