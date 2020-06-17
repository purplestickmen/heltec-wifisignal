#include "Arduino.h"
#include "WifiStrength.h"
#include "heltec.h" // alias for `#include "SSD1306Wire.h"`
#include <ESP8266WiFi.h>

#ifdef DEBUG_ESP_PORT
#define DEBUG_MSG(...) DEBUG_ESP_PORT.printf( __VA_ARGS__ )
#else
#define DEBUG_MSG(...)
#endif

WifiStrength::WifiStrength(int x,int y) {
    this->signalLocationX = x;
    this->signalLocationY = y;
}

void WifiStrength::showStrength() {

   long signalStrength = WiFi.RSSI();
    _debug = "DEBUG Signal Strength:" + signalStrength;
    DEBUG_MSG("_debug");

    switch (signalStrength) {
      case -100 ... -70:
        Serial.println("Bad Signal strength");
        drawSignalBar(2); //BAD - second bar
        break;
      case -69 ... -60:
        Serial.println("Good Signal strength");
        drawSignalBar(3); // GOOD - third bar
        break;
      case -59 ...-44:
        Serial.println("Excellent Signal strength");
        drawSignalBar(4); // Excellent - fourth bar
        break;
      default:
        Serial.println("none");
        drawSignalBar(1); // Really BAD or none - first bar
    }

}


//Draws a specified barNumber. Lower bars are additionally filled with higher bars outlined
void WifiStrength::drawSignalBar(int barNumber) {
Serial.println("drawSignalBar");
  //draw lower bars as filled
  for (int i=1;i<=barNumber;i++) {
    drawSignalBarFilled(i);
  }  

  //draw higher bars as outlines
  for (int i=barNumber+1;i<=NUM_BARS;i++) {
    drawSignalBarOutline(i);
  }  

}

//Draw the signal strength bar filled indicating the current reception level
void WifiStrength::drawSignalBarFilled(int barNumber) {
  
  //reset colour and draw in white
  Heltec.display->setColor(WHITE);
  Heltec.display->fillRect(signalLocationX+(barNumber*sizeWidthOffset),signalLocationY-(barNumber*sizeHeightOffset),signalBarWidth,barNumber*sizeHeightOffset);
}

//Draw the signal strength bar filled indicating the potential reception level
void WifiStrength::drawSignalBarOutline(int barNumber) {

  //remove previous fill if present by drawing black 
  Heltec.display->setColor(BLACK);
  Heltec.display->fillRect(signalLocationX+(barNumber*sizeWidthOffset),signalLocationY-(barNumber*sizeHeightOffset),signalBarWidth,barNumber*sizeHeightOffset);
  //reset colour and draw in white
  Heltec.display->setColor(WHITE);
  Heltec.display->drawRect(signalLocationX+(barNumber*sizeWidthOffset),signalLocationY-(barNumber*sizeHeightOffset),signalBarWidth,barNumber*sizeHeightOffset);
}



