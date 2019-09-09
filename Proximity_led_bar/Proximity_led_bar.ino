/* by Caio Camatta*/
int trigPin = 13; //Sensor Trip pin connected to Arduino pin 13
int echoPin = 12; //Sensor Echo pin connected to Arduino pin 11
int myCounter = 0; //declare your variable myCounter and set to 0
float pingTime;  //time for ping to travel from sensor to target and return
float targetDistance; //Distance to Target in cm
float speedOfSound = 1234.8; //Speed of sound in kilometers per hour.

int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  for (int i = 0; i < 10;  i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {

  digitalWrite(trigPin, LOW); //Set trigger pin low
  delayMicroseconds(2000); //Let signal settle
  digitalWrite(trigPin, HIGH); //Set trigPin high
  delayMicroseconds(15); //Delay in high state
  digitalWrite(trigPin, LOW); //ping has now been sent
  delayMicroseconds(10); //Delay in high state

  pingTime = pulseIn(echoPin, HIGH);  //pingTime is presented in microceconds
  if (pingTime < 5831) { //this is used to limit the distance to 100cm, if the distance is higher than this, it won't change the targetDistance
    pingTime = pingTime / 1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
    pingTime = pingTime / 3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
    targetDistance = speedOfSound * pingTime; //This will be in miles, since speed of sound was miles per hour
    targetDistance = targetDistance / 2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
    targetDistance = targetDistance * 100000; //Convert km to cm by multipling by 100000 (cm per km)

    if (targetDistance < 101) {
      int ledLevel = map(targetDistance, 0, 100, 0, 10);

      for (int level = 0; level < 10; level++) {
        if (level < ledLevel) {
          digitalWrite(leds[level], HIGH);
        }
        else {
          digitalWrite(leds[level], LOW);
        }
      }
    }
    else{
      for (int level = 0; level < 10; level++) {
          digitalWrite(leds[level], LOW);
      }
    }
    delay(100); //pause to let things settle
  }
}
