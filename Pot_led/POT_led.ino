int led = 3;
int pot = 3;
int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(pot);
  val = map(val, 1, 1023, 1, 255);
  analogWrite(led, val);
}
