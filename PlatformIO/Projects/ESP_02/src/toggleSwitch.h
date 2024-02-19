const int in180 = D3, in178 = D4, in177 = D5, in187 = D6, in188 = D7;
int countD4, countD4_,countD3, countD3_,countD5, countD5_,countD6, countD6_,countD7, countD7_;
void setupToggle(){
    pinMode(in180, INPUT_PULLUP);
    pinMode(in178, INPUT_PULLUP);
    pinMode(in177, INPUT_PULLUP);
    pinMode(in187, INPUT_PULLUP);
    pinMode(in188, INPUT_PULLUP);
}

void scanToggle(){
    if(digitalRead(in180)==LOW ){if(countD3<5)Serial.println("180");countD3++;countD3_=0;delay(20);}
    else if(digitalRead(in180)==HIGH && countD3_<5){Serial.println("580");countD3=0;countD3_++;delay(20);} 

    if(digitalRead(in178)==LOW ){if(countD4<5)Serial.println("178");countD4++;countD5_=0;delay(20);}
    else if(digitalRead(in177)==LOW && countD5<5){Serial.println("177");countD5_=0;countD5++;delay(20);}
    else if(digitalRead(in177)==HIGH && digitalRead(in178)==HIGH && countD5_<5){Serial.println("577");countD5=0;countD4=0;countD5_++;delay(20);} 

    if(digitalRead(in187)==LOW ){if(countD6<5)Serial.println("187");countD6++;countD6_=0;delay(20);}
    else if(digitalRead(in187)==HIGH && countD6_<5){Serial.println("587");countD6=0;countD6_++;delay(20);} 

    if(digitalRead(in188)==LOW ){if(countD7<5)Serial.println("188");countD7++;countD7_=0;delay(20);}
    else if(digitalRead(in188)==HIGH && countD7_<5){Serial.println("588");countD7=0;countD7_++;delay(20);} 

   
}