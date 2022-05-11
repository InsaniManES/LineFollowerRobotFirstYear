#include "melody.h"

Melody::Melody(int x,int *y, int z){
  tempo = x;
  melody = y;
  notes = z;
  // this calculates the duration of a whole note in ms
  wholenote = (60000 * 4) / tempo;
}

bool Melody::play(int buzzer) {
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  int thisNote = 0;
  for (;thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
  return true;
}

bool Melody::play(int buzzer,bool *func()) {
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  int thisNote = 0;
  for (;thisNote < notes * 2; thisNote = thisNote + 2) {
    if(!func()) return false; //interupted

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
  return true;
}
