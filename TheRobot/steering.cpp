#include "steering.h"

int position = 0, lastError = 0, errorSum = 0;

void handleSteering(QTRSensors *s, uint16_t sv[], MotorDriver *d) {
  position = (*s).readLineBlack(sv);
  //Serial.println(position);
  //delay(100);
  //return;

  if(position == 0 || position == 7000) { //handle white space
    Serial.println("On white space");
    return;    
  }
  
  if(position>wayRight){
    (*d).motor1->forward(speedturn);
    (*d).motor2->backward(speedturn);
    return;    
  }
  if(position<wayLeft){ 
    (*d).motor2->forward(speedturn);
    (*d).motor1->backward(speedturn);
    return;
  }
  
  int error = position - 3500; //P
  errorSum += error; //I
  int errorChange = error - lastError; //D
  int motorSpeed = Kp * error + Ki * errorSum + Kd * errorChange;
  lastError = error;

  int rightMotorSpeed = max(0,min(BaseSpeed + motorSpeed,MaxSpeed));
  int leftMotorSpeed = min(max(BaseSpeed - motorSpeed,0),MaxSpeed);
  
  Serial.print("Position: ");
  Serial.print(position);
  Serial.print("Error: ");
  Serial.println(error);
  
  Serial.print("Right: ");
  Serial.print(rightMotorSpeed);
  Serial.print("\t Left: ");
  Serial.print(leftMotorSpeed);
  Serial.print("\t Speed: ");
  Serial.println(motorSpeed);

  (*d).motor1->forward(rightMotorSpeed);
  (*d).motor2->forward(leftMotorSpeed);
}
