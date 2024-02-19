/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
#include <Toggle.h>

const byte ROWS = 10; //four rows
const byte COLS = 10; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {14,70,69,68,67,66,65,64,16,2},
  {37,40,75,74,38,39,52,48,20,53},
  {21,15,5,44,45,36,6,12,34,76},
  {33,13,35,3,4,43,77,10,11,55},
  {26,29,30,25,63,60,72,73,50,49},
  {59,58,31,54,32,27,56,57,61,62},
  {18,24,23,17,28,22,78,79,80,81},
  {86,87,88,89,90,91,82,83,84,85},
  {81,82,92,84,93,94,87,95,96,90},
  {101,102,104,103,95,100,99,98,97,100}

};
byte colPins[COLS] = {52, 50, 48, 46, 44, 42, 40, 38, 36, 34}; //connect to the row pinouts of the keypad
byte rowPins[ROWS] = {53, 51, 49, 47, 45, 43, 41, 39, 37, 35}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
bool toggle[600];
bool DGEN_en=0, ABSV_en1=0, ABSV_en2=0, DG_SW_bef_CIR_en=0;
int SW_bef_CIR_TEMP_en=0, Steam_Water_level_en=0, FW_aft_ME_en=0  ;


void setupMatrix(){
  for(int i=363; i<372; i++){toggle[i] = !toggle[i]; neo[i] = 'R';} 
  for(int i=324; i<334; i++){toggle[i] = !toggle[i]; neo[i] = 'R';} 
  for(int i=111; i<130; i++){toggle[i] = !toggle[i]; neo[i] = 'R';}
  for(int i=386; i<393; i++){toggle[i] = !toggle[i]; neo[i] = 'R';}

  neo[107] = 'R'; neo[108] = 'R';neo[109] = 'R'; neo[312] = 'R'; neo[338] = 'R'; neo[339] = 'R'; neo[340] = 'R'; neo[341] = 'R'; neo[355] = 'R';
  neo[356] = 'R'; neo[383] = 'R'; neo[2] = 'R'; neo[3] = 'R'; neo[20] = 'R'; neo[21] = 'R'; neo[28] = 'R'; neo[34] = 'R'; neo[39] = 'R'; neo[46] = 'R'; neo[51] = 'R'; neo[52] = 'R';
  neo[54] = 'R'; neo[55] = 'R'; neo[56] = 'R'; neo[57] = 'R'; neo[64] = 'R'; neo[65] = 'R'; neo[66] = 'R'; neo[71] = 'R'; neo[74] = 'R'; neo[79] = 'R'; neo[82] = 'R'; neo[87] = 'R'; neo[92] = 'R'; neo[97] = 'R'; 
  neo[98] = 'R'; neo[101] = 'R'; neo[102] = 'R'; neo[281] = 'R';neo[282] = 'R';neo[283] = 'R';neo[284] = 'R';neo[130] = 'R';neo[132] = 'R'; neo[103] = 'R';neo[105] = 'R'; neo[329] = 'G';neo[307] = 'G';
  neo[337] = 'R';neo[336] = 'R';neo[335] = 'R';neo[334] = 'R';
}

