#include <SoftwareSerial.h>
#include <Servo.h>

#define TRIG A4 
#define ECHO A5 
#define SERVO 3

// PINS
//
//
// Bl   Ar
// RX - TX 1
// TX - RX 0 

SoftwareSerial BTSerial (1, 0);
Servo servo;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  servo.attach(SERVO);
  Serial.begin(9600);
  BTSerial.begin(38400);
  servo.write(90);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delay(0);
  digitalWrite(TRIG, LOW);
  unsigned long tot = pulseIn(ECHO, HIGH);
  Serial.println(tot);
  if (Serial.available()) {
    Serial.println("available");
  }
}
