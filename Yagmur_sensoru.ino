#include<Servo.h>

#define led 6
#define alarm 7
#define yagmur A0

Servo motor;
int su_miktari ;
int uyari = 0 ;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(alarm,OUTPUT);
  pinMode(yagmur,INPUT);
  motor.attach(9);

  Serial.begin(9600);
 }

void loop() {
  su_miktari = analogRead(yagmur);
  delay(200);
  Serial.print("su miktarı : ");
  Serial.println(su_miktari);
  if(su_miktari < 450){
    digitalWrite(led,HIGH);
    digitalWrite(alarm,HIGH);
    delay(500);
    uyari = uyari + 1;
    if(uyari = 3){
      digitalWrite(led,LOW);
      digitalWrite(alarm,LOW);
      motor.write(90);
      uyari = 0;
    }
  }
  else{
    uyari = 0;
    motor.write(0);
  }
}
