
// constants won't change. They're used here to set pin numbers:
const int a2 = A2, a3 = A3, a4 = A4, a5 = A5, a6 = A6, a7 = A7, a8 = A8, a9 = A9, /*a10 = A10,*/ 
a11 = A11, a12 = A12, a13 = A13, /*a14 = A14,*/ a15 = A15, io22 = 22, io23 = 23, io24 = 24, io25 = 25, 
io26 = 26, io27 = 27, io28 = 28, io29 = 29, io30 = 30, io31 = 31, io32 = 32, io33 = 33;  // the number of the pushbutton pin

// Variables will change:
int bttSt_a2, bttSt_a3, bttSt_a4, bttSt_a5, bttSt_a6, bttSt_a7, bttSt_a8, bttSt_a9, bttSt_a10, bttSt_a11, bttSt_a12, bttSt_a13, bttSt_a14, bttSt_a15, 
bttSt_io22, bttSt_io23, bttSt_io24, bttSt_io25, bttSt_io26, bttSt_io27, bttSt_io28, bttSt_io29, bttSt_io30, bttSt_io31, bttSt_io32, bttSt_io33;            // the current reading from the input pin
int lstBttSt_a2 = LOW, lstBttSt_a3 = LOW, lstBttSt_a4 = LOW, lstBttSt_a5 = LOW, lstBttSt_a6 = LOW, lstBttSt_a7 = LOW, lstBttSt_a8 = LOW, 
lstBttSt_a9 = LOW, /*lstBttSt_a10 = LOW,*/ lstBttSt_a11 = LOW, lstBttSt_a12 = LOW, lstBttSt_a13 = LOW, /*lstBttSt_a14 = LOW,*/ lstBttSt_a15 = LOW, 
lstBttSt_io22 = LOW, lstBttSt_io23 = LOW, lstBttSt_io24 = LOW, lstBttSt_io25 = LOW, lstBttSt_io26 = LOW, lstBttSt_io27 = LOW, lstBttSt_io28 = LOW, lstBttSt_io29 = LOW, 
lstBttSt_io30 = LOW, lstBttSt_io31 = LOW, lstBttSt_io32 = LOW, lstBttSt_io33 = LOW;  // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setupPush() {
  pinMode(a2, INPUT_PULLUP);
  pinMode(a3, INPUT_PULLUP);
  pinMode(a4, INPUT_PULLUP);
  pinMode(a5, INPUT_PULLUP);
  pinMode(a6, INPUT_PULLUP);
  pinMode(a7, INPUT_PULLUP);
  pinMode(a8, INPUT_PULLUP);
  pinMode(a9, INPUT_PULLUP);
  // pinMode(a10, INPUT_PULLUP);
  pinMode(a11, INPUT_PULLUP);
  pinMode(a12, INPUT_PULLUP);
  pinMode(a13, INPUT_PULLUP);
  // pinMode(a14, INPUT_PULLUP);
  pinMode(a15, INPUT_PULLUP);
  pinMode(io22, INPUT_PULLUP);
  pinMode(io23, INPUT_PULLUP);
  pinMode(io24, INPUT_PULLUP);
  pinMode(io25, INPUT_PULLUP);
  pinMode(io26, INPUT_PULLUP);
  pinMode(io27, INPUT_PULLUP);
  pinMode(io28, INPUT_PULLUP);
  pinMode(io29, INPUT_PULLUP);
  pinMode(io30, INPUT_PULLUP);
  pinMode(io31, INPUT_PULLUP);
  pinMode(io32, INPUT_PULLUP);
  pinMode(io33, INPUT_PULLUP);
  neo[296] = 'R'; neo[34] = 'R'; neo[28] = 'R'; neo[21] = 'R'; neo[20] = 'R'; neo[46] = 'R'; neo[51] = 'R'; neo[65] = 'R';neo[66] = 'R';
  for(int i = 303; i<315; i++) neo[i]='R';
  for(int i = 317; i<320; i++) neo[i]='R';

  // set initial LED state
}

void toggle_neo(int possition){
  for(int i=303; i<312; i++){
    if(i!=possition) neo[i] = 'R';
  }
}

