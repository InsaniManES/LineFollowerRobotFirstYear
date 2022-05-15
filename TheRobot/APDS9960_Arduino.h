#include <Arduino.h>
#include <Arduino_APDS9960.h>
#include "helpers.h"

#ifndef APDS9960_H
#define APDS9960_H

bool setup_apds9960_arduino();
int readColor_apds9960_arduino();
int readProximity_apds9960_arduino();

#endif
