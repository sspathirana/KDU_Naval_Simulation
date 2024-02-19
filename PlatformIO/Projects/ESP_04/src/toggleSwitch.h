const int in121 = D3, in122 = D4, in129 = D5, in130 = D6, in126 = D7;
int countD4, countD4_,countD3, countD3_,countD5, countD5_,countD6, countD6_,countD7, countD7_;
void setupToggle(){
    pinMode(in121, INPUT_PULLUP);
    pinMode(in122, INPUT_PULLUP);
    pinMode(in129, INPUT_PULLUP);
    pinMode(in130, INPUT_PULLUP);
    pinMode(in126, INPUT_PULLUP);
}

void scanToggle(){
    if(digitalRead(in126)==LOW ){if(countD7<1)Serial.println("126");countD7++;countD7_=0;delay(20);}
    else if(digitalRead(in126)==HIGH && countD7_<1){Serial.println("526");countD7=0;countD7_++;delay(20);} 

    if(digitalRead(in121)==LOW ){if(countD3<1)Serial.println("121");countD3++;countD4_=0;delay(20);}
    else if(digitalRead(in122)==LOW && countD4<1){Serial.println("122");countD4_=0;countD4++;delay(20);}
    else if(digitalRead(in122)==HIGH && digitalRead(in121)==HIGH && countD4_<1){Serial.println("522");countD4=0;countD3=0;countD4_++;delay(20);} 

    if(digitalRead(in129)==LOW ){if(countD5<1)Serial.println("129");countD5++;countD6_=0;delay(20);/* display_UP[5] = 0.1; AL_en[5] = 4; */}
    else if(digitalRead(in130)==LOW && countD6<1){Serial.println("130");countD6_=0;countD6++;delay(20);/* display_UP[5] = 0.1; AL_en[5] = 4; */}
    else if(digitalRead(in130)==HIGH && digitalRead(in129)==HIGH && countD6_<1){Serial.println("530");countD6=0;countD5=0;countD6_++;delay(20); /* display_UP[5] = 0; AL_en[5] =0; */} 
    // else if(digitalRead(in130)==LOW)displayAC_auto();
    // else if(digitalRead(in130)==HIGH && digitalRead(in129)==HIGH)displayAC_off();
}