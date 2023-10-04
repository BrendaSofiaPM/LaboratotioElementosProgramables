// Codigo Attiny85
//
#include <TinyWireM.h>
#include <Tiny4kOLED.h>
int boton=LOW;
#define pwmPin  3 

void prepareDisplay() {
  oled.clear();
  oled.begin();
  oled.setFont(FONT6X8);
  
}

void setup()
{
  pinMode(4, INPUT);
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
 //oled.setRotation(0);
 // Two fonts are supplied with this library, FONT8X16 and FONT6X8
 // To clear all the memory
    oled.clear();
    oled.on();
    prepareDisplay();
    oled.setFont(FONT8X16);  

}


void loop()
{
  boton=digitalRead(4);
  
  if(boton==HIGH){

    oled.setCursor(5,1);
  oled.print(F("ON  "));
  }
  else{
    
    oled.setCursor(5,1);
  oled.print(F("OFF"));
  }
}