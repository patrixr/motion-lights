#include <Adafruit_NeoPixel.h>

/*
 * PIR sensor tester
 */

#define LED_COUNT 60
#define LED_PIN 13

int inputPin = 12;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);

  strip.begin();
  strip.show();

  on();
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == pirState)
    return;
  if (val == HIGH) {            // check if the input is HIGH
      Serial.println("MOTION");
      pirState = HIGH;
      on();
    //}
  } else {
    //digitalWrite(ledPin, LOW); // turn LED OFF
    //if (pirState == HIGH){
      // we have just turned of
      Serial.println("NOTHING");
      off();
      // We only want to print on the output change, not state
      pirState = LOW;
    //}
  }
}


void on(){
  for (int j = 0; j < LED_COUNT; j++) {
    strip.setPixelColor(j, 255, 255, 255);
    strip.show();
  }
}


void off(){
  for (int j = 0; j < LED_COUNT; j++) {
    strip.setPixelColor(j, 0, 0, 0);
    strip.show();
  }
}


