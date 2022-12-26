#include <ESP8266WiFi.h>
#include <GyverOLED.h>

//LCD init
GyverOLED<SSH1106_128x64> oled;

//tank height: 2070mm
#define OVERALL_HEIGHT_CM 207
#define OLED_HEIGHT 64
#define OLED_WIDTH 128

//https://chewett.co.uk/blog/1066/pin-numbering-for-wemos-d1-mini-esp8266/
#define TRIG_PIN D6 
#define ECHO_PIN D5
long duration;
int distance;
int percentsLeft;

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
    percentsLeft = 100 * (OVERALL_HEIGHT_CM - distance) / OVERALL_HEIGHT_CM;
    
    
    oled.setCursor(0, 1);
    oled.print("Расстояние");
    oled.setCursor(0, 2);
    String message =  "до воды:   " + String(distance) + "см";
    oled.print(message);
    
    oled.setCursor(0, 6);
    String message2 = "Осталось   " + String(percentsLeft) + "%";
    oled.print(message2);
  }
  drawRect(percentsLeft);
  oled.update();
  delay(100);
}

void drawRect(int percentsLeft){
  //x1, y1, x2, y2, color
  oled.rect(100, 0, OLED_WIDTH-1, OLED_HEIGHT-1, OLED_STROKE);
  int filledRectTopY = (OLED_HEIGHT-1) - (percentsLeft * (OLED_HEIGHT-1)) / 100;
  oled.rect(100, filledRectTopY, OLED_WIDTH-2, OLED_HEIGHT - 1, OLED_FILL);
}
