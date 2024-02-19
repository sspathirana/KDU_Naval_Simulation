#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define TCAADDR 0x70

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
uint16 LO_sump_level = 0;
uint8 LO_aft_PIS = 0, LO_bef_PIS = 0;
float LO_aft_trans1=0, LO_aft_trans2=0;
float DG_SW_bef_CIR = 0; 

// Helper function for changing TCA output channel
void tcaselect(uint8_t channel) {
  if (channel > 7) return;
  
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << channel);
  Wire.endTransmission();
 // Serial.print(TCAADDR);  
}

void setupOled() {
  
  // Serial.begin(9600);
 
  // Start I2C communication with the Multiplexer
  Wire.begin();

  // Init OLED display on bus number 0
  tcaselect(0);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 

   // Clear the buffer
  display.clearDisplay();
  
  // Init OLED display on bus number 1
   tcaselect(1);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 
  
  // Clear the buffer
  display.clearDisplay();

  tcaselect(2);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 

   // Clear the buffer
  display.clearDisplay();
  
  // Init OLED display on bus number 1
   tcaselect(3);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 
  
  // Clear the buffer
  display.clearDisplay();

  tcaselect(4);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 

   // Clear the buffer
  display.clearDisplay();
  
  // Init OLED display on bus number 1
   tcaselect(5);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 
  
 display.clearDisplay();
  
  // Init OLED display on bus number 1
   tcaselect(6);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 
display.clearDisplay();
  
  // Init OLED display on bus number 1
   tcaselect(7);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  } 

 // Clear the buffer
  display.clearDisplay();

  // Write to OLED on bus number 0
  tcaselect(0);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(10, 5);
  //display.setCursor(50, 5);
  // int cool_sys_temp_1=25;
  // Display static text
  display.println(LO_aft_trans2, 1);
  display.display(); 

  
  // Write to OLED on bus number 1
  tcaselect(1);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(10, 5);
  // display.setCursor(50, 5);
  // Display static text
  // float cool_sys_pr=0.0;
  display.println(LO_aft_trans1, 1);
  display.display(); 

  tcaselect(2);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // // Display static text
  LO_aft_PIS = 0;
  display.println(LO_aft_PIS);
  display.display(); 

  
  // Write to OLED on bus number 1
  tcaselect(3);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  LO_sump_level=0;
  display.println(LO_sump_level);
  display.display(); 

  tcaselect(4);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  int steam_system_water_temp_2=25;
  display.println(steam_system_water_temp_2);
  display.display(); 

  
  // Write to OLED on bus number 1
  tcaselect(5);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  int cool_sytem_temp_2=25;
  display.println(cool_sytem_temp_2);
  display.display(); 

  // Write to OLED on bus number 1
  tcaselect(6);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  int cool_sytem_temp_2A=25;
  display.println(cool_sytem_temp_2);
  display.display(); 

  // Write to OLED on bus number 1
  tcaselect(7);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  int cool_sytem_temp_2B=0;
  display.println(cool_sytem_temp_2);
  display.display(); 

}

int alarm_en=0;
void diplayLO_sump_level(){
  tcaselect(3);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  if(LO_sump_level>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(LO_sump_level>70 && alarm_en == 0){Serial.println("ALM");if(LO_sump_level>75) alarm_en = 4;}
  if(LO_sump_level<180 && display_[3]==4) LO_sump_level=LO_sump_level+2;
  display.println(LO_sump_level);
  display.display(); 
}

void diplayLO_aft_PSI(){
  tcaselect(2);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  if(LO_aft_PIS < 60 && display_[2]==4){LO_aft_PIS = LO_aft_PIS + 5;}
  if(display_[2]==2){LO_aft_PIS = 30;}
  if(LO_aft_PIS > 30 && display_[2]==8){LO_aft_PIS = LO_aft_PIS - 5;}
  display.println(LO_aft_PIS);
  display.display(); 
}

void diplayLO_bef_PSI(){
  tcaselect(7);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  if(display_[7]==2){LO_bef_PIS = 30;}
  display.println(LO_bef_PIS);
  display.display(); 
}

void display_LO_aft_trans1(){
  tcaselect(1);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(10, 5);
  if(LO_aft_trans1 < 0.3 && display_[1]==4){LO_aft_trans1 = LO_aft_trans1 + 0.1;}
  if(LO_aft_trans1 > 0 && display_[1]==8){LO_aft_trans1 = LO_aft_trans1 - 0.1;}
  display.println(LO_aft_trans1, 1);
  display.display(); 
}

void display_LO_aft_trans2(){
  tcaselect(0);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(10, 5);
  if(LO_aft_trans2 < 0.3 && display_[0]==4){LO_aft_trans2 = LO_aft_trans2 + 0.1;}
  if(LO_aft_trans2 > 0 && display_[0]==8){LO_aft_trans2 = LO_aft_trans2 - 0.1;}
  display.println(LO_aft_trans2, 1);
  display.display(); 
}

void display_DG_SW_bef_CIR(){
  tcaselect(4);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(0, 8);
  if(DG_SW_bef_CIR < 0.25 && display_[4]==4){DG_SW_bef_CIR = DG_SW_bef_CIR + 0.05;}
  if(DG_SW_bef_CIR > 0.01 && display_[4]==8){DG_SW_bef_CIR = DG_SW_bef_CIR - 0.05;}
  display.println(DG_SW_bef_CIR, 2);
  display.display(); 
}
uint8 SW_bef_CIR_TEMP=22;
void diplaySW_bef_CIR_TEMP(){
  tcaselect(5);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  if(SW_bef_CIR_TEMP < 28 && display_[5]==4){SW_bef_CIR_TEMP = SW_bef_CIR_TEMP + 1;}
  display.println(SW_bef_CIR_TEMP);
  display.display(); 
}

float SW_bef_CIR_PRS=0;

void display_SW_bef_CIR_PRS(){
  tcaselect(6);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(0, 8);
  if(SW_bef_CIR_PRS < 0.35 && display_[6]==4){SW_bef_CIR_PRS = SW_bef_CIR_PRS + 0.05;}
  // if(SW_bef_CIR_PRS > 0.01 && display_[4]==8){SW_bef_CIR_PRS = SW_bef_CIR_PRS - 0.05;}
  display.println(SW_bef_CIR_PRS, 2);
  display.display(); 
}