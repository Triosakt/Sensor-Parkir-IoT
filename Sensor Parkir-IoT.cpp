#include <Adafruit_SSD1306.h>
#include <Wire.h>


#define echo 12
#define trig 13
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define oled_reset -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, oled_reset);

int buzzer = 10;

void setup() {
  Serial.begin(115200);
  Serial.println(" Trio sakti ardika");
   Serial.println(" 2257051012");

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  Wire.begin();
  
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int waktu = pulseIn(echo,HIGH);
  int jarak = waktu * 0.034 / 2;

  Serial.print("jarak :");
  Serial.print(jarak);
  Serial.println("CM");

  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,2);
  display.print("jarak: ");
  display.print(jarak);
  display.println("CM");
  display.display();
  
  
  int buzzerDelay = map(jarak, 0, 150,200, 20);

  if(jarak < 171){
    tone(buzzer, 5000, buzzerDelay);
  }
  else{
    noTone(buzzer);
  }
   delay(150);
}