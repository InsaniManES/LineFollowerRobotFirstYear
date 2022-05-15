#include <Arduino.h>
#include "blackLineSensor.h"
#include "motor.h"
#include "helpers.h"

#ifndef STEERING_H
#define STEERING_H

void handleSharpRight(QTRSensors *s, uint16_t *sv, Motor *m1,Motor *m2);
void handleSharpLeft(QTRSensors *s, uint16_t *sv, Motor *m1,Motor *m2);
void handleSteering(QTRSensors *s, uint16_t *sv, Motor *m1, Motor *m2);
void testPID(int position, Motor *m1, Motor *m2);

#endif
