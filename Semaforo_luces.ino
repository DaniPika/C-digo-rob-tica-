const int interruptorPin = 2; // Pin donde está conectado el interruptor
const int led1Pin = 5; // Pin donde está conectado el LED 1
const int led2Pin = 9; // Pin donde está conectado el LED 2

int estadoInterruptor;
int i = 0; //variable de posicion de estado
bool barrera = false; //booleano que indica el estado de la suma

void setup() {
  pinMode(interruptorPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  estadoInterruptor = digitalRead(interruptorPin);

  if (estadoInterruptor == HIGH) {

    barrera = false;

    if(i == 0){

      lucesEncendidas();
    }else  if (i == 1){

      lucesSemaforo();
    }else if(i == 2){

      lucesApagadas();
    }else{

      i=0;
    }

  } else if (estadoInterruptor == LOW) {
    
    if(barrera == false)
    {
      i++;
      barrera = true;
    }
  }
}

void lucesEncendidas(){

  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
}

void lucesSemaforo(){

  delay(150);
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, LOW);

  delay(150);
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, HIGH);
}

void lucesApagadas(){

  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
}