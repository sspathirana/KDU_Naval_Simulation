const int in195 = D8, in131 = D3, in132 = D5, in133 = D6, in138 = D7;
int countD4, countD4_,countD3, countD3_,countD5, countD5_,countD6, countD6_,countD7, countD7_;
void setupToggle(){
    pinMode(in131, INPUT_PULLUP);
    pinMode(in195, INPUT_PULLUP);
    pinMode(in132, INPUT_PULLUP);
    pinMode(in133, INPUT_PULLUP);
    pinMode(in138, INPUT_PULLUP);
}

void scanToggle(){

    if(digitalRead(in138)==LOW ){if(countD7<1)Serial.println("138");countD7++;countD7_=0;delay(20);}
    else if(digitalRead(in138)==HIGH && countD7_<1){Serial.println("538");countD7=0;countD7_++;delay(20);} 

    if(digitalRead(in195)==LOW ){if(countD4<1)Serial.println("195");countD4++;countD4_=0;delay(20);}
    else if(digitalRead(in195)==HIGH && countD4_<1){Serial.println("595");countD4=0;countD4_++;delay(20);}

    if(digitalRead(in131)==LOW ){if(countD3<1)Serial.println("131");countD3++;countD5_=0;delay(20);}
    else if(digitalRead(in132)==LOW && countD5<1){Serial.println("132");countD5_=0;countD5++;delay(20);}
    else if(digitalRead(in132)==HIGH && digitalRead(in131)==HIGH && countD5_<1){Serial.println("532");countD5=0;countD3=0;countD5_++;delay(200);} 

    if(digitalRead(in133)==LOW ){if(countD6<1)Serial.println("133");countD6++;countD6_=0;delay(20);}
    else if(digitalRead(in133)==HIGH && countD6_<1){Serial.println("533");countD6=0;countD6_++;delay(20);}
   
}