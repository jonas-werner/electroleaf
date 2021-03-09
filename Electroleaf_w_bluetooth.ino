#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN    9  // Use 220-470 Ohm resistor
#define PIXEL_COUNT  54 // Set number of LEDs in WS2812B strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int showType = 0;
int state = 0;


void setup() {
  strip.begin();
  strip.show();       // Initialize all pixels to 'off'
  Serial.begin(9600); // Bluetooth module baud rate
}

// Capture commands sent from the Android app to the BT module
void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
  state = Serial.read();      // Reads the data from the serial port
  if (state == '0') {
    showType=0;
    startShow(showType);
    }
  if (state == '1') {
    showType=1;
    startShow(showType);
    }
  if (state == '2') {
    showType=2;
    startShow(showType);
    }
  if (state == '3') {
    showType=3;
    startShow(showType);
    }
  if (state == '4') {
    showType=4;
    startShow(showType);
    }
  if (state == '5') {
    showType=5;
    startShow(showType);
    }    
  }

}

// Set the LED color based on what option the user selected in the app
void startShow(int i) {
  switch(i){
    case 0: colorWipe(strip.Color(0, 0, 0), 0);       // Black/off
            break;
    case 1: colorWipe(strip.Color(255, 0, 0), 0);     // Red
            break;
    case 2: colorWipe(strip.Color(0, 255, 0), 0);     // Green
            break;
    case 3: colorWipe(strip.Color(0, 0, 255), 0);     // Blue
            break;
    case 4: colorWipe(strip.Color(255, 100, 0), 0);   // Gold
            break;
    case 5: colorWipe(strip.Color(100, 245, 228), 0); // Diamond
            break;            
  }
}


// Fill the LEDs in sequence
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
