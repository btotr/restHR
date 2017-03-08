#include <Ticker.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
/*#include "CayenneDefines.h"
#include "CayenneWiFi.h"
#include "CayenneWiFiClient.h"*/

#define OLED_RESET 0  // This is a dummy pin, as the display I have only has 4 Pins-SDA,SCL,GND,Vcc...
Adafruit_SSD1306 display(OLED_RESET);

// Set the Screen for the Pulse display
const int WIDTH=128;
const int HEIGHT=64;
const int LENGTH=WIDTH;

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = ""; // Insert your token here
char ssid[] = ""; // Insert your SSID here
char pwd[] = ""; // Insert your SSID password here

// The Ticker/flipper routine
Ticker flipper;

//  VARIABLES
int blinkPin = 15;                // pin to blink led at each beat
int fadePin = 12;                 // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin


// these variables are volatile because they are used during the interrupt service routine!
volatile int BPM;                   // used to hold the pulse rate
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // holds the time between beats, must be seeded! 
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

// For the display

int x;
int y[LENGTH];

void clearY(){
  for(int i=0; i<LENGTH; i++){
    y[i] = -1;
  }
}

void drawY(){
  display.drawPixel(0, y[0], WHITE);
  for(int i=1; i<LENGTH; i++){
    if(y[i]!=-1){
      display.drawLine(i-1, y[i-1], i, y[i], WHITE);
    }else{
      break;
    }
  }
}


void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
  delay(20);
  // Clear the buffer.
  display.clearDisplay();
  
  x = 0;
  clearY();
  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS
  //Cayenne.begin(token, ssid, pwd);
  
}



void loop(){
    Serial.print("test")
  y[x] = map(Signal, 0, 1023, HEIGHT-14, 0); // Leave some screen for the text.....
    drawY();
  x++;
  if(x >= WIDTH){
        display.clearDisplay();
  display.drawLine(0, 51, 127, 51, WHITE);
  display.drawLine(0, 63, 127, 63, WHITE);
  display.setTextSize(0);
  display.setTextColor(WHITE);
  display.setCursor(0,54);
        display.print(" BPM = ");
        display.print(BPM);
        display.print("  IBI = ");
        display.print(IBI);
        display.print("  ");
    x = 0;
    clearY();
  }
     
  //Cayenne.run();

  display.display();   
  delay(10);                             //  take a break
}


CAYENNE_OUT(V13)
{
    Cayenne.virtualWrite(V13, BPM);
}

