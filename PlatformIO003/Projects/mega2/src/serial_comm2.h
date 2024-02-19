String readString;

void setupSerComm(){
    Serial1.begin(115200);
    Serial2.begin(115200);
    Serial3.begin(115200);
}

void checkData(){
    Serial1.println("ESP");
}

void readSerial(){

    while (Serial1.available()){
        delay(1);
        if(Serial1.available()>0){
            char esp4 = Serial1.read();
            Serial.println(esp4);
            Serial3.print(esp4);
            if (isControl(esp4)){
                break;
            }
        }
    }

    while (Serial2.available()){
        delay(1);
        if(Serial2.available()>0){
            char esp3 = Serial2.read();
            Serial3.print(esp3);
            if (isControl(esp3)){
                break;
            }
        }
    }
    while (Serial3.available()){
        delay(1);
        if(Serial3.available()>0){
            char mega1 = Serial3.read();
            Serial.print(mega1);
            Serial1.print(mega1);
            if (isControl(mega1)){
                break;
            }
        }
    }
}

