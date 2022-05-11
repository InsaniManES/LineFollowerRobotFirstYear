#include "motor.h"

Motor::Motor(int x,int y){
  in1 = x;
  in2 = y;
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
}

void Motor::forward(int speedValue) {
  analogWrite(in1,max(min(speedValue,255),0));
  analogWrite(in2,0);
}

void Motor::backward(int speedValue) {
  analogWrite(in1,0);
  analogWrite(in2,max(min(speedValue,255),0));
}

void Motor::stop() {
  analogWrite(in1,0);
  analogWrite(in2,0);
}

void Motor::speed(int speedValue1, int speedValue2) {
  analogWrite(in1,max(min(speedValue1,255),0));
  analogWrite(in2,max(min(speedValue2,255),0));
}

MotorDriver::MotorDriver(int in1_A, int in2_A, int in1_B, int in2_B, int modePin) {
  _pinMode = modePin;
  pinMode(_pinMode,OUTPUT);
  setupMode(MOTOR_MODE_STATE);
  *motor1 = Motor(in1_A,in2_A);
  *motor2 = Motor(in1_B,in2_B);
}

void MotorDriver::setupMode(bool m) {
  _mode = m;
  digitalWrite(_pinMode,_mode);
}

void MotorDriver::stopAll() {
  motor1->stop();
  motor2->stop();
}
