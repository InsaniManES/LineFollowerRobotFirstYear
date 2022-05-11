#include <Arduino.h>
#include "defines.h"

// motor.h
#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
  int in1;
  int in2;

public:
  Motor(int x,int y);
  void forward(int speedValue);
  void backward(int speedValue);
  void stop();
  void speed(int speedValue1, int speedValue2);

};

class MotorDriver
{
  bool _mode = LOW;
  int _pinMode;

public:
  Motor *motor1;
  Motor *motor2;
  MotorDriver(int IN1_A, int IN2_A, int IN1_B, int IN2_B, int modePin);
  void setupMode(bool m);
  void stopAll();
};

#endif
