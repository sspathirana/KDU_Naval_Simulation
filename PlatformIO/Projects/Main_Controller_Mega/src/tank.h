int expansionTank=0, DOserTank=0, HFOserTank=0, FOsettlingT1=0, FOsettlingT2=0, 
DOdeepTank=0, HFOdeepTank=0, HFOportTank=0, HFOcenterTank=0, HFOstbdTank=0, refilTank=0, 
bilgeTank=0, hotWell=0, slugeTank=0, drainTank=0, dirtyLubeOilTank=0, MEoilTank1=0, MEoilTank2=0, 
DGoilTank=0, COserTank=0, COtank=0;

int hand_pump=0;

unsigned long tankTime = 0;  // the last time the output pin was toggled
unsigned long tankDelay = 2000;    // the debounce time; increase if the output flickers
unsigned long tankDelayHand = 200;    // the debounce time; increase if the output flickers
int count[25];

void tank(){
    if(expansionTank==4 and neo[383] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill-1");
            tankTime=millis();
            count[0]++;
        }  
        if(count[0]==1) neo[378]='G';
        if(count[0]==2) neo[379]='G';neo[239]='V'; 
        if(count[0]==3) neo[380]='Y'; 
        if(count[0]==4) neo[381]='R'; 
        if(count[0]==5) {neo[382]='R';neo[238]='R'; alarm_on=4;count[0]=0;}
    }

    if(DOserTank==4 and neo[371] == 'G' && neo[21]=='G' && neo[22]=='G'){
        if(millis()-tankTime>tankDelayHand && hand_pump==4){
            Serial.println("fill-2");
            tankTime=millis();
            count[1]++;
            hand_pump=0;
        }  
        if(count[1]==1) neo[377]='G';
        if(count[1]==2) neo[376]='G'; 
        if(count[1]==3) neo[375]='Y'; 
        if(count[1]==4) neo[374]='Y'; 
        if(count[1]==5) neo[373]='R'; 
        if(count[1]==6) {neo[372]='R'; alarm_on=4;count[1]=0;}
    }

    if(DOdeepTank==4 and neo[386] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill-3");
            tankTime=millis();
            count[2]++;
        }  
        if(count[2]==1) neo[22]='G';
        if(count[2]==2) neo[23]='G';
        if(count[2]==3) neo[24]='Y'; 
        if(count[2]==4) neo[25]='Y'; 
        if(count[2]==5) neo[26]='R'; 
        if(count[2]==6) {neo[27]='R'; alarm_on=4;count[2]=0;}
    }

     if(HFOdeepTank==4 and neo[57] == 'G' && neo[55] == 'G' && neo[56] == 'G' && neo[64] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[3]++;
        }  
        if(count[3]==1) neo[63]='G';
        if(count[3]==2) neo[62]='G';
        if(count[3]==3) neo[61]='Y'; 
        if(count[3]==4) neo[60]='Y'; 
        if(count[3]==5) neo[59]='R'; 
        if(count[3]==6) {neo[58]='R'; alarm_on=4;count[3]=0;}
     }
     if(HFOstbdTank==4 and neo[66] == 'G' && neo[64] == 'G' && neo[56] == 'G' && neo[55] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[4]++;
        }  
        if(count[4]==1) neo[70]='G';
        if(count[4]==2) neo[69]='G';
        if(count[4]==3) neo[68]='Y';  
        if(count[4]==4) {neo[67]='R'; alarm_on=4;count[4]=0;}
     }

     if(refilTank==4 and neo[2] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[5]++;
        }  
        if(count[5]==1) neo[7]='G';
        if(count[5]==2) neo[6]='G';
        if(count[5]==3) neo[5]='Y';  
        if(count[5]==4) {neo[4]='R'; alarm_on=4;count[5]=0;}
     }

     if(MEoilTank2==4 and neo[74] == 'G' && neo[98] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[6]++;
        }  
        if(count[6]==1) neo[83]='G';
        if(count[6]==2) neo[84]='G';
        if(count[6]==3) neo[85]='Y';  
        if(count[6]==4) {neo[86]='R';neo[177]='R'; alarm_on=4;count[6]=0;}
     }

     if(DGoilTank==4 and neo[87] == 'G' && neo[98] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[7]++;
        }  
        if(count[7]==1) neo[91]='G';
        if(count[7]==2) neo[90]='G';
        if(count[7]==3) neo[89]='Y';  
        if(count[7]==4) {neo[88]='R';neo[178]='R'; alarm_on=4;count[7]=0;}
     }

     if(MEoilTank1==4 and neo[97] == 'G' && neo[98] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[8]++;
        }  
        if(count[8]==1) neo[93]='G';
        if(count[8]==2) neo[94]='G';
        if(count[8]==3) neo[95]='Y';  
        if(count[8]==4) {neo[96]='R';neo[179]='R'; alarm_on=4;count[8]=0;}
     }

    if(FOsettlingT2==4 and neo[39] == 'G' && neo[54] == 'G' && (neo[46] == 'G' || neo[65] == 'G') && neo[52] == 'G' && (neo[45] == 'G' || neo[53] == 'G') && (neo[47] == 'G' || neo[70] == 'G')){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[9]++;
        }  
        if(count[9]==1) neo[44]='G';
        if(count[9]==2) neo[43]='G'; 
        if(count[9]==3) neo[42]='Y'; 
        if(count[9]==4) neo[41]='Y'; 
        if(count[9]==5) {neo[40]='R'; alarm_on=4;count[9]=0;}
    }

    if(HFOserTank==4 and neo[363] == 'G' && neo[340] == 'G' && neo[339] == 'G' && neo[28] == 'G' && neo[29] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[10]++;
        }  
        if(count[10]==1) neo[357]='G';
        if(count[10]==2) neo[358]='G'; 
        if(count[10]==3) neo[359]='Y'; 
        if(count[10]==4) neo[360]='Y'; 
        if(count[10]==5) neo[361]='R'; 
        if(count[10]==6) {neo[362]='R'; alarm_on=4;count[10]=0;}
    }

    if(COtank==4 and neo[355] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[11]++;
        }  
        if(count[11]==1) neo[349]='G';
        if(count[11]==2) neo[350]='G'; 
        if(count[11]==3) neo[351]='Y'; 
        if(count[11]==4) neo[352]='Y'; 
        if(count[11]==5) neo[353]='R'; 
        if(count[11]==6) {neo[354]='R';neo[183]='R'; alarm_on=4;count[11]=0;}
    }

    if(FOsettlingT1==4 and neo[34] == 'G' && neo[54] == 'G' && (neo[46] == 'G' || neo[65] == 'G') && neo[52] == 'G' && (neo[45] == 'G' || neo[53] == 'G') && (neo[47] == 'G' || neo[70] == 'G')){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[12]++;
        }  
        if(count[12]==1) neo[29]='G';
        if(count[12]==2) neo[30]='G'; 
        if(count[12]==3) neo[31]='Y'; 
        if(count[12]==4) neo[32]='Y'; 
        if(count[12]==5) {neo[33]='R'; alarm_on=4;count[12]=0;}
    }

    if(HFOportTank==4 and neo[20] == 'G' && neo[64] == 'G' && neo[56] == 'G' && neo[55] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[13]++;
        }  
        if(count[13]==1) neo[16]='G';
        if(count[13]==2) neo[17]='G'; 
        if(count[13]==3) neo[18]='Y'; 
        if(count[13]==4) {neo[19]='R'; alarm_on=4;count[13]=0;}
    }

    if(HFOcenterTank==4 and neo[51] == 'G' && neo[64] == 'G' && neo[56] == 'G' && neo[55] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill");
            tankTime=millis();
            count[14]++;
        }  
        if(count[14]==1) neo[47]='G';
        if(count[14]==2) neo[48]='G'; 
        if(count[14]==3) neo[49]='Y'; 
        if(count[14]==4) {neo[50]='R'; alarm_on=4;count[14]=0;}
    }

     if(hotWell==4 and neo[3] == 'G' && neo[7] == 'G' && neo[1] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill-1");
            tankTime=millis();
            count[16]++;
        }  
        if(count[16]==1) neo[400]='G';
        if(count[16]==2) neo[399]='G';
        if(count[16]==3) neo[398]='Y'; 
        if(count[16]==4) neo[397]='R'; 
        if(count[16]==5) {neo[396]='R'; alarm_on=4;count[16]=0;}
    }
    else if(neo[1] == 'G' && neo[3] == 'R'){
        if(millis()-tankTime>tankDelay){
            alarm_on = 4;
            tankTime=millis();
        }  
    }
    else if(neo[1] == 'G' && neo[3] == 'G' && neo[7] != 'G'){
        if(millis()-tankTime>tankDelay){
            alarm_on = 4;
            tankTime=millis();
        }  
    }

    if(COserTank==4 and neo[348] == 'G' && neo[349] == 'G' && neo[356] == 'G'){
        if(millis()-tankTime>tankDelay){
            Serial.println("fill-1");
            tankTime=millis();
            count[17]++;
        }  
        if(count[17]==1) neo[347]='G';
        if(count[17]==2) neo[346]='G';
        if(count[17]==3) neo[345]='Y'; 
        if(count[17]==4) neo[344]='Y'; 
        if(count[17]==5) neo[343]='R'; 
        if(count[17]==6) {neo[342]='R'; alarm_on=4;count[17]=0;}
    }
    else if(neo[348] == 'G' && neo[356] == 'R'){
        if(millis()-tankTime>tankDelay){
            alarm_on = 4;
            tankTime=millis();
        }  
    }
    else if(neo[348] == 'G' && neo[356] == 'G' && neo[349] != 'G'){
        if(millis()-tankTime>tankDelay){
            alarm_on = 4;
            tankTime=millis();
        }  
    }
}
