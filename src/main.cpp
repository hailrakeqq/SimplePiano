#include <Arduino.h>
#include "../include/pitches.h"
#define ACTIVATED LOW

const int PIEZO = 9;
const int LED = 13;

int buttonSong = 6;
const int BUTTON_C = 2;
const int BUTTON_AS = 3;
const int BUTTON_A = 4;
const int BUTTON_G = 5;


void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_C, INPUT);
  digitalWrite(BUTTON_C,HIGH);
  pinMode(BUTTON_AS, INPUT);
  digitalWrite(BUTTON_AS,HIGH);
  pinMode(BUTTON_A, INPUT);
  digitalWrite(BUTTON_A,HIGH);
  pinMode(BUTTON_G, INPUT);
  digitalWrite(BUTTON_G,HIGH);
  pinMode (buttonSong, INPUT);
  digitalWrite(buttonSong, HIGH);
  
  digitalWrite(LED,LOW);
}

int melody[] = {
NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, 0, 0, 0, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4, 
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3,
NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, 0, 0,
NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_A3, NOTE_F3, 
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_G3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4, 
};

int noteDurations[] = {
  4500, 2250, 2250, 4500, 2250, 2250, 2250, 2250, 2250, 4500, 3000, 9000, 4500,
  4500, 2250, 4500, 2250, 1125, 2250, 4500, 4500, 2250, 4500, 2250, 4500, 2250,
  4500, 4500, 4500, 2250, 4500, 4500, 4500, 2250, 4500, 2250, 4500, 2000,
  4500, 4500, 4500, 2250, 4500, 4500,
  4500, 2250, 2250, 4500, 2250, 2250, 2250, 2250, 2250, 4500, 3000, 9000, 4500,
  4500, 2250, 4500, 4500, 4500, 4500, 4500, 4500, 3000, 3000, 4500,
  2250, 4500, 2250, 4500, 2250,
  4500, 4500, 4500, 4500, 2250, 4500, 4500, 2250, 4500, 2250, 4500, 2250,
} ;

void playMelody() {
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
    if (melody[thisNote] != 0) {
      int noteDuration = 600 / noteDurations[thisNote];
      tone(PIEZO, melody[thisNote], noteDuration);
      delay(noteDuration * 1.50);
      noTone(PIEZO);
    } else {
      delay(noteDurations[thisNote]);
    }
  }

  delay(10000);
}


void loop()
{
  while(digitalRead(BUTTON_C) == ACTIVATED)
  {
    tone(PIEZO,NOTE_C5);
    digitalWrite(LED,HIGH);
  }
  while(digitalRead(BUTTON_AS) == ACTIVATED)
  {
    tone(PIEZO,NOTE_AS4);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(BUTTON_A) == ACTIVATED)
  {
    tone(PIEZO,NOTE_A4);
    digitalWrite(LED,HIGH);
  }
  
  while(digitalRead(BUTTON_G) == ACTIVATED)
  {
    tone(PIEZO,NOTE_G4);
    digitalWrite(LED,HIGH);
  }
  
  if (digitalRead(buttonSong) == ACTIVATED) {
    for (int thisNote = 0; thisNote < 85; thisNote++) {
      int noteDuration = noteDurations[thisNote];
      tone(11, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.50;
      delay(pauseBetweenNotes);
      noTone(11);
    }
  }
  
  noTone(PIEZO);
  digitalWrite(LED,LOW);
}