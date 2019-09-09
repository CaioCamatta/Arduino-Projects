int A = 2;
int B = 3;
int C = 4;
int D = 5;
int sA = 0;
int sB = 0;
int sC = 0;
int sD = 0;

int piezo = 13;

int tones[] = {1915, 1519, 1275, 1014};
int Cur_tone = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(piezo, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  sA = digitalRead(A);
  sB = digitalRead(B);
  sC = digitalRead(C);
  sD = digitalRead(D);
  
  if ((sA == HIGH) || (sB == HIGH) || (sC == HIGH) || (sD == HIGH)){
    if(sA == HIGH){
      Cur_tone = tones[0];
    }
    if(sB == HIGH){
      Cur_tone = tones[1];
    }
    if(sC == HIGH){
      Cur_tone = tones[2];
    }
    if(sD == HIGH){
      Cur_tone = tones[3];
    }
    digitalWrite(piezo, HIGH);
    delayMicroseconds(Cur_tone);
    digitalWrite(piezo, LOW);
    delayMicroseconds(Cur_tone);
  }
  else {
    digitalWrite(piezo, LOW);
  }
}

