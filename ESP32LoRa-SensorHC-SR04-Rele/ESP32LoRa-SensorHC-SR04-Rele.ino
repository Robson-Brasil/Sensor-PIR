const int trigPin = 2;
const int echoPin = 3;
const int relay = 4;
long Duracao;
int Distancia;
int DistanciaSegura;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT);
pinMode(relay, OUTPUT);// Sets the echoPin as an Input
Serial.begin(115200); // Starts the serial communication
}

void loop() {
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin,LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
Duracao = pulseIn(echoPin,HIGH);
// Calculating the distance
Distancia = Duracao*0.034/2;
Serial.print(Distancia);
Serial.println(" cm");
delay(50);
DistanciaSegura = Distancia;
if((Distancia>=75))
  {
    digitalWrite(relay, HIGH);
}
   else if(Distancia<80)
 {
     digitalWrite(relay, LOW);
   }
}