void scanPush() {
  // read the state of the switch into a local variable:
  int in114 = digitalRead(a2);
  int in108 = digitalRead(a3);
  int in110 = digitalRead(a4);
  int in113 = digitalRead(a5);
  int in9 = digitalRead(a6);
  int in19 = digitalRead(a7);
  int in41 = digitalRead(a8);
  int in7 = digitalRead(a9);
  // int in71 = digitalRead(a10);
  int in47 = digitalRead(a11);
  int in46 = digitalRead(a12);
  int in8 = digitalRead(a13);
  // int in51 = digitalRead(a14);
  int in42 = digitalRead(a15);
  int in112 = digitalRead(io22);
  int in111 = digitalRead(io23);
  int in119 = digitalRead(io24);
  int in109 = digitalRead(io25);
  int in118 = digitalRead(io26);
  int in115 = digitalRead(io27);
  int in116 = digitalRead(io28);
  int in120 = digitalRead(io29);
  int in106 = digitalRead(io30);
  int in105 = digitalRead(io31);
  int in117 = digitalRead(io32);
  int in107 = digitalRead(io33);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (in114 != lstBttSt_a2) {lastDebounceTime = millis();}
  if (in108 != lstBttSt_a3) {lastDebounceTime = millis();}
  if (in110 != lstBttSt_a4) {lastDebounceTime = millis();}
  if (in113 != lstBttSt_a5) {lastDebounceTime = millis();}
  if (in9 != lstBttSt_a6) {lastDebounceTime = millis();}
  if (in19 != lstBttSt_a7) {lastDebounceTime = millis();}
  if (in41 != lstBttSt_a8) {lastDebounceTime = millis();}
  if (in7 != lstBttSt_a9) {lastDebounceTime = millis();}
  // if (in71 != lstBttSt_a10) {lastDebounceTime = millis();}
  if (in47 != lstBttSt_a11) {lastDebounceTime = millis();}
  if (in46 != lstBttSt_a12) {lastDebounceTime = millis();}
  if (in8 != lstBttSt_a13) {lastDebounceTime = millis();}
  // if (in51 != lstBttSt_a14) {lastDebounceTime = millis();}
  if (in42 != lstBttSt_a15) {lastDebounceTime = millis();}
  if (in112 != lstBttSt_io22) {lastDebounceTime = millis();}
  if (in111 != lstBttSt_io23) {lastDebounceTime = millis();}
  if (in119 != lstBttSt_io24) {lastDebounceTime = millis();}
  if (in109 != lstBttSt_io25) {lastDebounceTime = millis();}
  if (in118 != lstBttSt_io26) {lastDebounceTime = millis();}
  if (in115 != lstBttSt_io27) {lastDebounceTime = millis();}
  if (in116 != lstBttSt_io28) {lastDebounceTime = millis();}
  if (in120 != lstBttSt_io29) {lastDebounceTime = millis();}
  if (in106 != lstBttSt_io30) {lastDebounceTime = millis();}
  if (in105 != lstBttSt_io31) {lastDebounceTime = millis();}
  if (in117 != lstBttSt_io32) {lastDebounceTime = millis();}
  if (in107 != lstBttSt_io33) {lastDebounceTime = millis();}

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the in114 is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (in114 != bttSt_a2) { bttSt_a2 = in114; if (bttSt_a2 == HIGH) {toggle[114] = !toggle[114]; neo[312] = (toggle[114] ? 'R' : 'G');if(neo[312]=='G')actuator = 4; else actuator =0; } }
    if (in9 != bttSt_a6) { bttSt_a6 = in9; if (bttSt_a6 == HIGH) {HFOportTank = 4; tankTime = millis(); toggle[9] = !toggle[9]; neo[20] = (toggle[9] ? 'G' : 'R');} }
    if (in19 != bttSt_a7) { bttSt_a7 = in19; if (bttSt_a7 == HIGH) {toggle[19] = !toggle[19]; neo[21] = (toggle[19] ? 'G' : 'R');} }
    if (in41 != bttSt_a8) { bttSt_a8 = in41; if (bttSt_a8 == HIGH) {toggle[41] = !toggle[41]; neo[46] = (toggle[41] ? 'G' : 'R');} }
    if (in7 != bttSt_a9) { bttSt_a9 = in7; if (bttSt_a9 == HIGH) {/* Serial.println("7"); */ HFOstbdTank = 4; tankTime = millis(); toggle[7] = !toggle[7]; neo[66] = (toggle[7] ? 'G' : 'R');} }
    // if (in71 != bttSt_a10) { bttSt_a10 = in71; if (bttSt_a10 == HIGH) {toggle[71] = !toggle[71]; neo[312] = (toggle[71] ? 'G' : 'R');} }
    if (in47 != bttSt_a11) { bttSt_a11 = in47; if (bttSt_a11 == HIGH) {toggle[47] = !toggle[47]; neo[28] = (toggle[47] ? 'G' : 'R');} }
    if (in46 != bttSt_a12) { bttSt_a12 = in46; if (bttSt_a12 == HIGH) {FOsettlingT1 = 4; tankTime = millis(); toggle[46] = !toggle[46]; neo[34] = (toggle[46] ? 'G' : 'R');} }
    if (in8 != bttSt_a13) { bttSt_a13 = in8; if (bttSt_a13 == HIGH) {HFOcenterTank = 4; tankTime = millis(); toggle[8] = !toggle[8]; neo[51] = (toggle[8] ? 'G' : 'R');} }
    // if (in51 != bttSt_a14) { bttSt_a14 = in51; if (bttSt_a14 == HIGH) {toggle[51] = !toggle[51]; neo[312] = (toggle[114] ? 'G' : 'R');} }
    if (in42 != bttSt_a15) { bttSt_a15 = in42; if (bttSt_a15 == HIGH) {toggle[42] = !toggle[42]; neo[65] = (toggle[42] ? 'G' : 'R');} }
    if (in119 != bttSt_io24) { bttSt_io24 = in119; if (bttSt_io24 == HIGH) {toggle[119] = !toggle[119]; neo[318] = (toggle[119] ? 'R' : 'G');} }
    if (in118 != bttSt_io26) { bttSt_io26 = in118; if (bttSt_io26 == HIGH) {toggle[118] = !toggle[118]; neo[319] = (toggle[118] ? 'R' : 'G');} }
    if (in115 != bttSt_io27) { bttSt_io27 = in115; if (bttSt_io27 == HIGH) {toggle[115] = !toggle[115]; neo[313] = (toggle[115] ? 'R' : 'G');} }
    if (in116 != bttSt_io28) { bttSt_io28 = in116; if (bttSt_io28 == HIGH) {toggle[116] = !toggle[116]; neo[314] = (toggle[116] ? 'R' : 'G');} }
    if (in120 != bttSt_io29) { bttSt_io29 = in120; if (bttSt_io29 == HIGH) {toggle[120] = !toggle[120]; neo[317] = (toggle[120] ? 'R' : 'G');} } 

    if (in105 != bttSt_io31) { bttSt_io31 =in105; if (bttSt_io31 == HIGH) {toggle[105] = !toggle[105]; neo[303] = (toggle[105] ? 'G' : 'R');if(neo[303]=='G')toggle_neo(303);} }
    if (in106 != bttSt_io30) { bttSt_io30 = in106; if (bttSt_io30 == HIGH) {toggle[106] = !toggle[106]; neo[304] = (toggle[106] ? 'G' : 'R');if(neo[304]=='G')toggle_neo(304);} }
    if (in107 != bttSt_io33) { bttSt_io33 = in107; if (bttSt_io33 == HIGH) {toggle[107] = !toggle[107]; neo[305] = (toggle[107] ? 'G' : 'R');if(neo[305]=='G')toggle_neo(305);} }
    if (in108 != bttSt_a3) { bttSt_a3 = in108; if (bttSt_a3 == HIGH) {toggle[108] = !toggle[108]; neo[306] = (toggle[108] ? 'G' : 'R'); if(neo[306]=='G')toggle_neo(306);} }
    if (in109 != bttSt_io25) { bttSt_io25 = in109; if (bttSt_io25 == HIGH) {toggle[109] = !toggle[109]; neo[307] = (toggle[109] ? 'G' : 'R');if(neo[307]=='G')toggle_neo(307);} }
    if (in110 != bttSt_a4) { bttSt_a4 = in110; if (bttSt_a4 == HIGH) {toggle[110] = !toggle[110]; neo[308] = (toggle[110] ? 'G' : 'R');if(neo[308]=='G')toggle_neo(308);} }
    if (in111 != bttSt_io23) { bttSt_io23 = in111; if (bttSt_io23 == HIGH) {toggle[111] = !toggle[111]; neo[309] = (toggle[111] ? 'R' : 'G');if(neo[309]=='G')toggle_neo(309);} }
    if (in112 != bttSt_io22) { bttSt_io22 = in112; if (bttSt_io22 == HIGH) {toggle[112] = !toggle[112]; neo[310] = (toggle[112] ? 'R' : 'G');if(neo[310]=='G')toggle_neo(310);} }
    if (in113 != bttSt_a5) { bttSt_a5 = in113; if (bttSt_a5 == HIGH) {toggle[113] = !toggle[113]; neo[311] = (toggle[113] ? 'R' : 'G');if(neo[311]=='G')toggle_neo(311);} }

    if (in117 != bttSt_io32) { bttSt_io32 = in117; if (bttSt_io32 == HIGH) {toggle[117] = !toggle[117]; neo[296] = (toggle[117] ? 'R' : 'G');} }
    
  }

  // save the in114. Next time through the loop, it'll be the lastButtonState:
  lstBttSt_a2 = in114;
  lstBttSt_a3 = in108;
  lstBttSt_a4 = in110;
  lstBttSt_a5 = in113;
  lstBttSt_a6 = in9;
  lstBttSt_a7 = in19;
  lstBttSt_a8 = in41;
  lstBttSt_a9 = in7;
  // lstBttSt_a10 = in71;
  lstBttSt_a11 = in47;
  lstBttSt_a12 = in46;
  lstBttSt_a13 = in8;
  // lstBttSt_a14 = in51;
  lstBttSt_a15 = in42;
  lstBttSt_io22 = in112;
  lstBttSt_io23 = in111;
  lstBttSt_io24 = in119;
  lstBttSt_io25 = in109;
  lstBttSt_io26 = in118;
  lstBttSt_io27 = in115;
  lstBttSt_io28 = in116;
  lstBttSt_io29 = in120;
  lstBttSt_io30 = in106;
  lstBttSt_io31 =in105;
  lstBttSt_io32 = in117;
  lstBttSt_io33 = in107;
  
}
