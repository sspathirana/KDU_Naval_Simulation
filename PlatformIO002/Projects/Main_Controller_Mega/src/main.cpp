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
long lastUpdateTime = 0, lastUpdateTime2 = 0;
long updateInterval = 1000;

long hundred = 100;

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
  if(syncVar==2){
    syncVar=0;
    lastUpdateTime2 = millis(); 
  }
  if (millis() - lastUpdateTime2 > hundred) {
    // Serial.println("Main Controller");// put your main code here, to run repeatedly:    
    syncVar=4;
    neo[268]='L';
    lastUpdateTime2 = millis(); // delay(10000); // Send data every minute
  }

  if (millis() - lastUpdateTime > updateInterval) {
    // Serial.println("Main Controller");// put your main code here, to run repeatedly:    

    if(actuator==4){buzzSpeed(); send_actuator();}
    lastUpdateTime = millis(); // delay(10000); // Send data every minute
  }
  neoPattern();
  mainScan();
  if(mainSwitch==4 || neo[265] =='G' || neo[266] =='G' || neo[267] =='G'){
    serchMatrix();
    scanPush();
    tank();
    readSerial();
    scanToggle();
    // Serial.println("okay");
  }
  else if(mainSwitch==8 && neo[265] =='R' && neo[266] =='R' && neo[267] =='R'){
    shoreConnectionErr();
    mainSwitch=0;
    // Serial.println("fail");
  }
  if(alarm_on==4) alarm();
  else digitalWrite(buzzer,HIGH);
}
