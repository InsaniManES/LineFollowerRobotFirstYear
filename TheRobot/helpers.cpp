#include "helpers.h"
#include "songs.h"
#include "defines.h"

void setupDigitalSensors() {
  pinMode(DigitalSensorRight,INPUT);
  pinMode(DigitalSensorLeft,INPUT);
}

int readDigitalSensorRight() {
  return digitalRead(DigitalSensorRight);
}

int readDigitalSensorLeft() {
  return digitalRead(DigitalSensorRight);
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
