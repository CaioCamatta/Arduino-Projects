#include <LiquidCrystal.h>
LiquidCrystal LCD(10, 9, 5, 4, 3, 2);
int photocellPin = 0;
int photocellReading;
int photocellMax = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Current: ");
  LCD.setCursor(0,1);
  LCD.print("Max: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  photocellReading = analogRead(photocellPin);

  if (photocellReading > photocellMax){
    photocellMax = photocellReading;
  }
  
  LCD.setCursor(8,0);
  LCD.print("        ");
  LCD.setCursor(8,0);
  LCD.print(photocellReading);
  LCD.setCursor(5,1);
  LCD.print("           ");
  LCD.setCursor(5,1);
  LCD.print(photocellMax);

  delay(250);
}
