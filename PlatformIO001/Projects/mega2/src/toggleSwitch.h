const int _in149 = A0, _in150 = A1, _in156 = A2, _in155 = A3, _in157 = A4, _in158 = A5, _in151 = A6, _in152 = A7, _in159 = A8, _in160 = A9, _in145 = A10, _in146 = A11, 
_in147 = A12, _in148 = A13, _in163 = A14, _in164 = A15, _in128 = 2, _in127 = 3, _in134 = 4, _in135 = 5, _in137 = 6, _in136 = 7, _in165 = 8, _in166 = 9, _in200 = 10, _in201 = 11, 
_in168 = 12, _in169 = 13, _in124 = 22, _in123 = 23, _in186 = 24, _in175 = 25, _in176 = 26, _in162 = 27, _in161 = 28, _in144 = 29, _in196 = 30, _in143 = 31, _in192 = 32, _in197 = 33, 
_in142 = 34, _in191 = 35, _in141 = 36, _in207 = 37, _in205 = 38, _in204 = 39, _in206 = 40, _in194 = 41, _in193 = 42, _in183 = 43, _in184 = 44, _in182 = 45, _in181 = 46, _in170 = 47, 
_in174 = 48, _in173 = 49, _in171 = 50, _in172 = 51, _in189 = 52, _in190 = 53/* , in200 = D4, in201 = D4, in202 = D4, in203 = D4, in204 = D4, in205 = D4, in206 = D4, in207 = D4 */;

int count[70], count_[70];
 
void setupToggle(){
    for(int i=0; i<70; i++)count_[i]=9;
    pinMode(_in149, INPUT_PULLUP);
    pinMode(_in150, INPUT_PULLUP);
    pinMode(_in156, INPUT_PULLUP);
    pinMode(_in155, INPUT_PULLUP);
    pinMode(_in157, INPUT_PULLUP);
    pinMode(_in158, INPUT_PULLUP);
    pinMode(_in151, INPUT_PULLUP);
    pinMode(_in152, INPUT_PULLUP);
    pinMode(_in159, INPUT_PULLUP);
    pinMode(_in160, INPUT_PULLUP);
    pinMode(_in145, INPUT_PULLUP);
    pinMode(_in146, INPUT_PULLUP);
    pinMode(_in147, INPUT_PULLUP);
    pinMode(_in148, INPUT_PULLUP);
    pinMode(_in163, INPUT_PULLUP);
    pinMode(_in164, INPUT_PULLUP);
    pinMode(_in128, INPUT_PULLUP);
    pinMode(_in127, INPUT_PULLUP);
    pinMode(_in134, INPUT_PULLUP);
    pinMode(_in135, INPUT_PULLUP);
    pinMode(_in137, INPUT_PULLUP);
    pinMode(_in136, INPUT_PULLUP);
    pinMode(_in165, INPUT_PULLUP);
    pinMode(_in166, INPUT_PULLUP);
    pinMode(_in200, INPUT_PULLUP);
    pinMode(_in201, INPUT_PULLUP);
    pinMode(_in168, INPUT_PULLUP);
    pinMode(_in169, INPUT_PULLUP);
    pinMode(_in124, INPUT_PULLUP);
    pinMode(_in123, INPUT_PULLUP);
    pinMode(_in186, INPUT_PULLUP);
    pinMode(_in175, INPUT_PULLUP);
    pinMode(_in176, INPUT_PULLUP);
    pinMode(_in162, INPUT_PULLUP);
    pinMode(_in161, INPUT_PULLUP);
    pinMode(_in144, INPUT_PULLUP);
    pinMode(_in196, INPUT_PULLUP);
    pinMode(_in143, INPUT_PULLUP);
    pinMode(_in192, INPUT_PULLUP);
    pinMode(_in197, INPUT_PULLUP);
    pinMode(_in142, INPUT_PULLUP);
    pinMode(_in191, INPUT_PULLUP);
    pinMode(_in141, INPUT_PULLUP);
    pinMode(_in207, INPUT_PULLUP);
    pinMode(_in205, INPUT_PULLUP);
    pinMode(_in204, INPUT_PULLUP);
    pinMode(_in206, INPUT_PULLUP);
    pinMode(_in194, INPUT_PULLUP);
    pinMode(_in193, INPUT_PULLUP);
    pinMode(_in183, INPUT_PULLUP);
    pinMode(_in184, INPUT_PULLUP);
    pinMode(_in182, INPUT_PULLUP);
    pinMode(_in181, INPUT_PULLUP);
    pinMode(_in170, INPUT_PULLUP);
    pinMode(_in174, INPUT_PULLUP);
    pinMode(_in173, INPUT_PULLUP);
    pinMode(_in171, INPUT_PULLUP);
    pinMode(_in172, INPUT_PULLUP);
    pinMode(_in189, INPUT_PULLUP);
    pinMode(_in190, INPUT_PULLUP);
    
}

