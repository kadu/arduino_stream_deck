#include <Arduino.h>
#include "Keyboard.h"

void pressedButton(int value) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);

  if(value < 200) {
    Keyboard.press('X');
  } else if(value < 390) {
    Keyboard.press('Y');
  } else if(value < 900) {
    Keyboard.press('Z');
  }
  delay(50);
  Keyboard.releaseAll();
  delay(300);
}

void setup() {
  Serial.begin(115200);
  Keyboard.begin();
  delay(5000);
  Serial.println("Stream Deck Ready!");
}

void loop() {
  int value = analogRead(A0);
  delay(50);

  if(value > 10) { // if some button was pressed
    pressedButton(value);
  }
}