void toggle_neo2(int possition){
  for(int i=324; i<334; i++){
    if(i!=possition) neo[i] = 'R';
  }
}
bool engine_ST=0, engine_ST2=0, engine_ST3 = 0;
void serchMatrix(){
  char customKey = customKeypad.getKey();
  if (customKey){
    toggle[customKey] = !toggle[customKey];
    if(customKey==20){neo[371] = (toggle[customKey] ? 'G' : 'R'); DOserTank=4;}
    if(customKey==64)neo[370] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==65)neo[369] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==66)neo[368] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==67)neo[367] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==68)neo[366] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==69)neo[365] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==70)neo[364] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==48){HFOserTank = 4; tankTime = millis();neo[363] = (toggle[customKey] ? 'G' : 'R');}
    if(customKey==52)neo[356] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==53)neo[341] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==49)neo[340] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==2){DOdeepTank = 4; tankTime = millis(); neo[386] = (toggle[customKey] ? 'G' : 'R');}
    if(customKey==45){FOsettlingT2 = 4; tankTime = millis(); neo[39] = (toggle[customKey] ? 'G' : 'R');}
    if(customKey==44)neo[54] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==6)neo[55] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==5)neo[56] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==3){HFOdeepTank = 4; tankTime = millis(); neo[57] = (toggle[customKey] ? 'G' : 'R');}
    if(customKey==43)neo[52] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==4)neo[64] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==74)neo[389] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==38)neo[388] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==39)neo[387] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==15){refilTank = 4; tankTime = millis(); neo[2] = (toggle[customKey] ? 'G' : 'R');}
    if(customKey==36)neo[3] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==75)neo[392] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==40)neo[391] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==37)neo[390] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==14){COtank = 4; tankTime = millis(); neo[355] = (toggle[customKey] ? 'G' : 'R');}
    if(customKey==50)neo[339] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==16){expansionTank = 4; tankTime = millis(); neo[383] = (toggle[customKey] ? 'G' : 'R');}
    if(customKey==13){MEoilTank2 = 4; tankTime = millis(); neo[74] = (toggle[customKey] ? 'G' : 'R');}
    if(customKey==12){DGoilTank = 4; tankTime = millis(); neo[87] = (toggle[customKey] ? 'G' : 'R');}
    if(customKey==10){MEoilTank1 = 4; tankTime = millis(); neo[97] = (toggle[customKey] ? 'G' : 'R');}
    if(customKey==34)neo[82] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==33)neo[71] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==77)neo[92] = (toggle[customKey] ? 'G' : 'R');neo[179]='V';
    if(customKey==11)neo[98] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==49)neo[340] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==22)neo[338] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==32)neo[117] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==27)neo[118] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==56)neo[119] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==57){neo[120] = (toggle[customKey] ? 'G' : 'R');if(neo[120]=='G'){Serial3.println("ABSV"); ABSV_en1 = 1;} if(neo[120]=='R' && ABSV_en1 == 1){ABSV_en1 = 0; Serial3.println("ABOF");}}
    if(customKey==61)neo[128] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==62)neo[127] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==28)neo[129] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==18){neo[126] = (toggle[customKey] ? 'G' : 'R'); if(neo[126]=='G'){Serial3.println("DGEN"); DGEN_en = 1; } if(neo[126]=='R' && DGEN_en == 1){DGEN_en = 0; Serial3.println("DGOF");}}
    if(customKey==17)neo[125] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==24)neo[123] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==23)neo[124] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==72)neo[121] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==73)neo[122] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==63)neo[111] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==60){neo[112] = (toggle[customKey] ? 'G' : 'R'); if(neo[120]=='G'){Serial3.println("ABSV"); ABSV_en2 = 1;} if(neo[120]=='R' && ABSV_en2 == 1){ABSV_en2 = 0; Serial3.println("ABOF");}}
    if(customKey==59)neo[113] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==58)neo[114] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==31)neo[115] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==54)neo[116] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==55)neo[101] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==25)neo[109] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==26)neo[102] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==29)neo[107] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==30)neo[108] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==76)neo[79] = (toggle[customKey] ? 'G' : 'R');
    if(customKey==82){neo[324] = (toggle[customKey] ? 'G' : 'R');if(neo[324]=='G') toggle_neo2(324);}
    if(customKey==83){neo[325] = (toggle[customKey] ? 'G' : 'R');if(neo[325]=='G') toggle_neo2(325);}
    if(customKey==84){neo[326] = (toggle[customKey] ? 'G' : 'R');if(neo[326]=='G') toggle_neo2(326);}
    if(customKey==85){neo[327] = (toggle[customKey] ? 'G' : 'R');if(neo[327]=='G') toggle_neo2(327);}
    if(customKey==86){neo[328] = (toggle[customKey] ? 'G' : 'R');if(neo[328]=='G') toggle_neo2(328);}
    if(customKey==87){neo[329] = (toggle[customKey] ? 'G' : 'R');if(neo[329]=='G') toggle_neo2(329);}
    if(customKey==88){neo[330] = (toggle[customKey] ? 'G' : 'R');if(neo[330]=='G') toggle_neo2(330);}
    if(customKey==89){neo[331] = (toggle[customKey] ? 'G' : 'R');if(neo[331]=='G') toggle_neo2(331);}
    if(customKey==90){neo[332] = (toggle[customKey] ? 'G' : 'R');if(neo[332]=='G') toggle_neo2(332);}
    if(customKey==91){neo[333] = (toggle[customKey] ? 'G' : 'R');if(neo[333]=='G') toggle_neo2(333);}
    if(customKey==78){
      neo[103] = 'R';
      neo[130] = (toggle[customKey] ? 'R' : 'R');
      neo[131] = (toggle[customKey] ? 'V' : 'V');
    }
    else if(customKey==79){
      neo[103] = 'G';
      neo[131] = (toggle[customKey] ? 'G' : 'G');
      neo[130] = (toggle[customKey] ? 'v' : 'v');
    }
    if(neo[103]=='G' && neo[102]=='G' && neo[109]=='G' && neo[123]=='G' && engine_ST==0){engine_ST=1; Serial1.println("START"); engineStart();}
    else if(neo[103]=='R' && engine_ST==1){engine_ST=0; Serial1.println("STOP");}
    else if((neo[102]=='R' || neo[109]=='R' || neo[123]=='R') && engine_ST==1){engine_ST=0; Serial1.println("STOP");alarm_on=4;}
    if(customKey==80){
      neo[105] = 'R';
      neo[132] = (toggle[customKey] ? 'R' : 'R');
      neo[133] = (toggle[customKey] ? 'V' : 'V');
    }
    else if(customKey==81){
      neo[105] = 'G';
      neo[133] = (toggle[customKey] ? 'G' : 'G');
      neo[132] = (toggle[customKey] ? 'V' : 'V');
    }
    if(neo[105]=='G' && neo[107]=='G' && neo[108]=='G' && neo[123]=='G' && engine_ST2==0){engine_ST2=1; Serial1.println("STAR2"); engineStart();}
    else if(neo[105]=='R' && engine_ST2==1){engine_ST2=0; Serial1.println("STO2");}
    else if((neo[107]=='R' || neo[108]=='R' || neo[123]=='R') && engine_ST2==1){engine_ST2=0; Serial1.println("STO2");alarm_on=4;}
    
    if(customKey==95)neo[281] = (toggle[customKey] ? 'G' : 'G');
    if(customKey==96)neo[281] = (toggle[customKey] ? 'R' : 'R');
    if(customKey==97)neo[282] = (toggle[customKey] ? 'G' : 'G');
    if(customKey==98)neo[282] = (toggle[customKey] ? 'R' : 'R');
    if(customKey==99)neo[283] = (toggle[customKey] ? 'G' : 'G');
    if(customKey==100)neo[283] = (toggle[customKey] ? 'R' : 'R');
    if(customKey==101)neo[284] = (toggle[customKey] ? 'G' : 'G');
    if(customKey==102)neo[284] = (toggle[customKey] ? 'R' : 'R'); 
    if(customKey==92){alarm_on=0; playerStop();}
    if(customKey==21){hand_pump=4; tankTime = millis();}
    if(customKey==104){neo[268]='R'; syncVar=2; syncVar2 = 4;}
    // Serial.println(toggle);
    Serial.println((int)customKey);
    
    if(customKey==93){
      neo[134] = 'R';
      neo[137] = (toggle[customKey] ? 'R' : 'R');
    }
    else if(customKey==94){
      neo[134] = 'G';
      neo[137] = (toggle[customKey] ? 'v' : 'v');
    }
    if(neo[134]=='G' && engine_ST3==0){engine_ST3=1; Serial1.println("STAR3"); }
    else if(neo[134]=='R' && engine_ST3==1){engine_ST3=0; Serial1.println("STO3");}

  }
  if(neo[338]=='G'&& (neo[210]!='R'||neo[213]!='R') && DG_SW_bef_CIR_en==0){DG_SW_bef_CIR_en=4; Serial2.println("STA44");}
  else if(neo[338]=='R'&& neo[210]=='R'&& neo[213]=='R' && DG_SW_bef_CIR_en==4){Serial2.println("ST44");DG_SW_bef_CIR_en=0;}
  else if(neo[338]=='R'&& (neo[210]!='R'||neo[213]!='R')){alarm_on=4;}

  if(neo[209]!='R' || neo[214]!='R' && SW_bef_CIR_TEMP_en==0){SW_bef_CIR_TEMP_en=4; Serial2.println("STA55");}
  else if(neo[209]=='R' && neo[214]=='R' && SW_bef_CIR_TEMP_en==4){SW_bef_CIR_TEMP_en=4; Serial2.println("STO55");}

  if(neo[182]!='R' && neo[387]!='R' && neo[388]!='R'&& Steam_Pressure_en==0){display_[2]=4;Steam_Pressure_en=4;}
  else if(neo[182]=='R' || neo[387]=='R' || neo[388]=='R'|| Steam_Pressure_en==4){display_[2]=0;Steam_Pressure_en=0;}

  if((neo[149]!='R' || neo[181]!='R') && neo[388]=='G' && neo[400]=='G' && Steam_Water_level_en==0){display_[4]=4;Steam_Water_level_en=4;Steam_Water_level_AL=0;}
  else if(neo[182]=='R' || neo[387]=='R' || neo[388]=='R'|| Steam_Water_level_en==4){display_[4]=0;Steam_Water_level_en=0;}

  if((neo[145]!='R' || neo[207]!='R') && FW_aft_ME_en==0){display_[5]=4; FW_aft_ME_en=4;}
  else if(neo[145]=='R' && neo[207]=='R' && FW_aft_ME_en==4){display_[5]=0;FW_aft_ME_en=0;}
}

