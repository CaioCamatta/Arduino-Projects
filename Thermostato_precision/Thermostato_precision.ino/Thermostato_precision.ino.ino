#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tPin = 0;

float tAverage[10];
int avgLen = 10;
float finalT;
float maxT;
float minT;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.setCursor(0, 1);
  lcd.print("Ma:");
  lcd.setCursor(8, 1);
  lcd.print("Mi:");

  
  float voltage, degreesC;
  voltage = analogRead(tPin) * 0.004882814;
  degreesC = voltage * 100.0;
  minT = degreesC;
}

void loop() {
  float voltage, degreesC;
  voltage = analogRead(tPin) * 0.004882814;
  degreesC = voltage * 100.0;

  

  for (int k = 1; k < avgLen; k++) { //loop that runs 9 times
    tAverage[k - 1] = tAverage[k]; // removes the first value of the array and brings all the others 1 position down
  }
  tAverage[avgLen - 1] = degreesC; // the last value of the array is set to the last target distance recieved
  
  for (int k = 1; k < avgLen; k++) { //loop that runs 10 times
    finalT += tAverage[k]; //adds all the values inside the array to distance
  }
  finalT = finalT / avgLen; //gets the average
  


  if (degreesC > maxT){
    maxT = degreesC;
  }
  if (degreesC < minT){
    minT = degreesC;
  }

  lcd.setCursor(5, 0);
  lcd.print(finalT);
  lcd.print("C");
  lcd.setCursor(3, 1);
  lcd.print(maxT);
  lcd.setCursor(11, 1);
  lcd.print(minT);


  delay(300);
}

