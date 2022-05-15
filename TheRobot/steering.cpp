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
  m1->forward(TurnSpeed);
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

  int rightState = readDigitalSensorRight();
  int leftState = readDigitalSensorLeft();
  if(rightState == HIGH && leftState == LOW) {
    //handleSharpRight(s,sv,m1,m2);
    stopAll(m1,m2);
    position = s->readLineBlack(sv);
  } else if(rightState == LOW && leftState == HIGH) {
    //handleSharpLeft(s,sv,m1,m2);
    stopAll(m1,m2);
    position = s->readLineBlack(sv);
  } else if(rightState == HIGH && leftState == HIGH) {
    stopAll(m1,m2);
    position = s->readLineBlack(sv);    
  }

  if(position == 0 || position == 7000) { //handle white space
    Serial.print("On white space, continue as usual ");
    Serial.print("(");
    Serial.print(position);
    Serial.print(")");
    m1->forward(rightMotorSpeed);
    m2->forward(leftMotorSpeed);
    return;
  }

  int error = position - 3500; //P
  //errorSum += error; //I
  int deltaError = error - lastError; //D
  int motorSpeed = Kp * error + /*Ki * errorSum +*/ Kd * deltaError;
  lastError = error;

  rightMotorSpeed = max(0,min(BaseSpeed1 + motorSpeed,MaxSpeed));
  leftMotorSpeed = min(max(BaseSpeed2 - motorSpeed,0),MaxSpeed);

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
