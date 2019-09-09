#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Temperature:");  
}

void loop() {
  lcd.setCursor(12,0);
  lcd.print("degreesC");
}

