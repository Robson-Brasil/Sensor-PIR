const int SensorPin = 22;// the Arduino pin connected to output (middle) wire of sensor
36
void setup() {
  Serial.begin(115200);// setup Serial Monitor to display information
   Serial.println("Sensor de Movimento");
   Serial.println("HC-SR501 com ativação do rele");
  pinMode(SensorPin, INPUT);// Define SENSOR_PIN as Input from sensor
  pinMode(RelePin, OUTPUT);// Define RELAY_PIN as OUTPUT for relay
}

void loop() {
  
  int motion =digitalRead(SensorPin);// read the sensor pin and stores it in "motion" variable
 
  // if motion is detected
  if(motion){
    Serial.println("Movimento Detectado");
    digitalWrite(RelePin, LOW);// Turn the relay ON
  }else{
     Serial.println("===Sem Movimento");
     digitalWrite(RelePin,HIGH);// Turn the relay OFF
  }
  delay(500);
  
}
