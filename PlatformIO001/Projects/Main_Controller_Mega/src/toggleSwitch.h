const int in185 = 2, in203 = 3, in179 = 4, in1 = 5, in125 = 8, in154 = 9, in139 = 10, /* in325 = 11, */ in140 = 13, in71 = A10, in51 = A14;

int countA[15], count_[15];
 
void setupToggle(){
    for(int i=0; i<15; i++)count_[i]=9;
    pinMode(in185, INPUT_PULLUP);
    pinMode(in203, INPUT_PULLUP);
    pinMode(in179, INPUT_PULLUP);
    pinMode(in1, INPUT_PULLUP);
    pinMode(in125, INPUT_PULLUP);
    pinMode(in154, INPUT_PULLUP);
    pinMode(in139, INPUT_PULLUP);
    // pinMode(in325, INPUT_PULLUP);
    pinMode(in140, INPUT_PULLUP);
    pinMode(in71, INPUT_PULLUP);
    pinMode(in51, INPUT_PULLUP);
    neo[216] = 'R';neo[288] = 'R';neo[287] = 'R';
}

void scanToggle(){
    // if(digitalRead(in149)==LOW ){if(count[0]<5)Serial3.println("149");count[0]++;count_[0]=0;delay(20);}
    // if(digitalRead(in150)==LOW ){if(count[0]<5)Serial3.println("150");count[0]++;count_[0]=0;delay(20);}
    // else if(digitalRead(in149)==HIGH && digitalRead(in150)==HIGH && count_[0]<5){Serial3.println("549");count[0]=0;count_[0]++;delay(20);} 

    if(digitalRead(in185)==LOW ){if(countA[1]<1)Serial.println("185");countA[1]++;neo[216] = 'G';count_[1]=0;delay(20);}
    else if(digitalRead(in185)==HIGH && count_[1]<1){Serial.println("585");neo[216] = 'R';countA[1]=0;count_[1]++;delay(20);} 

    if(digitalRead(in203)==LOW ){if(countA[2]<1)Serial.println("203");countA[2]++;neo[181] = 'B';neo[396] = 'B';count_[2]=0;delay(20);}
    else if(digitalRead(in203)==HIGH && count_[2]<1){Serial.println("603");neo[181] = 'R';neo[396] = 'R';countA[2]=0;count_[2]++;delay(20);} 

    if(digitalRead(in179)==LOW ){if(countA[3]<1)Serial.println("179");countA[3]++;neo[214] = 'B';neo[336] = 'B';count_[3]=0;delay(20);}
    else if(digitalRead(in179)==HIGH && count_[3]<1){Serial.println("579");neo[214] = 'R';neo[336] = 'R';countA[3]=0;count_[3]++;delay(20);} 

    if(digitalRead(in1)==LOW ){if(countA[4]<1)Serial.println("1");countA[4]++;count_[4]=0;delay(20);}
    else if(digitalRead(in1)==HIGH && count_[4]<1){Serial.println("701");countA[4]=0;count_[4]++;delay(20);} 

    if(digitalRead(in125)==LOW ){if(countA[5]<1)Serial.println("125");countA[5]++;neo[323] = 'B';count_[5]=0;delay(20);}
    else if(digitalRead(in125)==HIGH && count_[5]<1){Serial.println("525");neo[323] = 'R';countA[5]=0;count_[5]++;delay(20);} 

    if(digitalRead(in154)==LOW ){if(countA[6]<1)Serial.println("154");countA[6]++;count_[6]=0;delay(20);}
    else if(digitalRead(in154)==HIGH && count_[6]<1){Serial.println("554");countA[6]=0;count_[6]++;delay(20);} 

    if(digitalRead(in139)==LOW ){if(countA[7]<1)Serial.println("139");countA[7]++;neo[288] = 'G';count_[7]=0;delay(20);}
    else if(digitalRead(in139)==HIGH && count_[7]<1){Serial.println("539");neo[288] = 'R';countA[7]=0;count_[7]++;delay(20);} 

    // if(digitalRead(in325)==LOW ){if(countA[8]<1)Serial.println("325");countA[8]++;count_[8]=0;delay(20);}
    // else if(digitalRead(in325)==HIGH && count_[8]<1){Serial.println("725");countA[8]=0;count_[8]++;delay(20);} 

    if(digitalRead(in140)==LOW ){if(countA[9]<1)Serial.println("140");countA[9]++;neo[287] = 'G';count_[9]=0;delay(20);}
    else if(digitalRead(in140)==HIGH && count_[9]<1){Serial.println("540");neo[287] = 'R';countA[9]=0;count_[9]++;delay(20);} 

    if(digitalRead(in71)==LOW ){if(countA[10]<1)Serial.println("71");countA[10]++;neo[294]='G';neo[295]='R'; count_[10]=0;delay(20);}
    else if(digitalRead(in71)==HIGH && count_[10]<1){Serial.println("771");countA[10]=0;neo[295]='G'; neo[294]='R';count_[10]++;delay(20);} 

    if(digitalRead(in51)==LOW ){if(countA[11]<1)Serial.println("51");countA[11]++;count_[11]=0;delay(20);}
    else if(digitalRead(in51)==HIGH && count_[11]<1){Serial.println("751");countA[11]=0;count_[11]++;delay(20);} 

    
 
}