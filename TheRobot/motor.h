#include <Arduino.h>
#include "defines.h"

// motor.h
#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
private:
  int _in1;
  int _in2;

public:
  Motor(int x,int y);
  void setup();
  void forward(int speedValue);
  void backward(int speedValue);
  void stop();
  void speed(int speedValue1, int speedValue2);
};

#endif
