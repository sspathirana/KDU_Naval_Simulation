#include <Arduino.h>
#include "serial_Comm.h"
#include "toggleSwitch.h"
#include "oled_display.h"
long lastUpdateTime = 0;
long updateInterval = 50;

void setup() {
  Serial.begin(115200);// put your setup code here, to run once:
  setupOled();
  setupToggle();
}

void loop() {
  if (millis() - lastUpdateTime > updateInterval) {
    // Serial.println("ESP-01");
    displayDG1_on();
    displayDG2_on();
    diplayDG1_current();
    diplayDG2_current();
    diplayDG2_voltage();
    diplayDG1_voltage();
    diplaySG_voltage();
    diplaySG_current();
/*     displayAR_on();
    displayAR2_on();
    displayDGEN_on();
 */
    lastUpdateTime = millis(); // delay(10000); // Send data every minute
  }
  scanToggle();
  readSerial();
  // Serial.println("ESP-4");// put your main code here, to run repeatedly:
  // delay(2000);
}
