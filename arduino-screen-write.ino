// http://www.adafruit.com/products/1947


#include <Adafruit_GFX.h>    // Core graphics library
#include <SPI.h>       // this is needed for display
#include <Adafruit_ILI9341.h>
#include <Wire.h>      // this is needed for FT6206
#include <Adafruit_FT6206.h>

// The display also uses hardware SPI, plus #9 & #10
#define TFT_CS 10
#define TFT_DC 9
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int counter = 0;
String incomingString;

void setup(void) {
  while (!Serial);     // used for leonardo debugging
 
  Serial.begin(115200);
  Serial.println(F("Dead Night Display"));
  
  
  tft.begin();
  
  
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(5);
  tft.setTextColor(ILI9341_GREEN);
  tft.setRotation(1);
  tft.setCursor(0, 100);
  tft.println("dead night");
  
  incomingString = "";
  
}

void loop() {
  if(Serial.available()){
    char incomingByte = (char)Serial.read();
    if (incomingByte != '\n' && incomingByte != '\r'){
      incomingString += incomingByte;
    }
    
    if (incomingByte == '\n' || incomingByte == '\r') {
      tft.fillScreen(ILI9341_BLACK);
      tft.setCursor(0, 100);
      tft.println(incomingString);
      Serial.println(incomingString); 
      incomingString = "";
    }
  }
  delay(1);
}

unsigned long testText() {
  tft.fillScreen(ILI9341_BLACK);
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(2);
  tft.println(1234.56);
  tft.setTextColor(ILI9341_RED);    tft.setTextSize(3);
  tft.println(0xDEADBEEF, HEX);
  tft.println();
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(5);
  tft.println("Groop");
  tft.setTextSize(2);
  tft.println("I implore thee,");
  tft.setTextSize(1);
  tft.println("my foonting turlingdromes.");
  tft.println("And hooptiously drangle me");
  tft.println("with crinkly bindlewurdles,");
  tft.println("Or I will rend thee");
  tft.println("in the gobberwarts");
  tft.println("with my blurglecruncheon,");
  tft.println("see if I don't!");
  return micros() - start;
}




// Arduino Serial Tester
// rld, cycling'74, 3.2008

//long randomvalue = 0; // random value
//long countervalue = 0; // counter value
//int serialvalue; // value for serial input
//int started = 0; // flag for whether we've received serial yet
//
//void setup()
//{
//  Serial.begin(115200); // open the arduino serial port
//}
//
//void loop()
//{
//  if(Serial.available()) // check to see if there's serial data in the buffer
//  {
//    serialvalue = Serial.read(); // read a byte of serial data
//    started = 1; // set the started flag to on
//  }
//
//  if(started) // loop once serial data has been received
//  {
//    randomvalue = random(1000); // pick a new random number
//    Serial.print(countervalue); // print the counter
//    Serial.print(" "); // print a space
//    Serial.print(randomvalue); // print the random value
//    Serial.print(" "); // print a space
//    Serial.print(serialvalue); // echo the received serial value
//    Serial.println(); // print a line-feed
//    countervalue = (countervalue+1)%1000; // increment the counter
//    delay(100); // pause
//  }
//}
