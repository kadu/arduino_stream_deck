#include <Arduino.h>
#include "Keyboard.h"

bool imprime = false;
String mensagem;

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
      mensagem = "Botao 1";
      imprime = true;
    } else if(value < 390) {
      mensagem = "Botao 2";
      imprime = true;
    } else if(value < 900) {
      mensagem = "Botao 3";
      imprime = true;
    }
  }

  if(imprime) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('X');
    delay(100);
    Keyboard.releaseAll();
    delay(1000);
    imprime = false;
  }
}
