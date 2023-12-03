#include <TinyWireM.h>
#include <Tiny4kOLED.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  TinyWireM.begin();
  mlx.begin();
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
  oled.on();
}

void loop() {
  float temp = mlx.readObjectTempC();
  oled.setFont(FONT6X8);
  oled.setCursor(0,0);
  oled.print("Temperatura = ");
  oled.setCursor(0,10);
  oled.print(temp); 
  delay(3500);
  oled.clear();
}
