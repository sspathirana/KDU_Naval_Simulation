#include <Arduino.h>
#include "toggleSwitch.h"
#include "oled_display.h"
void setup() {
  Serial.begin(115200);// put your setup code here, to run once:
  setupOled();
  setupToggle();

}

void loop() {
  scanToggle();
  // Serial.println("ESP-4");// put your main code here, to run repeatedly:
  // delay(2000);
}
