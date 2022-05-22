#include "helpers.h"
#include "songs.h"
#include "defines.h"

void setupDigitalSensors() {
  pinMode(DigitalSensorRight,INPUT);
  pinMode(DigitalSensorLeft,INPUT);
}

int readDigitalSensorsState() {
  int rightState = readDigitalSensorRight();
  int leftState = readDigitalSensorLeft();
  if(rightState == HIGH && leftState == LOW) {
    return RIGHT;
  } else if(rightState == LOW && leftState == HIGH) {
    return RIGHT;
  } else if(rightState == HIGH && leftState == HIGH) {
    return BOTH;
  } else {
    return NONE;
  }
}

int readDigitalSensorRight() {
  return digitalRead(DigitalSensorRight);
}

int readDigitalSensorLeft() {
  return digitalRead(DigitalSensorLeft);
}

void handleRed(bool (*func)()) {
    superMarioMelody(BUZZER,func);
}
void handleGreen(bool (*func)()) {
    fureliseMelody(BUZZER,func);
}
void handleBlue(bool (*func)()) {
    nokiaMelody(BUZZER,func);
}
