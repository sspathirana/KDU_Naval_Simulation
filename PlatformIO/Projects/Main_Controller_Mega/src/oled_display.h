#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define TCAADDR 0x70

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int actuator=0;

// Helper function for changing TCA output channel
void tcaselect(uint8_t channel) {
  if (channel > 7) return;
  
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << channel);
  Wire.endTransmission();
  Serial.print(TCAADDR);  
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
  
  // Clear the buffer
  display.clearDisplay();

  // Write to OLED on bus number 0
  tcaselect(0);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  //display.setCursor(50, 5);
  int cool_sys_temp_1=25;
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
  tcaselect(7);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  display.setCursor(30, 5);
  // Display static text
  /* int */ cool_sytem_temp_2=25;
  display.println(cool_sytem_temp_2);
  display.display(); 
}
float Steam_Pressure=0;
uint8_t Steam_Pressure_en=0;
int display_[6];

void display_Steam_Pressure(){
  tcaselect(2);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(0, 8);
  if(Steam_Pressure < 0.8 && display_[2]==4 ){Steam_Pressure = Steam_Pressure + 0.1; }
  // if(SW_bef_CIR_PRS > 0.01 && display_[4]==8){SW_bef_CIR_PRS = SW_bef_CIR_PRS - 0.05;}
  display.println(Steam_Pressure, 1);
  display.display(); 
}
uint16_t Steam_Water_level=0;
uint8_t Steam_Water_level_AL=0;
int alarm_on=0;
void display_Steam_Water_level(){
  tcaselect(4);
  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  if(Steam_Water_level>99) display.setCursor(0, 5); else display.setCursor(30, 5);

  if(Steam_Water_level < 300 && display_[4]==4 ){Steam_Water_level = Steam_Water_level + 2; }
  if(Steam_Water_level > 200 && Steam_Water_level_AL==0){Steam_Water_level_AL=4;alarm_on=4;}
  display.println(Steam_Water_level);
  display.display(); 
}

int FW_aft_ME1=25, FW_aft_ME2=25;

void display_FW_aft_ME(){
  tcaselect(5);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  if(FW_aft_ME1>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(FW_aft_ME1 < 80 && display_[5]==4 ){FW_aft_ME1 = FW_aft_ME1 + 5; }
  display.println(FW_aft_ME1);
  display.display(); 
}

void display_FW_aft_ME2(){
  tcaselect(0);
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(WHITE);
  if(FW_aft_ME2>99) display.setCursor(0, 5); else display.setCursor(30, 5);
  if(FW_aft_ME2 < 70 && display_[5]==4 ){FW_aft_ME2 = FW_aft_ME2 + 5; }
  display.println(FW_aft_ME2);
  display.display(); 
}
