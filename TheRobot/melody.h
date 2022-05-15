#include <Arduino.h>
#include "pitches.h"

// melody.h
#ifndef MELODY_H
#define MELODY_H

class Melody
{
  int tempo = 144; //default
  int *melody; //expected to be an array
  int notes;
  int wholenote;
  int divider = 0, noteDuration = 0;

public:
  Melody(int y[], int z);
  Melody(int x,int y[], int z);
  bool play(int buzzer);
  bool play(int buzzer,bool *func());
  bool play(int buzzer,bool (*func)());
};

#endif
