String readString;
char key[10];
int count2=0;
char * read;
void setupSerComm(){
    Serial1.begin(115200);
    Serial2.begin(115200);
    Serial3.begin(115200);
    neo[289] = 'R';neo[292] = 'R';neo[323] = 'R';neo[302] = 'R';neo[293] = 'R';neo[213] = 'R';neo[263] = 'R';neo[262] = 'R';neo[214] = 'R';neo[146] = 'R';neo[149] = 'R';
    neo[148] = 'R';neo[181] = 'R';neo[286] = 'R';neo[291] = 'R';neo[290] = 'R';neo[285] = 'R';neo[321] = 'R';neo[212] = 'R';neo[211] = 'R';neo[139] = 'R';neo[182] = 'R';
    neo[147] = 'R';neo[144] = 'R';neo[143] = 'R';neo[209] = 'R';neo[210] = 'R';neo[208] = 'R';neo[145] = 'R';neo[207] = 'R';neo[215] = 'R';neo[217] = 'R';neo[264] = 'R';
    neo[265] = 'R';neo[266] = 'R';neo[267] = 'R';neo[142] = 'R';neo[141] = 'R';neo[140] = 'R';neo[301] = 'R';neo[99] = 'R';neo[100] = 'R';

    neo[329] = 'R';neo[307] = 'R';neo[294] = 'R';neo[315] = 'R';neo[173] = 'R';neo[168] = 'R';neo[167] = 'R';neo[166] = 'R';neo[165] = 'R';neo[164] = 'R';neo[184] = 'R';
    neo[187] = 'R';neo[244] = 'R';neo[241] = 'R';neo[240] = 'R';neo[239] = 'R';neo[236] = 'R';neo[235] = 'R';neo[234] = 'R';neo[233] = 'R';neo[151] = 'R';neo[152] = 'R';
    neo[156] = 'R';neo[157] = 'R';neo[158] = 'R';neo[161] = 'R';neo[200] = 'R';neo[199] = 'R';neo[198] = 'R';neo[197] = 'R';neo[195] = 'R';neo[137] = 'R';neo[190] = 'R';
    neo[192] = 'R';neo[205] = 'R';neo[203] = 'R';neo[284] = 'R';neo[265] = 'R';neo[266] = 'R';neo[267] = 'R';neo[1] = 'R';   
}
void send_actuator(){
    Serial3.println(speed_value);
}

void checkData(){
    Serial1.println("ESP");
}

