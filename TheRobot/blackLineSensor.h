#include <Arduino.h>
#include <QTRSensors.h>
#include "defines.h"

// blackLineSensor.h
#ifndef BLS_H //BlackLineSensor
#define BLS_H

void setupBlackLineSensor(QTRSensors *qtr);
void calibrateBlackLineSensor(QTRSensors *qtr);
void QTR8RCExmaple();

#endif
