const int speed = A1, buzzer = 7;
unsigned long previousMillis=0;  // the last time the output pin was toggled
const long buzzerDelay = 250;    // the debounce time; increase if the output flickers
int speed_value=0;
void setupBuzzSpeed(){
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer,HIGH);
}

void buzzSpeed(){
  speed_value = analogRead(speed);
  if(speed_value>1000)alarm_on=4; else alarm_on =0;
  // MEP=speed_value/4;
  // // Serial.println(MEP);
  // RPM = MEP/2;
  // Serial.println(RPM);
  // if(speed_value<500)digitalWrite(buzzer,HIGH);
  // else digitalWrite(buzzer, LOW);

}

void alarm(){
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= buzzerDelay){
    previousMillis = currentMillis;
    Serial.println("ON");
    if(digitalRead(buzzer) == HIGH){
      digitalWrite(buzzer,LOW);
      Serial.println("ON222");
    }
    else{
      digitalWrite(buzzer,HIGH);
      Serial.println("OFF");
    }
  }
}