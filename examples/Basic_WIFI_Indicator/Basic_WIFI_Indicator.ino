/*
  WIFI Strength usage

  Traditional indicator that shows the current WIFI strength using graduated
  bars at a specific location.
 
*/

#include <WifiStrength.h>
#include <ESP8266WiFi.h>

WifiStrength wifiSignal(90,12);

//WiFI Credentials
const char* ssid     = "XXXX";
const char* password = "XXXX";

void setup() {
  
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Serial Enable*/);
  Heltec.display->init();
  Heltec.display->flipScreenVertically();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
}

void loop() {

    wifiSignal.showStrength();
    
    Heltec.display->display();
    
    delay(2000);
}
