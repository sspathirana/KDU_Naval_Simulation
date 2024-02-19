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
                if(key[0]== '2')if(key[1]== '0')if(key[2]== '2'){neo[149] = 'G';} if(key[0]== '6')if(key[1]== '0')if(key[2]== '2'){neo[149] = 'R';} 
                if(key[0]== '1')if(key[1]== '6')if(key[2]== '7'){neo[146] = 'G';} if(key[0]== '5')if(key[1]== '6')if(key[2]== '7'){neo[146] = 'R';} 
                if(key[0]== '1')if(key[1]== '6')if(key[2]== '4'){neo[181] = 'G';} if(key[0]== '5')if(key[1]== '6')if(key[2]== '4'){neo[181] = 'R';} 
                if(key[0]== '1')if(key[1]== '9')if(key[2]== '8'){neo[148] = 'B';} if(key[0]== '1')if(key[1]== '9')if(key[2]== '9'){neo[148] = 'G';} if(key[0]== '5')if(key[1]== '9')if(key[2]== '9'){neo[148] = 'R';} 
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
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '0'){neo[214] = 'G';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '0'){neo[214] = 'R';} 
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '7'){neo[263] = 'R';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '7'){neo[263] = 'G';} 
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '8'){neo[262] = 'G';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '8'){neo[262] = 'R';} 
                if(key[0]== '1')if(key[1]== '7')if(key[2]== '7'){neo[213] = 'B';} if(key[0]== '1')if(key[1]== '7')if(key[2]== '8'){neo[213] = 'G';} if(key[0]== '5')if(key[1]== '7')if(key[2]== '7'){neo[213] = 'R';} 
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

                if(key[0]== '1')if(key[1]== '6')if(key[2]== '9'){neo[145] = 'G';} if(key[0]== '1')if(key[1]== '6')if(key[2]== '8'){neo[145] = 'B';} if(key[0]== '5')if(key[1]== '6')if(key[2]== '8'){neo[145] = 'R';}
                if(key[0]== '1')if(key[1]== '7')if(key[2]== '0'){neo[208] = 'G';} if(key[0]== '5')if(key[1]== '7')if(key[2]== '0'){neo[208] = 'R';}
                if(key[0]== '1')if(key[1]== '7')if(key[2]== '2'){neo[210] = 'G';} if(key[0]== '1')if(key[1]== '7')if(key[2]== '1'){neo[210] = 'B';} if(key[0]== '5')if(key[1]== '7')if(key[2]== '1'){neo[210] = 'R';}
                if(key[0]== '1')if(key[1]== '7')if(key[2]== '4'){neo[209] = 'G';} if(key[0]== '1')if(key[1]== '7')if(key[2]== '3'){neo[209] = 'B';} if(key[0]== '5')if(key[1]== '7')if(key[2]== '3'){neo[209] = 'R';}

                if(key[0]== '1')if(key[1]== '7')if(key[2]== '6'){neo[207] = 'G';} if(key[0]== '1')if(key[1]== '7')if(key[2]== '5'){neo[207] = 'B';} if(key[0]== '5')if(key[1]== '7')if(key[2]== '5'){neo[207] = 'R';}
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '2'){neo[215] = 'G';} if(key[0]== '1')if(key[1]== '8')if(key[2]== '1'){neo[215] = 'B';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '1'){neo[215] = 'R';}
                if(key[0]== '1')if(key[1]== '8')if(key[2]== '4'){neo[217] = 'G';} if(key[0]== '1')if(key[1]== '8')if(key[2]== '3'){neo[217] = 'B';} if(key[0]== '5')if(key[1]== '8')if(key[2]== '3'){neo[217] = 'R';}
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

