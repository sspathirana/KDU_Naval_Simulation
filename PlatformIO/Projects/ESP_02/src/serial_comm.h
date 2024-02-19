String readString;
char Data[10];
int display_[8];


char command[10];
void readSerial(){
  if(Serial.available())
  {
   // delay(3);
    readString = Serial.readStringUntil('\n');
  }
  if (readString.length() > 0) 
  {
    readString.toCharArray(Data,10);
    
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'A' && Data[3] == 'R' && Data[4] == '1'){
        Data[0] ='e';
        display_[3] = 4; 
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'O' && Data[3] == 'P'){
        Data[0] ='e';
        display_[3] = 0; 
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'A' && Data[3] == 'R' && Data[4] == '2'){
        Data[0] ='e';
        display_[2] = 4; 
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'A' && Data[3] == 'T' && Data[4] == '2' && Data[5] == '2'){
        Data[0] ='e';
        display_[2] = 2; 
        display_[7] = 2;//lube oil pistons
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'O' && Data[3] == '2'){
        Data[0] ='e';
        display_[2] = 8; 
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'A' && Data[3] == 'R' && Data[4] == '3'){//display_LO_aft_trans1
        Data[0] ='e';
        display_[1] = 4; 
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'O' && Data[3] == '3'){
        Data[0] ='e';
        display_[1] = 8; 
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'A' && Data[3] == 'R' && Data[4] == '4'){//display_LO_aft_trans2
        Data[0] ='e';
        display_[0] = 4; 
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'O' && Data[3] == '4'){
        Data[0] ='e';
        display_[0] = 8; 
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'A' && Data[3] == '4' && Data[4] == '4'){//display_LO_aft_trans2
        Data[0] ='e';
        display_[4] = 4; 
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == '4' && Data[3] == '4'){
        Data[0] ='e';
        display_[4] = 8; 
    }
    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'A' && Data[3] == '5' && Data[4] == '5'){//display_LO_aft_trans2
        Data[0] ='e';
        display_[5] = 4; 
        display_[6] = 4;
    }

    if(Data[0] == 'S' && Data[1] == 'T' && Data[2] == 'O' && Data[3] == '5' && Data[4] == '5'){//display_LO_aft_trans2
        Data[0] ='e';
        display_[5] = 0; 
        display_[6] = 0;
    }

   

/*     else if(Data[0] == 'A' && Data[1] == 'C' && Data[2] == '1' && Data[3] == 'N'){
        Data[0] ='e';
        display_UP[5] = 0.1; AL_en[5] = 4;
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'C' && Data[2] == '1' && Data[3] == 'O' && Data[4] == 'F'){
        Data[0] ='e';
        display_UP[5] = 0; AL_en[5] = 0;
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'C' && Data[2] == '2' && Data[3] == 'N'){
        Data[0] ='e';
        display_UP[6] = 0.1; AL_en[6] = 4;
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'C' && Data[2] == '2' && Data[3] == 'O' && Data[4] == 'F'){
        Data[0] ='e';
        display_UP[6] = 0; AL_en[6] = 0;
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'B' && Data[2] == 'S' && Data[3] == 'V'){
        displayABSV();
        delay(1000);
    }
    else if(Data[0] == 'A' && Data[1] == 'B' && Data[2] == 'O' && Data[3] == 'F'){
        Data[0] ='e';
        display_UP[3] = 0; AL_en[3] = 0;
        delay(1000);
    }
    else if(atoi(Data)<1030){MEP= atoi(Data)/4; RPM= atoi(Data)/8;display_actuator();} */
  }
  readString = "";

}