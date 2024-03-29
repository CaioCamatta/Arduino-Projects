/* by Caio Camatta*/

#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 5, 4, 3, 2);  //Create Liquid Crystal Object called LCD
 
int trigPin=13; //Sensor Trip pin connected to Arduino pin 13
int echoPin=11;  //Sensor Echo pin connected to Arduino pin 11
int myCounter=0;  //declare your variable myCounter and set to 0
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in cm
float speedOfSound=1234.8; //Speed of sound in kilometers per hour.
float aproxDistance[10]; //creates an array of 10 (you can change this) floats. later on we will get the average of this numbers
float distance; //the final distance to display
int len = sizeof(aproxDistance) / sizeof(aproxDistance[0]); //lenght of the array, for convenience if you want to change the number of itens in the array
 
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   
  LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
  LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("Target Distance:");  //Print Message on First Row
}
 
void loop() {
  
  digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(trigPin, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in high state
  
  pingTime = pulseIn(echoPin, HIGH);  //pingTime is presented in microceconds
  if(pingTime < 5831){ //this is used to limit the distance to 100cm, if the distance is higher than this, it won't change the targetDistance
    pingTime=pingTime/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
    pingTime=pingTime/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
    targetDistance= speedOfSound * pingTime;  //This will be in miles, since speed of sound was miles per hour
    targetDistance=targetDistance/2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
    targetDistance= targetDistance*100000;    //Convert km to cm by multipling by 100000 (cm per km)


    for (int k = 1; k < len; k++){ //loop that runs 4 times
      aproxDistance[k-1] = aproxDistance[k]; // removes the first value of the array and brings all the others 1 position down
    }
    aproxDistance[len-1] = targetDistance; // the last value of the array is set to the last target distance recieved


    for (int k = 0; k < len; k++){ //loop that runs 5 times
      distance += aproxDistance[k]; //adds all the values inside the array to distance
    }
    distance = distance/len; //gets the average
  }

  
  LCD.setCursor(0,1);  //Set cursor to first column of second row
  LCD.print("                "); //Print blanks to clear the row
  LCD.setCursor(0,1);   //Set Cursor again to first column of second row
  LCD.print(targetDistance); //Print measured distance
  LCD.print(" cm");  //Print your units.
  delay(250); //pause to let things settle
  }
