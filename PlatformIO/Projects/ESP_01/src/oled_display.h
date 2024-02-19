#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define TCAADDR 0x70

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


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

  // Write to OLED on bus number 0 DG1
  tcaselect(0);//DG1
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  //display.setCursor(50, 5);
  int cool_sys_temp_1=0;
  // Display static text
  display.println(cool_sys_temp_1);
  display.display(); 

  
  // Write to OLED on bus number 1
  tcaselect(1);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(10, 5);
  // display.setCursor(50, 5);
  // Display static text
  float cool_sys_pr=0.0;
  display.println(cool_sys_pr, 1);
  display.display(); 

  tcaselect(2);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(10, 5);
  // Display static text
  float steam_system_pr=0;
  display.println(steam_system_pr, 1);
  display.display(); 

  
  // Write to OLED on bus number 1
  tcaselect(3);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  int steam_system_water_temp_1=25;
  display.println(steam_system_water_temp_1);
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
  int cool_sytem_temp_2B=25;
  display.println(cool_sytem_temp_2);
  display.display(); 

}

int display_UP[8], DG1 = 0, DG2 = 0;
int AL_en[8];


void displayDG1_on(){
  tcaselect(0);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  if(DG1>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(DG1<1800 && display_[0]==4) DG1=DG1+30;
  else if(DG1>0 && display_[0]==8){DG1=DG1-30; if(DG1<100)Serial.println("STOP"); else if(DG1<300)Serial.println("ST3P"); else if(DG1<600)Serial.println("ST2P"); else if(DG1<800)Serial.println("ST1P");} 
  display.println(DG1);
  display.display(); 

}

void displayDG2_on(){
  tcaselect(1);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  if(DG2>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(DG2<1800 && display_[1]==4) DG2=DG2+30;
  else if(DG2>0 && display_[1]==8){DG2=DG2-30; if(DG2<100)Serial.println("STOP"); else if(DG2<300)Serial.println("ST3P"); else if(DG2<600)Serial.println("ST2P"); else if(DG2<800)Serial.println("ST1P");} 
  display.println(DG2);
  display.display(); 

}

uint16 DG1_current = 0;

void diplayDG1_current(){
  tcaselect(2);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  if(DG1_current>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(DG1_current<375 && display_[0]==4) DG1_current=DG1_current+5;
  else if(DG1_current>0 && display_[0]==8){DG1_current=DG1_current-5; } 
  display.println(DG1_current);
  display.display(); 
}

uint16 DG2_current = 0;
void diplayDG2_current(){
  tcaselect(5);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  if(DG2_current>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(DG2_current<375 && display_[1]==4) DG2_current=DG2_current+5;
  else if(DG2_current>0 && display_[1]==8){DG2_current=DG2_current-5; } 
  display.println(DG2_current);
  display.display(); 
}

uint16 DG2_voltage = 0;
void diplayDG2_voltage(){
  tcaselect(4);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  if(DG2_voltage>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(DG2_voltage<390 && display_[1]==4) DG2_voltage=DG2_voltage+5;
  else if(DG2_voltage>0 && display_[1]==8){DG2_voltage=DG2_voltage-5; } 
  display.println(DG2_voltage);
  display.display(); 
}
uint16 DG1_voltage = 0;
void diplayDG1_voltage(){
  tcaselect(3);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  if(DG1_voltage>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(DG1_voltage<390 && display_[0]==4) DG1_voltage=DG1_voltage+5;
  else if(DG1_voltage>0 && display_[0]==8){DG1_voltage=DG1_voltage-5; } 
  display.println(DG1_voltage);
  display.display(); 
}
uint16 SG_voltage = 0;
void diplaySG_voltage(){
  tcaselect(6);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  if(SG_voltage>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(SG_voltage<390 && display_[2]==4) SG_voltage=SG_voltage+5;
  else if(SG_voltage>0 && display_[2]==8){SG_voltage=SG_voltage-5; } 
  display.println(SG_voltage);
  display.display(); 
}
uint16 SG_current = 0;
void diplaySG_current(){
  tcaselect(7);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  if(SG_current>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(SG_current<375 && display_[2]==4) SG_current=SG_current+5;
  else if(SG_current>0 && display_[2]==8){SG_current=SG_current-5; } 
  display.println(SG_current);
  display.display(); 
}