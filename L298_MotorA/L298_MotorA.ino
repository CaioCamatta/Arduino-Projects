//motor A
int IN1 = 2 ;
int IN2 = 3 ;
 
//Inicializa Pinos
void setup(){
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
}
 
void loop(){ 
 /* MOTOR A */
 //Sentido Horario
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 delay(5000); 
 
 //Freia Motor
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,HIGH);
 delay(5000);
 
 //Sentido Anti-Horario
 digitalWrite(IN1,LOW);
 digitalWrite(IN2,HIGH);
 delay(5000);
 
 //Freia Motor
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,HIGH);
 delay(5000);
}
