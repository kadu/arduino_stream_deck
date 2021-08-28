#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <BleKeyboard.h>
#include <WiFi.h>
#include <OneButton.h>

#define btn1 23
#define btn2 22
#define btn3 21
#define btn4 19
#define btn5 18
#define btn6 17
#define btn7 16
#define btn8 25
#define btn9 26
#define NUM_LEDS 27

#define NUMPIXELS 2
Adafruit_NeoPixel pixels(NUMPIXELS, NUM_LEDS, NEO_GRB + NEO_KHZ800);
BleKeyboard bleKeyboard("StreamDeckBLE", "http://kaduzi.us", 100);
OneButton button_1(btn1, true);
OneButton button_2(btn2);
OneButton button_3(btn3);
OneButton button_4(btn4);
OneButton button_5(btn5);
OneButton button_6(btn6);
OneButton button_7(btn7);
OneButton button_8(btn8);
OneButton button_9(btn9);

void sendCommand(uint8_t LETTER) {
  pixels.setPixelColor(1, pixels.Color(0,0,255));
  pixels.show();
  bleKeyboard.press(KEY_RIGHT_CTRL);
  bleKeyboard.press(KEY_RIGHT_ALT);
  bleKeyboard.press(KEY_RIGHT_SHIFT);
  bleKeyboard.press(LETTER);

  delay(50);
  bleKeyboard.releaseAll();
  pixels.setPixelColor(1, pixels.Color(0,0,0));
  pixels.show();
  Serial.println("Sended " + LETTER);
}

void btn1_function() {
  sendCommand('Z');
}

void btn2_function() {
  sendCommand('Y');
}

void btn3_function() {
  sendCommand('W');
}

void btn4_function() {
  sendCommand('X');
}

void btn5_function() {
  sendCommand('V');
}

void btn6_function() {
  sendCommand('U');
}

void btn7_function() {
  sendCommand('T');
}

void btn8_function() {
  sendCommand('S');
}

void btn9_function() {
  sendCommand('R');
}

void setup() {
  WiFi.disconnect(true);  // Disconnect from the network
  WiFi.mode(WIFI_OFF);    // Switch WiFi off
  delay(12);
  bleKeyboard.begin();

  button_1.attachClick(btn1_function);
  button_2.attachClick(btn2_function);
  button_3.attachClick(btn3_function);
  button_4.attachClick(btn4_function);
  button_5.attachClick(btn5_function);
  button_6.attachClick(btn6_function);
  button_7.attachClick(btn7_function);
  button_8.attachClick(btn8_function);
  button_9.attachClick(btn9_function);

  button_1.setClickTicks(200);
  button_2.setClickTicks(200);
  button_3.setClickTicks(200);
  button_4.setClickTicks(200);
  button_5.setClickTicks(200);
  button_6.setClickTicks(200);
  button_7.setClickTicks(200);
  button_8.setClickTicks(200);
  button_9.setClickTicks(200);

  pixels.begin();
  pixels.clear();
  pixels.setBrightness(20);
  pixels.show();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    pixels.setPixelColor(0, pixels.Color(0,255,0));
    pixels.show();
  } else {
    pixels.setPixelColor(0, pixels.Color(255,0,0));
    pixels.show();
  }

  button_1.tick();
  button_2.tick();
  button_3.tick();
  button_4.tick();
  button_5.tick();
  button_6.tick();
  button_7.tick();
  button_8.tick();
  button_9.tick();
}