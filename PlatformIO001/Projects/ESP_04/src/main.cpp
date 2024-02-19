#include <Arduino.h>
#include "oled_display.h"
#include "toggleSwitch.h"
#include "serial_Comm.h"
long lastUpdateTime = 0;
long updateInterval = 600;

void setup() {
  Serial.begin(115200);// put your setup code here, to run once:
  setupToggle();
  setupOled();
}

void loop() {

  if (millis() - lastUpdateTime > updateInterval) {
    displayAR_on();
    displayAR2_on();
    displayDGEN_on();

    lastUpdateTime = millis(); // delay(10000); // Send data every minute
  }
  readSerial();



  scanToggle();

  // Serial.println("ESP-4");// put your main code here, to run repeatedly:
  // delay(2000);
}
