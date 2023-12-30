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

const int echo = 8;
const int trig = 7;

const int topDistance = 100;

void setup() {

  //set LEDs
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(white,OUTPUT);

  //set Sensor
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  // initialize with the I2C addr 0x3C (for the 128x64)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.display();
}

int GetDistance(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  long duration = pulseIn(echo,HIGH);
  float distance = (duration * 0.0343) / 2; //in centimeter

  return distance;
}

void loop() {

  float distance = GetDistance();

  display.setCursor(0,20 );
  display.println(F("Distance:"));
  display.print(distance);
  display.print(F("cm"));
  display.setCursor(50, 40);
  display.display();
  delayMicroseconds(2);
  display.clearDisplay();
 

  lightControl(distance);

}

void lightControl(float distance){
    if(distance < topDistance/16){
    digitalWrite(red,1);
    digitalWrite(blue,0);
    digitalWrite(yellow,0);
    digitalWrite(white,0);

    delay(500);

    digitalWrite(red,0);
    digitalWrite(blue,0);
    digitalWrite(yellow,0);
    digitalWrite(white,0);

    delay(500);
  }else if(distance < topDistance/8){
    digitalWrite(red,0);
    digitalWrite(blue,1);
    digitalWrite(yellow,0);
    digitalWrite(white,0);

    delay(500);

    digitalWrite(red,0);
    digitalWrite(blue,0);
    digitalWrite(yellow,0);
    digitalWrite(white,0);
  }else if(distance < topDistance/4){
    digitalWrite(red,0);
    digitalWrite(blue,0);
    digitalWrite(yellow,1);
    digitalWrite(white,0);

    delay(500);

    digitalWrite(red,0);
    digitalWrite(blue,0);
    digitalWrite(yellow,0);
    digitalWrite(white,0);
  }else if(distance < topDistance/2){
    digitalWrite(red,0);
    digitalWrite(blue,0);
    digitalWrite(yellow,0);
    digitalWrite(white,1);

    delay(500);

    digitalWrite(red,0);
    digitalWrite(blue,0);
    digitalWrite(yellow,0);
    digitalWrite(white,0);
  }else{
    digitalWrite(red,0);
    digitalWrite(blue,0);
    digitalWrite(yellow,0);
    digitalWrite(white,0);
  }
}
