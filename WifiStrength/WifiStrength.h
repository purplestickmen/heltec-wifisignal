
#ifndef WifiStrength_h
#define WifiStrength_h

#include "Arduino.h"
#include "heltec.h" // alias for `#include "SSD1306Wire.h"`

class WifiStrength
{
  public:
    WifiStrength(int x,int y);

    //draws a specific signal strength indicator
    void drawSignalBar(int barNumber);

    //shows the signal strength indicator
    void showStrength();
  protected:
    void drawSignalBarFilled(int barNumber);
    void drawSignalBarOutline(int barNumber);
    
    //location for the Signal indicator
    unsigned int signalLocationX;
    unsigned int signalLocationY;

    //difference of height between adjacent bars
    const unsigned int sizeHeightOffset = 3;

    //the spacing between bars
    const unsigned int sizeWidthOffset = 7;

    //the width of the bars
    const unsigned int signalBarWidth = 6;

    //the number of bars that should be drawn
    int NUM_BARS = 4;

    //used for debugging
    String _debug;
};

#endif


