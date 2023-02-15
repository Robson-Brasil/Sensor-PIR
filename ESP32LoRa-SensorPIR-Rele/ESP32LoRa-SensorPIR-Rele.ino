/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/
#include <WiFi.h>
#include <SPI.h> //lib para comunicação serial
#include <LoRa.h> //lib para comunicação com o WIFI Lora
#include <Wire.h>  //lib para comunicação i2c
#include "SSD1306.h" //lib para comunicação com o display

#define timeSeconds 3

// Set GPIOs for LED and PIR Motion Sensor
const int led = 23;
const int motionSensor = 22;

// Timer: Auxiliary variables
unsigned long now = millis();
unsigned long lastTrigger = 0;
boolean startTimer = false;

// Checks if motion was detected, sets LED HIGH and starts a timer
void IRAM_ATTR detectsMovement() {
  //Serial.println("MOTION DETECTED!!!"); //--> Se não ficar comentado, causa Panic Error no Core 0(Guru Meditation Error: Core  1 panic'ed (Interrupt wdt timeout on CPU1))
  digitalWrite(led, LOW);
  startTimer = true;
  lastTrigger = millis();
}

void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  // PIR Motion Sensor mode INPUT_PULLUP
  pinMode(motionSensor, INPUT_PULLUP);
  // Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);

  // Set LED to LOW
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
}

void loop() {
  // Current time
  now = millis();
  // Turn off the LED after the number of seconds defined in the timeSeconds variable
  if(startTimer && (now - lastTrigger > (timeSeconds*1000))){
    Serial.println("Sem Movimento...");
    digitalWrite(led, HIGH);
    startTimer = false;
  }
}