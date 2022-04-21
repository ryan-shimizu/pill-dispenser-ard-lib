/*
 * Speaker.cpp - Speaker interface
 * Definition file for Speaker module
 * Created by Team Licensed to Pill, March 4, 2022
 */
#include "Arduino.h"
#include "Speaker.h"

Speaker::Speaker(uint8_t speaker_pin){
    this->_speaker_pin = speaker_pin;
    pinMode(speaker_pin, OUTPUT);
    //pin 5
}

void Speaker::play_tune(){
  // Plays tune at the end of the pill dispensing operation
      // TODO: Implement

  // change this to make the song slower or faster
  int tempo = 180;

  // change this to whichever pin you want to use
  int buzzer = this->_speaker_pin;


  int melody[] = {


    659, 8, 587, 8, 370, 4, 415, 4,
    554, 8, 494, 8, 294, 4, 330, 4,
    494, 8, 440, 8, 277, 4, 330, 4,
    440, 2,
  };

  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes

  int notes = sizeof(melody) / sizeof(melody[0]) / 2;

  // this calculates the duration of a whole note in ms
  int wholenote = (60000 * 4) / tempo;

  int divider = 0, noteDuration = 0;



    // iterate over the notes of the melody.
    // Remember, the array is twice the number of notes (notes + durations)
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

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

}