void scanToggle(){
    if(digitalRead(_in149)==LOW ){if(count[0]<5)Serial3.println("149");count[0]++;count_[0]=0;delay(20);}
    if(digitalRead(_in150)==LOW ){if(count[0]<5)Serial3.println("150");count[0]++;count_[0]=0;delay(20);}
    else if(digitalRead(_in149)==HIGH && digitalRead(_in150)==HIGH && count_[0]<5){Serial3.println("549");count[0]=0;count_[0]++;delay(20);} 

    if(digitalRead(_in155)==LOW ){if(count[3]<5){Serial3.println("155");count[3]++;}count_[3]=0;delay(20);}
    else if(digitalRead(_in156)==LOW ){if(count_[3]<5)Serial3.println("156");count_[3]++;count[3]=0;delay(20);}
    else if(digitalRead(_in157)==LOW ){if(count[3]<5)Serial3.println("157");count[3]++;count_[3]=0;delay(20);}
    else if(digitalRead(_in158)==LOW ){if(count_[3]<5)Serial3.println("158");count_[3]++;count[3]=0;delay(20);}

    if(digitalRead(_in151)==LOW ){if(count[6]<5)Serial3.println("151");count[6]++;count_[6]=0;delay(20);}
    if(digitalRead(_in152)==LOW ){if(count[6]<5)Serial3.println("152");count[6]++;count_[6]=0;delay(20);}
    else if(digitalRead(_in151)==HIGH && digitalRead(_in152)==HIGH && count_[6]<5){Serial3.println("551");count[6]=0;count_[6]++;delay(20);} 

    if(digitalRead(_in159)==LOW ){if(count[8]<5)Serial3.println("159");count[8]++;count_[8]=0;delay(20);}
    if(digitalRead(_in160)==LOW ){if(count[8]<5)Serial3.println("160");count[8]++;count_[8]=0;delay(20);}
    else if(digitalRead(_in159)==HIGH && digitalRead(_in160)==HIGH && count_[8]<5){Serial3.println("559");count[8]=0;count_[8]++;delay(20);} 

    if(digitalRead(_in145)==LOW ){if(count[10]<5)Serial3.println("145");count[10]++;count_[10]=0;delay(20);}
    if(digitalRead(_in146)==LOW ){if(count[10]<5)Serial3.println("146");count[10]++;count_[10]=0;delay(20);}
    else if(digitalRead(_in146)==HIGH && digitalRead(_in145)==HIGH && count_[10]<5){Serial3.println("545");count[10]=0;count_[10]++;delay(20);} 

    
    if(digitalRead(_in147)==LOW ){if(count[12]<5)Serial3.println("147");count[12]++;count_[12]=0;delay(20);}
    if(digitalRead(_in148)==LOW ){if(count[12]<5)Serial3.println("148");count[12]++;count_[12]=0;delay(20);}
    else if(digitalRead(_in147)==HIGH && digitalRead(_in148)==HIGH && count_[12]<5){Serial3.println("547");count[12]=0;count_[12]++;delay(20);} 


    if(digitalRead(_in163)==LOW ){if(count[14]<5)Serial3.println("163");count[14]++;count_[14]=0;delay(20);}
    if(digitalRead(_in164)==LOW ){if(count[14]<5)Serial3.println("164");count[14]++;count_[14]=0;delay(20);}
    else if(digitalRead(_in164)==HIGH && digitalRead(_in163)==HIGH && count_[14]<5){Serial3.println("563");count[14]=0;count_[14]++;delay(20);} 

    if(digitalRead(_in128)==LOW ){if(count[16]<5)Serial3.println("128");count[16]++;count_[16]=0;delay(20);}
    if(digitalRead(_in127)==LOW ){if(count[16]<5)Serial3.println("127");count[16]++;count_[16]=0;delay(20);}
    else if(digitalRead(_in128)==HIGH && digitalRead(_in127)==HIGH && count_[16]<5){Serial3.println("527");count[16]=0;count_[16]++;delay(20);} 

    if(digitalRead(_in134)==LOW ){if(count[18]<5)Serial3.println("134");count[18]++;count_[18]=0;delay(20);}
    if(digitalRead(_in135)==LOW ){if(count[18]<5)Serial3.println("135");count[18]++;count_[18]=0;delay(20);}
    else if(digitalRead(_in134)==HIGH && digitalRead(_in135)==HIGH && count_[18]<5){Serial3.println("534");count[18]=0;count_[18]++;delay(20);} 

    if(digitalRead(_in137)==LOW ){if(count[21]<5)Serial3.println("137");count[21]++;count_[21]=0;delay(20);}
    if(digitalRead(_in136)==LOW ){if(count[21]<5)Serial3.println("136");count[21]++;count_[21]=0;delay(20);}
    else if(digitalRead(_in137)==HIGH && digitalRead(_in136)==HIGH && count_[21]<5){Serial3.println("536");count[21]=0;count_[21]++;delay(20);}  

    if(digitalRead(_in165)==LOW ){if(count[22]<5)Serial3.println("165");count[22]++;count_[22]=0;delay(20);}
    if(digitalRead(_in166)==LOW ){if(count[22]<5)Serial3.println("166");count[22]++;count_[22]=0;delay(20);}
    else if(digitalRead(_in165)==HIGH && digitalRead(_in166)==HIGH && count_[22]<5){Serial3.println("565");count[22]=0;count_[22]++;delay(20);}  

    if(digitalRead(_in200)==LOW ){if(count[24]<5)Serial3.println("200");count[24]++;count_[24]=0;delay(20);}
    if(digitalRead(_in201)==LOW ){if(count[24]<5)Serial3.println("201");count[24]++;count_[24]=0;delay(20);}
    else if(digitalRead(_in200)==HIGH && digitalRead(_in201)==HIGH && count_[24]<5){Serial3.println("600");count[24]=0;count_[24]++;delay(20);}  

    if(digitalRead(_in168)==LOW ){if(count[26]<5)Serial3.println("168");count[26]++;count_[26]=0;delay(20);}
    if(digitalRead(_in169)==LOW ){if(count[26]<5)Serial3.println("169");count[26]++;count_[26]=0;delay(20);}
    else if(digitalRead(_in168)==HIGH && digitalRead(_in169)==HIGH && count_[26]<5){Serial3.println("568");count[26]=0;count_[26]++;delay(20);} 

    if(digitalRead(_in124)==LOW ){if(count[28]<5)Serial3.println("124");count[28]++;count_[28]=0;delay(20);}
    if(digitalRead(_in123)==LOW ){if(count[28]<5)Serial3.println("123");count[28]++;count_[28]=0;delay(20);}
    else if(digitalRead(_in124)==HIGH && digitalRead(_in123)==HIGH && count_[28]<5){Serial3.println("523");count[28]=0;count_[28]++;delay(20);} 

    if(digitalRead(_in186)==LOW ){if(count[30]<5)Serial3.println("186");count[30]++;count_[30]=0;delay(20);}
    else if(digitalRead(_in186)==HIGH && count_[30]<5){Serial3.println("586");count[30]=0;count_[30]++;delay(20);} 

    if(digitalRead(_in175)==LOW ){if(count[31]<5)Serial3.println("175");count[31]++;count_[31]=0;delay(20);}
    if(digitalRead(_in176)==LOW ){if(count[31]<5)Serial3.println("176");count[31]++;count_[31]=0;delay(20);}
    else if(digitalRead(_in175)==HIGH && digitalRead(_in176)==HIGH && count_[31]<5){Serial3.println("575");count[31]=0;count_[31]++;delay(20);} 


    if(digitalRead(_in161)==LOW ){if(count[33]<5)Serial3.println("161");count[33]++;count_[33]=0;delay(20);}
    if(digitalRead(_in162)==LOW ){if(count[33]<5)Serial3.println("162");count[33]++;count_[33]=0;delay(20);}
    else if(digitalRead(_in162)==HIGH && digitalRead(_in161)==HIGH && count_[33]<5){Serial3.println("561");count[33]=0;count_[33]++;delay(20);} 

    if(digitalRead(_in144)==LOW ){if(count[35]<5)Serial3.println("144");count[35]++;count_[35]=0;delay(20);}
    if(digitalRead(_in143)==LOW ){if(count[35]<5)Serial3.println("143");count[35]++;count_[35]=0;delay(20);}
    else if(digitalRead(_in143)==HIGH && digitalRead(_in144)==HIGH && count_[35]<5){Serial3.println("543");count[35]=0;count_[35]++;delay(20);} 

    if(digitalRead(_in196)==LOW ){if(count[36]<5)Serial3.println("196");count[36]++;count_[36]=0;delay(20);}
    if(digitalRead(_in197)==LOW ){if(count[36]<5)Serial3.println("197");count[36]++;count_[36]=0;delay(20);}
    else if(digitalRead(_in197)==HIGH && digitalRead(_in196)==HIGH && count_[36]<5){Serial3.println("596");count[36]=0;count_[36]++;delay(20);} 

    if(digitalRead(_in192)==LOW ){if(count[38]<5)Serial3.println("192");count[38]++;count_[38]=0;delay(20);}
    if(digitalRead(_in191)==LOW ){if(count[38]<5)Serial3.println("191");count[38]++;count_[38]=0;delay(20);}
    else if(digitalRead(_in192)==HIGH && digitalRead(_in191)==HIGH && count_[38]<5){Serial3.println("591");count[38]=0;count_[38]++;delay(20);}

    if(digitalRead(_in141)==LOW ){if(count[40]<5)Serial3.println("141");count[40]++;count_[40]=0;delay(20);}
    if(digitalRead(_in142)==LOW ){if(count[40]<5)Serial3.println("142");count[40]++;count_[40]=0;delay(20);}
    else if(digitalRead(_in141)==HIGH && digitalRead(_in142)==HIGH && count_[40]<5){Serial3.println("541");count[40]=0;count_[40]++;delay(20);} 


    if(digitalRead(_in204)==LOW ){if(count[43]<5){Serial3.println("204");count[43]++;}count_[43]=0;delay(20);}
    else if(digitalRead(_in205)==LOW ){if(count_[43]<5)Serial3.println("205");count_[43]++;count[43]=0;delay(20);}
    else if(digitalRead(_in206)==LOW ){if(count[43]<5)Serial3.println("206");count[43]++;count_[43]=0;delay(20);}
    else if(digitalRead(_in207)==LOW ){if(count_[43]<5)Serial3.println("207");count_[43]++;count[43]=0;delay(20);}

    if(digitalRead(_in194)==LOW ){if(count[47]<5)Serial3.println("194");count[47]++;count_[47]=0;delay(20);}
    if(digitalRead(_in193)==LOW ){if(count[47]<5)Serial3.println("193");count[47]++;count_[47]=0;delay(20);}
    else if(digitalRead(_in194)==HIGH && digitalRead(_in193)==HIGH && count_[47]<5){Serial3.println("593");count[47]=0;count_[47]++;delay(20);}


    if(digitalRead(_in183)==LOW ){if(count[49]<5)Serial3.println("183");count[49]++;count_[49]=0;delay(20);}
    if(digitalRead(_in184)==LOW ){if(count[49]<5)Serial3.println("184");count[49]++;count_[49]=0;delay(20);}
    else if(digitalRead(_in183)==HIGH && digitalRead(_in184)==HIGH && count_[49]<5){Serial3.println("583");count[49]=0;count_[49]++;delay(20);}

    if(digitalRead(_in182)==LOW ){if(count[51]<5)Serial3.println("182");count[51]++;count_[51]=0;delay(20);}
    if(digitalRead(_in181)==LOW ){if(count[51]<5)Serial3.println("181");count[51]++;count_[51]=0;delay(20);}
    else if(digitalRead(_in182)==HIGH && digitalRead(_in181)==HIGH && count_[51]<5){Serial3.println("581");count[51]=0;count_[51]++;delay(20);}

    if(digitalRead(_in170)==LOW ){if(count[53]<5)Serial3.println("170");count[53]++;count_[53]=0;delay(20);}
    else if(digitalRead(_in170)==HIGH && count_[53]<5){Serial3.println("570");count[53]=0;count_[53]++;delay(20);}

    if(digitalRead(_in174)==LOW ){if(count[54]<5)Serial3.println("174");count[54]++;count_[54]=0;delay(20);}
    if(digitalRead(_in173)==LOW ){if(count[54]<5)Serial3.println("173");count[54]++;count_[54]=0;delay(20);}
    else if(digitalRead(_in174)==HIGH && digitalRead(_in173)==HIGH && count_[54]<5){Serial3.println("573");count[54]=0;count_[54]++;delay(20);}

    if(digitalRead(_in171)==LOW ){if(count[56]<5)Serial3.println("171");count[56]++;count_[56]=0;delay(20);}
    if(digitalRead(_in172)==LOW ){if(count[56]<5)Serial3.println("172");count[56]++;count_[56]=0;delay(20);}
    else if(digitalRead(_in171)==HIGH && digitalRead(_in172)==HIGH && count_[56]<5){Serial3.println("571");count[56]=0;count_[56]++;delay(20);}

    if(digitalRead(_in189)==LOW ){if(count[58]<5)Serial3.println("189");count[58]++;count_[58]=0;delay(20);}
    if(digitalRead(_in190)==LOW ){if(count[58]<5)Serial3.println("190");count[58]++;count_[58]=0;delay(20);}
    else if(digitalRead(_in189)==HIGH && digitalRead(_in190)==HIGH && count_[58]<5){Serial3.println("589");count[58]=0;count_[58]++;delay(20);}

    
}
/* void scanToggle(){

    if(digitalRead(in138)==LOW ){if(countD7<5)Serial3.println("138");countD7++;countD7_=0;delay(20);}
    else if(digitalRead(in138)==HIGH && countD7_<5){Serial3.println("538");countD7=0;countD7_++;delay(20);} 

    if(digitalRead(in195)==LOW ){if(countD4<5)Serial3.println("195");countD4++;countD4_=0;delay(20);}
    else if(digitalRead(in195)==HIGH && countD4_<5){Serial3.println("595");countD4=0;countD4_++;delay(20);}

    if(digitalRead(in131)==LOW ){if(countD3<5)Serial3.println("131");countD3++;countD5_=0;delay(20);}
    else if(digitalRead(in132)==LOW && countD5<5){Serial3.println("132");countD5_=0;countD5++;delay(20);}
    else if(digitalRead(in132)==HIGH && digitalRead(in131)==HIGH && countD5_<5){Serial3.println("532");countD5=0;countD3=0;countD5_++;delay(20);} 

    if(digitalRead(in133)==LOW ){if(countD6<5)Serial3.println("133");countD6++;countD6_=0;delay(20);}
    else if(digitalRead(in133)==HIGH && countD6_<5){Serial3.println("533");countD6=0;countD6_++;delay(20);}
   
} */