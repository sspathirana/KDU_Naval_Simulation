#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 11; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 12; // Connects to module's TX 

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
// Create the Player object
DFRobotDFPlayerMini player;

void setupDF(){
  softwareSerial.begin(9600);

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
//    Serial.println("OK");

//     // Set volume to maximum (0 to 30).
    player.volume(30);
//     // Play the first MP3 file on the SD card
    // player.play(1);
    // player.stop();
    }
//   } else {
//     Serial.println("Connecting to DFPlayer Mini failed!");
//   }

}

void engineStart(){
    player.play(1);
    // if(player.begin(softwareSerial))Serial.println("Okay");
    // Set volume to maximum (0 to 30).
    //player.volume(30);
    // Play the first MP3 file on the SD card
    // player.play(1);
}

void engineStop(){
    player.stop();
}