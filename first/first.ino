#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, PIN, NEO_GRB + NEO_KHZ400);
    
void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
   Serial.begin(57600); 
   // writes a messages on serial
  Serial.println("Setup done!!!");
}

int i;
int j=0;

void loop() {
  for(i = 0; i < 10; i++) {
    strip.setPixelColor(i, j*10, 0, i*25);
    Serial.print(i);
    Serial.print(' ');
    Serial.println(j);
    j=j+1;
    if (j>25)
       j = 0;
 }
 strip.show();
 delay(500);
}
