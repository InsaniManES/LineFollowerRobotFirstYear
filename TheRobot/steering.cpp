#include "steering.h"

int lastError = 0, errorSum = 0; //variables for PID
int rightMotorSpeed = 0, leftMotorSpeed = 0; //variables for motor speed

void stopAll(Motor *m1,Motor *m2) {
  m1->stop();
  m2->stop();  
}

void handleSharpRight(QTRSensors *s, uint16_t sv[], Motor *m1,Motor *m2) {
  m1->backward(TurnSpeed);
  m2->forward(TurnSpeed);
  int position = s->readLineBlack(sv);
  while (position < 3000 || position > 4000) {
    position = s->readLineBlack(sv); 
  }
}
void handleSharpLeft(QTRSensors *s, uint16_t sv[], Motor *m1,Motor *m2) {
  m1->forward(0);
  m2->backward(TurnSpeed);
  int position = s->readLineBlack(sv);
  while (position < 3000 || position > 4000) {
    position = s->readLineBlack(sv); 
  }
}

//motor1 - right
//motor2 - left
void handleSteering(QTRSensors *s, uint16_t sv[], Motor *m1,Motor *m2) {
  int position = s->readLineBlack(sv);
  //Serial.println(position);
  //delay(100);
  //return;

  /*
  switch(readDigitalSensorsState()) {
    case RIGHT:
    stopAll(m1,m2);
    delay(50);
    handleSharpRight(s,sv,m1,m2);
    position = s->readLineBlack(sv);
    break;
    case LEFT:
    delay(50);
    stopAll(m1,m2);
    handleSharpLeft(s,sv,m1,m2);
    position = s->readLineBlack(sv);
    break;
  }
  */

  if(position == 0 || position == 7000) { //handle white space
    Serial.print("On white space, continue as usual ");
    Serial.print("(");
    Serial.print(position);
    Serial.print(")");
    Serial.println();
    m1->forward(rightMotorSpeed);
    m2->forward(leftMotorSpeed);
    return;
  }

  int error = position - 3500; //P
  //errorSum += error; //I
  int deltaError = error - lastError; //D
  int motorSpeed = Kp * error + /*Ki * errorSum +*/ Kd * deltaError;
  lastError = error;

  rightMotorSpeed = min(max(BaseSpeed1 - motorSpeed,0),MaxSpeed);
  leftMotorSpeed = max(0,min(BaseSpeed2 + motorSpeed,MaxSpeed));

  Serial.print("P = ");
  Serial.print(error);
  Serial.print(" D = ");
  Serial.println(deltaError);
  Serial.print(" Speed ");
  Serial.print(motorSpeed);
  Serial.print("rightMotorSpeed = ");
  Serial.print(rightMotorSpeed);
  Serial.print(" leftMotorSpeed = ");
  Serial.print(leftMotorSpeed);
  Serial.println();

  m1->forward(rightMotorSpeed);
  m2->forward(leftMotorSpeed);
}
