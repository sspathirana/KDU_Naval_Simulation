const int in202 = D3, in167 = D4, in198 = D5, in199 = D6, in164 = D7;
int countD4, countD4_,countD3, countD3_,countD5, countD5_,countD6, countD6_,countD7, countD7_;
void setupToggle(){
    pinMode(in202, INPUT_PULLUP);
    pinMode(in198, INPUT_PULLUP);
    pinMode(in167, INPUT_PULLUP);
    pinMode(in199, INPUT_PULLUP);
    pinMode(in164, INPUT_PULLUP);
}

void scanToggle(){

    if(digitalRead(in202)==LOW ){if(countD3<5)Serial.println("202");countD3++;countD3_=0;delay(20);}
    else if(digitalRead(in202)==HIGH && countD3_<5){Serial.println("602");countD3=0;countD3_++;delay(20);} 

    if(digitalRead(in198)==LOW ){if(countD5<5)Serial.println("198");countD5++;countD6_=0;delay(20);}
    else if(digitalRead(in199)==LOW && countD6<5){Serial.println("199");countD6_=0;countD6++;delay(20);}
    else if(digitalRead(in199)==HIGH && digitalRead(in198)==HIGH && countD6_<5){Serial.println("599");countD6=0;countD5=0;countD6_++;delay(20);} 

    if(digitalRead(in164)==LOW ){if(countD7<5)Serial.println("164");countD7++;countD7_=0;delay(20);}
    else if(digitalRead(in164)==HIGH && countD7_<5){Serial.println("564");countD7=0;countD7_++;delay(20);} 

    if(digitalRead(in167)==LOW ){if(countD4<5)Serial.println("167");countD4++;countD4_=0;delay(20);}
    else if(digitalRead(in167)==HIGH && countD4_<5){Serial.println("567");countD4=0;countD4_++;delay(20);} 

}