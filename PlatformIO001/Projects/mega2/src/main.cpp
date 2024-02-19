#include <Arduino.h>
#include "serial_comm2.h"
#include "toggleSwitch.h"
#include "oled_display.h"

long lastUpdateTime = 0;
long updateInterval = 2000;

void setup() {
  Serial.begin(115200);// put your setup code here, to run once:
  setupOled();
  setupSerComm();// int result = myFunction(2, 3);
  setupToggle();
}

void loop() {
  if (millis() - lastUpdateTime > updateInterval) {
    Serial.println("mega-2");// put your main code here, to run repeatedly:    
    lastUpdateTime = millis(); // delay(10000); // Send data every minute
  }
  
  readSerial();
  scanToggle();
  
}
