/*      ATTINY85                            Out/10/2022          Esdras Silva
    Programa Display e Temperatura NTC100K a 25C 
     oled.setFont(FONT6X8);
     oled.setFontX2(FONT6X8);
     oled.setFont(FONT8X16);
     oled.setFont(FONT8X16);
 */


#include <TinyWireM.h>
#include <Tiny4kOLED.h>

#define pwmPin  3  	// digital PWM pin 9 - SAIDA
#define enPin   4   // habiita sinais PWM
unsigned int rpm;

const float BETA = 3950; // should match the Beta Coefficient of the thermistor

void prepareDisplay() {
  oled.clear();
  oled.begin();
  oled.setFont(FONT6X8);
  oled.setCursor(5,1);
  oled.print(F("TEMP:"));
  oled.setCursor(5,3);
  oled.print(F("RPM:")); 
}

void setup() {
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
 //oled.setRotation(0);
 // Two fonts are supplied with this library, FONT8X16 and FONT6X8
 // To clear all the memory
    oled.clear();
    oled.on();
    prepareDisplay();
    oled.setFont(FONT8X16);  
}

void loop() {
  
  static long startTime = 0;
  long currentTime;
  int analogValue = analogRead(PB3);
  // Get current time
  currentTime = millis();
  float rpm=1234.7;

  // Checks 1 second passed
  if ((currentTime - startTime) > 1000) {
    startTime = currentTime;
    float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15; 
    // Print to display
    oled.setCursor(48, 0);
    oled.print(celsius, 1);
    oled.print(" C");
    oled.setCursor(48, 2);
    oled.print(rpm, 1);
    oled.print(" RPM");  
  }

 
}