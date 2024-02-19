#include <Arduino.h>
#include "DFPlayer.h"
#include "oled_display.h"
#include "neo_pixel.h"
#include "toggleSwitch.h"
#include "buzzer_speed.h"
#include "serial_Comm.h"
#include "tank.h"
#include "matrixKey.h"
#include "pushToOff.h"
long lastUpdateTime = 0;
long updateInterval = 1000;

void setup() {
  Serial.begin(115200);
  setupDF();
  setupToggle();
  setupSerComm();
   setupNeo();
  setupPush();
  setupBuzzSpeed();
  setupMatrix();
  setupOled();
  // sei();
}

void loop() {
  if (millis() - lastUpdateTime > updateInterval) {
    // Serial.println("Main Controller");// put your main code here, to run repeatedly:    

    if(actuator==4){buzzSpeed(); send_actuator();}
    lastUpdateTime = millis(); // delay(10000); // Send data every minute
  }
  neoPattern();
  serchMatrix();
  scanPush();
  tank();
  readSerial();
  scanToggle();
  if(alarm_on==4) alarm();
  else digitalWrite(buzzer,HIGH);
}
