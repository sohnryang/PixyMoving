#ifndef __SERIALCOMM__
#define __SERIALCOMM__

void sendString(char * data, int len)
{
  int i;
  
  for (i = 0; i < (len - 1); i++)
    Serial.write(data[i]);
}

#endif
