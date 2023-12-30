#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_I2C_ADDR 0x3C // I2C address for the OLED display
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

const int red = 2; 
const int yellow = 3;
const int blue = 4; 
const int white = 5;

void setup() {

  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(white,OUTPUT);

  // initialize with the I2C addr 0x3C (for the 128x64)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer
  display.clearDisplay();

  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Display "Hello, World!" at coordinates (0, 0)
  display.setCursor(20,20 );
  display.println(F("Hello, Yann!"));

  // Display on the screen
  display.display();
}

void loop() {
  display.setCursor(20,20 );
  display.println(F("Hello, Yann!"));
  display.setCursor(50, 40);
  display.display();
  delay(500);
  display.clearDisplay();
  delay(500);
}
