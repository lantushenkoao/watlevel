#include <ESP8266WiFi.h>
#include <GyverOLED.h>

//LCD init
GyverOLED<SSH1106_128x64> oled;


//#define TRIG_PIN D6
//#define ECHO_PIN D7

//https://chewett.co.uk/blog/1066/pin-numbering-for-wemos-d1-mini-esp8266/
#define TRIG_PIN D6 
#define ECHO_PIN D5
long duration;
int distance;


void setup() {
  Serial.begin(9600);
  delay(500);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  oled.init();       
}

void loop() {
  oled.clear();
  oled.home();
  oled.autoPrintln(true);
  oled.setScale(1);

  digitalWrite(TRIG_PIN, LOW);
  //delayMicroseconds(2);
  delay(10);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  //duration = pulseIn(ECHO_PIN, HIGH, 200 * 1000);
  duration = pulseIn(ECHO_PIN, HIGH);
  Serial.println(duration);
  if(duration == 0){
    oled.print("Нет сигнала");  
  } else {
    distance = duration*0.034/2;
    String message = "Расстояние: " + String(distance) + "см";
    oled.print(message);
  }
  oled.update();
  delay(100);
}
