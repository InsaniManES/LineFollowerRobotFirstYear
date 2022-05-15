#include "motor.h"

Motor::Motor(int x,int y){
  _in1 = x;
  _in2 = y;
}

void Motor::setup() {
  pinMode(_in1,OUTPUT);
  pinMode(_in2,OUTPUT);  
}

void Motor::forward(int speedValue) {
  analogWrite(_in1,max(min(speedValue,255),0));
  analogWrite(_in2,0);
}

void Motor::backward(int speedValue) {
  analogWrite(_in1,0);
  analogWrite(_in2,max(min(speedValue,255),0));
}

void Motor::stop() {
  analogWrite(_in1,0);
  analogWrite(_in2,0);
}

void Motor::speed(int speedValue1, int speedValue2) {
  analogWrite(_in1,max(min(speedValue1,255),0));
  analogWrite(_in2,max(min(speedValue2,255),0));
}
