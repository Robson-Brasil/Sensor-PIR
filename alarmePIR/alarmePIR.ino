
const int PIR = 22;     // pino sinal sensor de presença
const int buzzer = 2;
const int led =  23;      

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(PIR, INPUT);
}

void loop() {
  // leitura do sensor
  int leitura = digitalRead(PIR);
  Serial.println(leitura);
  delay(500); // delay 500ms para estabilizar sinal de leitura
  
  // verifica se leitura está em nivel alto
  if (leitura == HIGH) {
    digitalWrite(led, HIGH);
    tone(buzzer,1200,500);   
    delay(100);
    noTone(buzzer);
    delay(100);
  //Desligando o buzzer.  
  } else {
    digitalWrite(led, LOW);
    noTone(buzzer);
  }
}
