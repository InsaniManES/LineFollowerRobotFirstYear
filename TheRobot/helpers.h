#include <Arduino.h>
#include "defines.h"

#ifndef HELPERS_H
#define HELPERS_H

int readDigitalSensorRight();
int readDigitalSensorLeft();
void setupDigitalSensors();

void handleRed(bool (*func)());
void handleGreen(bool (*func)());
void handleBlue(bool (*func)());

void handleRed(bool *func());
void handleGreen(bool *func());
void handleBlue(bool *func());

#endif