void readSerial(){

    while (Serial1.available()){
        delay(1);
        if(Serial1.available()>0){
            // char esp1 = Serial1.read();
            // Serial.print(esp1);
            // if (isControl(esp1)){
            //     break;
             readString = Serial1.readStringUntil('\n');
               if (readString.length() > 3) 
            {
                readString.toCharArray(key,4);
                for(int i=0; i<4; i++)Serial.print(key[i]);
                if(key[0]== '2')if(key[1]== '0')if(key[2]== '2'){neo[149] = 'G';neo[395] = 'G';} if(key[0]== '6')if(key[1]== '0')if(key[2]== '2'){neo[149] = 'R';neo[395] = 'R';} 
                if(key[0]== '1')if(key[1]== '6')if(key[2]== '7'){neo[146] = 'G';neo[1] = 'G';} if(key[0]== '5')if(key[1]== '6')if(key[2]== '7'){neo[146] = 'R';neo[1] = 'R';} 
                if(key[0]== '1')if(key[1]== '6')if(key[2]== '4'){neo[181] = 'G';neo[396] = 'G';} if(key[0]== '5')if(key[1]== '6')if(key[2]== '4'){neo[181] = 'R';neo[396] = 'R';} 
                if(key[0]== '1')if(key[1]== '9')if(key[2]== '8'){neo[148] = 'B';} if(key[0]== '1')if(key[1]== '9')if(key[2]== '9'){neo[148] = 'G';} if(key[0]== '5')if(key[1]== '9')if(key[2]== '9'){neo[148] = 'R';} 
                if(key[0]== 'S')if(key[1]== 'T')if(key[2]== 'O'){engineStop();}
                readString = "";
            }
        }
    }

    while (Serial2.available()){
        delay(1);
        if(Serial2.available()>0){
            //char esp2 = Serial2.read();
           // Serial.print(esp2);
            //if (isControl(esp2)){
             //   break;
              readString = Serial2.readStringUntil('\n');
               if (readString.length() > 3) 
            {
                readString.toCharArray(key,4);
                for(int i=0; i<4; i++)Serial.print(key[i]);
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '0'){neo[214] = 'G';neo[336]='G';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '0'){neo[214] = 'R';neo[336]='R';} 
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '7'){neo[263] = 'R';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '7'){neo[263] = 'G';} 
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '8'){neo[262] = 'G';neo[348] = 'G';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '8'){neo[262] = 'R';neo[348] = 'R';} 
                if(key[0]== '1')if(key[1]== '7')if(key[2]== '7'){neo[213] = 'B';neo[334] = 'B';} if(key[0]== '1')if(key[1]== '7')if(key[2]== '8'){neo[213] = 'G';neo[334] = 'G';} if(key[0]== '5')if(key[1]== '7')if(key[2]== '7'){neo[213] = 'R';neo[334] = 'R';} 
                readString = "";
            }
        }
    }
    while (Serial3.available()){
        delay(1);
        if(Serial3.available()>0){
            readString = Serial3.readStringUntil('\n');
            // char mega2 = Serial3.read();
            // Serial.print(readString);
            // read[count2]=mega2;
            // count2++;
            //if(mega2 == "138")neo[289] = 'G'; else neo[289] = 'R';

            // if (isControl(mega2)){
            //     // Serial.print(read);
            //     // count2=0;
            //     break;
            // Serial.println("test");
            // }
        // }
            if (readString.length() > 3) 
            {
                readString.toCharArray(key,7);
                for(int i=0; i<7; i++)Serial.print(key[i]);
                if(key[0]== 'A')if(key[1]== 'L')if(key[2]== '1'){alarm_on=4; key[3]=0;key[4]=0;key[5]=0;}
                if(key[0]== 'A')if(key[1]== 'L')if(key[2]== '0'){alarm_on=0; key[3]=0;key[4]=0;key[5]=0;}
                if(key[0]== '1')if(key[1]== '3')if(key[2]== '8'){neo[289] = 'G';} if(key[0]== '5')if(key[1]== '3')if(key[2]== '8'){neo[289] = 'R';} 
                if(key[0]== '1')if(key[1]== '9')if(key[2]== '5'){neo[289] = 'G';} if(key[0]== '5')if(key[1]== '9')if(key[2]== '5'){neo[289] = 'R';} 
                if(key[0]== '1')if(key[1]== '3')if(key[2]== '1'){neo[292] = 'G';neo[100] = 'G';delay(100);Serial3.println("AC2N");} if(key[0]== '1')if(key[1]== '3')if(key[2]== '2'){neo[292] = 'B';neo[100] = 'B';delay(100);Serial3.println("AC2N");} if(key[0]== '5')if(key[1]== '3')if(key[2]== '2'){neo[292] = 'R';neo[100] = 'R';delay(100);Serial3.println("AC2OF");}
                if(key[0]== '1')if(key[1]== '2')if(key[2]== '6'){neo[323] = 'G';} if(key[0]== '5')if(key[1]== '2')if(key[2]== '6'){neo[323] = 'R';}
                if(key[0]== '1')if(key[1]== '2')if(key[2]== '1'){neo[302] = 'B';} if(key[0]== '1')if(key[1]== '2')if(key[2]== '2'){neo[302] = 'G';} if(key[0]== '5')if(key[1]== '2')if(key[2]== '2'){neo[302] = 'R';}
                if(key[0]== '1')if(key[1]== '2')if(key[2]== '9'){neo[293] = 'G';neo[99] = 'G';delay(100);Serial3.println("AC1N");} if(key[0]== '1')if(key[1]== '3')if(key[2]== '0'){neo[293] = 'B';neo[99] = 'B';delay(100);Serial3.println("AC1N");} if(key[0]== '5')if(key[1]== '3')if(key[2]== '0'){neo[293] = 'R';neo[99] = 'R';delay(100);Serial3.println("AC1OF");} 
                if(key[0]== '1')if(key[1]== '4')if(key[2]== '2'){neo[286] = 'G';} if(key[0]== '1')if(key[1]== '4')if(key[2]== '1'){neo[286] = 'B';} if(key[0]== '5')if(key[1]== '4')if(key[2]== '1'){neo[286] = 'R';}
                if(key[0]== '1')if(key[1]== '3')if(key[2]== '5'){neo[291] = 'G';} if(key[0]== '1')if(key[1]== '3')if(key[2]== '4'){neo[291] = 'B';} if(key[0]== '5')if(key[1]== '3')if(key[2]== '4'){neo[291] = 'R';}
                if(key[0]== '1')if(key[1]== '3')if(key[2]== '7'){neo[290] = 'G';} if(key[0]== '1')if(key[1]== '3')if(key[2]== '6'){neo[290] = 'B';} if(key[0]== '5')if(key[1]== '3')if(key[2]== '6'){neo[290] = 'R';}
                if(key[0]== '1')if(key[1]== '4')if(key[2]== '4'){neo[285] = 'G';} if(key[0]== '1')if(key[1]== '4')if(key[2]== '3'){neo[285] = 'B';} if(key[0]== '5')if(key[1]== '4')if(key[2]== '3'){neo[285] = 'R';}
                if(key[0]== '1')if(key[1]== '2')if(key[2]== '8'){neo[321] = 'G';} if(key[0]== '1')if(key[1]== '2')if(key[2]== '7'){neo[321] = 'B';} if(key[0]== '5')if(key[1]== '2')if(key[2]== '7'){neo[321] = 'R';}
                if(key[0]== '1')if(key[1]== '9')if(key[2]== '2'){neo[212] = 'G';} if(key[0]== '1')if(key[1]== '9')if(key[2]== '1'){neo[212] = 'B';} if(key[0]== '5')if(key[1]== '9')if(key[2]== '1'){neo[212] = 'R';}
                if(key[0]== '1')if(key[1]== '6')if(key[2]== '2'){neo[211] = 'G';} if(key[0]== '1')if(key[1]== '6')if(key[2]== '1'){neo[211] = 'B';} if(key[0]== '5')if(key[1]== '6')if(key[2]== '1'){neo[211] = 'R';}
                if(key[0]== '1')if(key[1]== '6')if(key[2]== '0'){neo[139] = 'B';} if(key[0]== '1')if(key[1]== '5')if(key[2]== '9'){neo[139] = 'G';} if(key[0]== '5')if(key[1]== '5')if(key[2]== '9'){neo[139] = 'R';}
                if(key[0]== '1')if(key[1]== '5')if(key[2]== '2'){neo[143] = 'G';} if(key[0]== '1')if(key[1]== '5')if(key[2]== '1'){neo[143] = 'B';} if(key[0]== '5')if(key[1]== '5')if(key[2]== '1'){neo[143] = 'R';}
                if(key[0]== '1')if(key[1]== '4')if(key[2]== '8'){neo[144] = 'B';} if(key[0]== '1')if(key[1]== '4')if(key[2]== '7'){neo[144] = 'G';} if(key[0]== '5')if(key[1]== '4')if(key[2]== '7'){neo[144] = 'R';}
                if(key[0]== '2')if(key[1]== '0')if(key[2]== '1'){neo[147] = 'G';} if(key[0]== '2')if(key[1]== '0')if(key[2]== '0'){neo[147] = 'B';} if(key[0]== '6')if(key[1]== '0')if(key[2]== '0'){neo[147] = 'R';}
                if(key[0]== '1')if(key[1]== '6')if(key[2]== '6'){neo[182] = 'G';} if(key[0]== '1')if(key[1]== '6')if(key[2]== '5'){neo[182] = 'B';} if(key[0]== '5')if(key[1]== '6')if(key[2]== '5'){neo[182] = 'R';}

                if(key[0]== '1')if(key[1]== '6')if(key[2]== '9'){neo[145] = 'G';neo[38] = 'G';} if(key[0]== '1')if(key[1]== '6')if(key[2]== '8'){neo[145] = 'B';neo[38] = 'B';} if(key[0]== '5')if(key[1]== '6')if(key[2]== '8'){neo[145] = 'R';neo[38] = 'R';}
                if(key[0]== '1')if(key[1]== '7')if(key[2]== '0'){neo[208] = 'G';} if(key[0]== '5')if(key[1]== '7')if(key[2]== '0'){neo[208] = 'R';}
                if(key[0]== '1')if(key[1]== '7')if(key[2]== '2'){neo[210] = 'G';neo[233]='V';neo[335] = 'G';} if(key[0]== '1')if(key[1]== '7')if(key[2]== '1'){neo[210] = 'B';neo[335] = 'B';} if(key[0]== '5')if(key[1]== '7')if(key[2]== '1'){neo[210] = 'R';neo[335] = 'R';}
                if(key[0]== '1')if(key[1]== '7')if(key[2]== '4'){neo[209] = 'G';neo[236]='V';neo[235]='V';neo[337]='G';} if(key[0]== '1')if(key[1]== '7')if(key[2]== '3'){neo[209] = 'B';neo[337]='B';} if(key[0]== '5')if(key[1]== '7')if(key[2]== '3'){neo[209] = 'R';neo[337]='R';}

                if(key[0]== '1')if(key[1]== '7')if(key[2]== '6'){neo[207] = 'G';neo[37] = 'G';} if(key[0]== '1')if(key[1]== '7')if(key[2]== '5'){neo[207] = 'B';neo[37] = 'B';} if(key[0]== '5')if(key[1]== '7')if(key[2]== '5'){neo[207] = 'R';neo[37] = 'R';}
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '2'){neo[215] = 'G';neo[81] = 'G';} if(key[0]== '1')if(key[1]== '8')if(key[2]== '1'){neo[215] = 'B';neo[81] = 'B';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '1'){neo[215] = 'R';neo[81] = 'R';}
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '4'){neo[217] = 'G';neo[80] = 'G';} if(key[0]== '1')if(key[1]== '8')if(key[2]== '3'){neo[217] = 'B';neo[80] = 'B';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '3'){neo[217] = 'R';neo[80] = 'R';}
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '6'){neo[264] = 'G';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '6'){neo[264] = 'R';}
                if(key[0]== '1')if(key[1]== '2')if(key[2]== '4'){neo[301] = 'G';} if(key[0]== '1')if(key[1]== '2')if(key[2]== '3'){neo[301] = 'B';} if(key[0]== '5')if(key[1]== '2')if(key[2]== '3'){neo[301] = 'R';}

                if(key[0]== '2')if(key[1]== '0')if(key[2]== '4'){neo[265] = 'R';neo[266] = 'R';neo[267] = 'R';} if(key[0]== '2')if(key[1]== '0')if(key[2]== '5'){neo[265] = 'G';neo[266] = 'R';neo[267] = 'R';}
                if(key[0]== '2')if(key[1]== '0')if(key[2]== '6'){neo[265] = 'R';neo[266] = 'G';neo[267] = 'R';} if(key[0]== '2')if(key[1]== '0')if(key[2]== '7'){neo[265] = 'R';neo[266] = 'R';neo[267] = 'G';}

                if(key[0]== '1')if(key[1]== '5')if(key[2]== '5'){neo[142] = 'R';neo[141] = 'R';neo[140] = 'R';} if(key[0]== '1')if(key[1]== '5')if(key[2]== '6'){neo[142] = 'G';neo[141] = 'R';neo[140] = 'R';} 
                if(key[0]== '1')if(key[1]== '5')if(key[2]== '7'){neo[142] = 'R';neo[141] = 'G';neo[140] = 'R';} if(key[0]== '1')if(key[1]== '5')if(key[2]== '8'){neo[142] = 'R';neo[141] = 'R';neo[140] = 'G';} 
                readString = "";
                // Serial.println(key[1]);
            }
        }
    }
}

