#include <Arduino.h>
#include "defines.h"

#ifndef HELPERS_H
#define HELPERS_H

enum Colors{RED,GREEN,BLUE,ERR};

void handleRed(bool (*func)());
void handleGreen(bool (*func)());
void handleBlue(bool (*func)());

#endif
