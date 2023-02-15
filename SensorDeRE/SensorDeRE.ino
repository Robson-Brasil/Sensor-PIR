// Sensor de Ré com leds e buzzer
// Autor : Robson Brasil
// Versão : 15
// Última Modificação : 05/07/2020

const int TRIG = 22, ECHO = 23, buzzer = 2;
unsigned int intervalo, distancia;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  
  pinMode(buzzer,OUTPUT);
  
  pinMode(A5,OUTPUT);         // Led Vermelho
  pinMode(A4,OUTPUT);         // Led Amarelo
  pinMode(A3,OUTPUT);         // Led Amarelo
  pinMode(A2,OUTPUT);         // Led Verde
  pinMode(A1,OUTPUT);         // Led Verde
  pinMode(A0,OUTPUT);         // Led Verde
}

void loop() {
  distancia = sensor_morcego(TRIG,ECHO); // Chamada da função de leitura.
  Serial.println(distancia);
  if (distancia <= 10) {       // Distância minima 
    digitalWrite(A0,HIGH);
    digitalWrite(A1,HIGH);
    digitalWrite(A2,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A5,HIGH);
    tone(buzzer, 1750);
  }
  else if (distancia > 50) {  // Acima de 40cm. buzzer e leds desativados
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      digitalWrite(A3,LOW);
      digitalWrite(A4,LOW);
      digitalWrite(A5,LOW);
      noTone(buzzer);
  } 
  else {                      // Condicional para leitura intermediarias.
    if (distancia <= 15) { 
      digitalWrite(A0,LOW);
      digitalWrite(A1,HIGH);
      digitalWrite(A2,HIGH);
      digitalWrite(A3,HIGH);
      digitalWrite(A4,HIGH);
      digitalWrite(A5,HIGH);
      intervalo = 100;
    }
    else if (distancia <= 20) {
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      digitalWrite(A2,HIGH);
      digitalWrite(A3,HIGH);
      digitalWrite(A4,HIGH);
      digitalWrite(A5,HIGH);
      intervalo = 150;
    }
    else if (distancia <= 30) {
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      digitalWrite(A3,HIGH);
      digitalWrite(A4,HIGH);
      digitalWrite(A5,HIGH);
      intervalo = 200;
    }
    else if (distancia <= 40) {
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      digitalWrite(A3,LOW);
      digitalWrite(A4,HIGH);
      digitalWrite(A5,HIGH);
      intervalo = 250;
    }
    else if (distancia <= 50) {
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      digitalWrite(A2,LOW);
      digitalWrite(A3,LOW);
      digitalWrite(A4,LOW);
      digitalWrite(A5,HIGH);
      intervalo = 300;
    }
    tone(buzzer,1750);
    delay(intervalo);
    noTone(buzzer);
    delay(intervalo);
  }
}

int sensor_morcego(int pinotrig,int pinoecho){ // Função para leitura do sensor
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/59;
}
