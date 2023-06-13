#include <Adafruit_CircuitPlayground.h>

// BOP IT ver -0.5
// Nicole Shaffer

//////////////RULES/////////////////
// Green = Left
// Red = Right
// Yellow = Shout
// Goal is 20 points without missing any
// Game stops when you hit 20 points
////////////////////////////////////


//VARIABLES//
    int sound;
    int light;
    int lightpin;
    int score;
    int number;
    int value;
    
    bool leftButtonPressed;
    bool rightButtonPressed;
    bool gaming;

    const byte numPins = 9;
    byte pins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  CircuitPlayground.clearPixels();
    score = 0;
    number = 0;
  
}

void loop() {
  value = CircuitPlayground.mic.soundPressureLevel(10);
  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();

//1 - BUTTON
CircuitPlayground.clearPixels();
delay(500);
CircuitPlayground.setPixelColor(0, 0xE60000);
CircuitPlayground.setPixelColor(1, 0xE60000);
CircuitPlayground.setPixelColor(2, 0xE60000);
CircuitPlayground.setPixelColor(3, 0xE60000);
CircuitPlayground.setPixelColor(4, 0xE60000);
CircuitPlayground.setPixelColor(5, 0xE60000);
CircuitPlayground.setPixelColor(6, 0xE60000);
CircuitPlayground.setPixelColor(7, 0xE60000);
CircuitPlayground.setPixelColor(8, 0xE60000);
CircuitPlayground.setPixelColor(9, 0xE60000);

gaming = true;

if ((rightButtonPressed) and (gaming = true)){
  score = score + 1;
}

delay(1000);
gaming = false;
Serial.print(score);

delay(1000);
CircuitPlayground.clearPixels();
delay(500);
CircuitPlayground.setPixelColor(0, 0xE6EE00);
CircuitPlayground.setPixelColor(1, 0xE6EE00);
CircuitPlayground.setPixelColor(2, 0xE6EE00);
CircuitPlayground.setPixelColor(3, 0xE6EE00);
CircuitPlayground.setPixelColor(4, 0xE6EE00);
CircuitPlayground.setPixelColor(5, 0xE6EE00);
CircuitPlayground.setPixelColor(6, 0xE6EE00);
CircuitPlayground.setPixelColor(7, 0xE6EE00);
CircuitPlayground.setPixelColor(8, 0xE6EE00);
CircuitPlayground.setPixelColor(9, 0xE6EE00);

if ((value > 65)and (gaming=true)){
  score = score + 1;
}

delay(1000);
gaming = false;
Serial.print(score);

CircuitPlayground.clearPixels();
delay(500);
CircuitPlayground.setPixelColor(0, 0x14EE00);
CircuitPlayground.setPixelColor(1, 0x14EE00);
CircuitPlayground.setPixelColor(2, 0x14EE00);
CircuitPlayground.setPixelColor(3, 0x14EE00);
CircuitPlayground.setPixelColor(4, 0x14EE00);
CircuitPlayground.setPixelColor(5, 0x14EE00);
CircuitPlayground.setPixelColor(6, 0x14EE00);
CircuitPlayground.setPixelColor(7, 0x14EE00);
CircuitPlayground.setPixelColor(8, 0x14EE00);
CircuitPlayground.setPixelColor(9, 0x14EE00);

  gaming = true;

if ((leftButtonPressed) and (gaming = true)){
  score = score + 1;
}

delay(1000);

  gaming = false;

Serial.print(score);

if (score == 20){
  CircuitPlayground.playTone(500, 100);
  CircuitPlayground.playTone(500, 100);
  CircuitPlayground.playTone(500, 100);
  Serial.print("   SCORE: ");
  Serial.print(score);
  CircuitPlayground.clearPixels();
  delay(10000000);
}

//END

}
