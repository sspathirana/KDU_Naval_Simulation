#include <Arduino.h>
#include "serial_comm.h"
#include "toggleSwitch.h"
#include "oled_display.h"

long lastUpdateTime = 0;
long updateInterval = 200;
long lastUpdateTime2 = 0;
long updateInterval2 = 1500;

void setup() {
  Serial.begin(115200);// put your setup code here, to run once:
  setupOled();
  setupToggle();

}

void loop() {
  scanToggle();
  if (millis() - lastUpdateTime > updateInterval) {

    diplayLO_sump_level();
    lastUpdateTime = millis(); // delay(10000); // Send data every minute
  }
  if (millis() - lastUpdateTime2 > updateInterval2) {

    diplayLO_aft_PSI();
    diplayLO_bef_PSI();
    display_LO_aft_trans1();
    display_LO_aft_trans2();
    display_DG_SW_bef_CIR();
    diplaySW_bef_CIR_TEMP();
    display_SW_bef_CIR_PRS();
    lastUpdateTime2 = millis(); // delay(10000); // Send data every minute
  }

  readSerial();
  // Serial.println("ESP-4");// put your main code here, to run repeatedly:
  // delay(2000);
}
