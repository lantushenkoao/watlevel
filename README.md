# watlevel
Water level sensor

#Hardware
Wemos (ESP 2866)
LCD SH1106
AJ SR04M Ultrasonic sensor

#Wemos setup
(board manager URL is)
http://arduino.esp8266.com/stable/package_esp8266com_index.json
Then select LOLIN (Wemos) D1 R2 in Tools->Board
https://www.instructables.com/Arduino-WeMos-D1-WiFi-UNO-ESP-8266-IoT-IDE-Compati/

#LCD setup
SCK-->D1 --> Wemos D15(SCL)
SDA-->D2 --> Wemos D14(SDA)
LCD controller is SH1106 (not SSD1306) and therefore it's having issues with Adafruit
https://forum.arduino.cc/t/oled-1-3-i2c-iic-128x64-serial-lcd-faulty/250171/16
Using GyverOLED with GyverOLED<SSH1106_128x64> oled solves the issue