//#include <Servo.h>
//Servo servo;
//
// int angle = 0;
// int pot = A0;
// int servoPin = 9;
//
// void setup() {
//  // put your setup code here, to run once:
//  servo.attach(servoPin);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  angle = analogRead(pot);
//  angle = map(angle, 0, 1023, 0 ,179);
//  servo.write(angle);
//  delay(15);
//
//}
//

#include <Servo.h>

Servo myservo; // create servo object to control a servo 

int potpin = 0; // analog pin used to connect the potentiometer
int val; // variable to read the value from the analog pin 

void setup() 
{ 
myservo.attach(9); // attaches the servo on pin 9 to the servo object 
} 

void loop() 
{ 
val = analogRead(potpin); // reads the value of the potentiometer (value between 0 and 1023) 
val = map(val, 0, 1023, 0, 179); // scale it to use it with the servo (value between 0 and 180) 
myservo.write(val); // sets the servo position according to the scaled value 
delay(15); // waits for the servo to get there 
}
