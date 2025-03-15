

#include <HCSR04.h>
#include <NewPing.h>

#include <HCSR04.h>

#include <HCSR04.h>

#define ena 10
#define enb 11
#define in1  7
#define in2  6
#define in3  5
#define in4  4
#define echo 8
#define trig 9
int distancia = 0;

UltraSonicDistanceSensor ultrassonico(trig, echo);

void setup(){
  Serial.begin(9600);
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void parar(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(ena, 0);
  analogWrite(enb, 0);
}

void frente(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ena, 100);
  analogWrite(enb, 150);
}

void tras(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ena, 200);
  analogWrite(enb, 200);
}

void direita(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ena, 200);
  analogWrite(enb, 200);
}

void esquerda(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ena, 200);
  analogWrite(enb, 200);
}

void loop(){
  distancia = (ultrassonico.measureDistanceCm());
  if(distancia <= 9){
    parar();
    delay(300);
    esquerda();
    delay(500);
    parar();
    delay(300);
    distancia = (ultrassonico.measureDistanceCm());
    if(distancia <= 9){
      direita();
      delay(1000);
      parar();
      delay(300);
      distancia = (ultrassonico.measureDistanceCm());
      if(distancia <= 9){
        direita();
        delay(500);
        parar();
        delay(300);
      }
    }
  } else{
    frente();
    delay(100);
  }
}
