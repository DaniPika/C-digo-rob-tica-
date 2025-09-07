#include <Servo.h>

const int botonPin = 2; // Pin donde está conectado el botón
const int servo1Pin = 7; // Pin donde está conectado el servo 1
const int servo2Pin = 11; // Pin donde está conectado el servo 2

Servo servo1;
Servo servo2;

int anguloInicial = 90; // Ángulo inicial de los servos
int anguloGiro = 30;    // Ángulo de giro de los servos
int anguloGiro1 = 10;   //Ángulo de giro de los servos para girar
int i;                  //variable para contabilizar las ppulsaciones dadas

bool barrera = true;    //Barrera del "mando"

void setup() {
  pinMode(botonPin, INPUT);

  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  servo1.write(anguloInicial);
  servo2.write(anguloInicial);
}

void loop()
 {
  if (digitalRead(botonPin) == HIGH)
  {
    if(i == 1){
      moverRuedas();
      barrera = false;
    }

    if(i == 2){
      detenerRuedas();
      barrera = false;
    }

    if(i==3){
      girarRuedasI();
      barrera = false;
    }

    if(i==4)   {
      girarRuedasD();
      barrera = false;

    }   
  }
  else
  {
    if(barrera == false)
    {
      i++;
      barrera = true;
    }
    
  }
}
void moverRuedas() {
  servo1.write(anguloInicial - anguloGiro);
  servo2.write(anguloInicial + anguloGiro);
}

void detenerRuedas() {
  servo1.write(anguloInicial);
  servo2.write(anguloInicial);
}

void girarRuedasD() {
  servo1.write(anguloInicial - anguloGiro);
  servo2.write(anguloInicial + anguloGiro1);
}

void girarRuedasI(){
  servo1.write(anguloInicial - anguloGiro1);
  servo2.write(anguloInicial + anguloGiro);
}
