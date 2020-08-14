#include <Arduino.h>
#include "Keyboard.h"

bool showMessage = false;
String message;

void setup() {
  Serial.begin(115200);
  Keyboard.begin();
  delay(5000);
  Serial.println("Stream Deck Ready!");
}


void loop() {
  int value = analogRead(A0);
  delay(50);

  if(value > 10) {
    if( value < 200) {
      message = "Button 1";
      showMessage = true;
    } else if(value < 390) {
      message = "Button 2";
      showMessage = true;
    } else if(value < 900) {
      message = "Button 3";
      showMessage = true;
    }
  }

  if(showMessage) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('X');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    showMessage = false;
  }
}