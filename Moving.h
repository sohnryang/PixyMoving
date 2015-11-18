#ifndef __MOVING__
#define __MOVING__

#include <DCM.h>
#include <MsTimer2.h>
#include <Pixy.h>

#define   DIR_FORWARD   0
#define   DIR_LEFT      1
#define   DIR_RIGHT     2
#define   DIR_BACKWARD  3
#define   DIR_LEFTTURN  4
#define   DIR_RIGHTRURN 5

DCM Motor1;
DCM Motor2;
DCM Motor3;
DCM Motor4;

void motorInit()
{
  Motor1.attachPins(16, 17);
  Motor2.attachPins(18, 19);
  Motor3.attachPins(20, 21);
  Motor4.attachPins(22, 23);
}

void Move(int dir, int duration)
{
  if(dir == DIR_FORWARD)
  {
    Motor1.write(CW, 5);
    Motor2.write(CCW, 5);
    Motor3.write(CW, 5);
    Motor4.write(CCW, 5);
    delay(duration * 1000);
    Motor1.write(STOP, 0);
    Motor2.write(STOP, 0);
    Motor3.write(STOP, 0);
    Motor4.write(STOP, 0);
  }
  else if(dir == DIR_BACKWARD)
  {
    Motor1.write(CCW, 5);
    Motor2.write(CW, 5);
    Motor3.write(CCW, 5);
    Motor4.write(CW, 5);
    delay(duration * 1000);
    Motor1.write(STOP, 0);
    Motor2.write(STOP, 0);
    Motor3.write(STOP, 0);
    Motor4.write(STOP, 0);
  }
  else if(dir == DIR_LEFT)
  {
    Motor1.write(CCW, 5);
    Motor2.write(CW, 5);
    Motor3.write(CW, 5);
    Motor4.write(CCW, 5);
    delay(duration * 1000);
    Motor1.write(STOP, 0);
    Motor2.write(STOP, 0);
    Motor3.write(STOP, 0);
    Motor4.write(STOP, 0);
  }
  else
  {
    Motor1.write(CW, 5);
    Motor2.write(CCW, 5);
    Motor3.write(CCW, 5);
    Motor4.write(CW, 5);
    delay(duration * 1000);
    Motor1.write(STOP, 0);
    Motor2.write(STOP, 0);
    Motor3.write(STOP, 0);
    Motor4.write(STOP, 0);
  }
}

#endif
