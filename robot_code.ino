#include <Servo.h>
#include "HX711.h"

#define ENA 5
#define IN1 6
#define IN2 7
#define ENB 9
#define IN3 10
#define IN4 11

#define IR_LEFT 2
#define IR_CENTER 3
#define IR_RIGHT 4

#define TRIG 12
#define ECHO 13

#define SERVO_PIN 8

#define LOADCELL_DOUT_PIN A1
#define LOADCELL_SCK_PIN A0

Servo myServo;
HX711 scale;

long distance;
float weight;

long readUltrasonic() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  return pulseIn(ECHO, HIGH) * 0.034 / 2;
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IR_LEFT, INPUT);
  pinMode(IR_CENTER, INPUT);
  pinMode(IR_RIGHT, INPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  myServo.attach(SERVO_PIN);

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare();
}

void loop() {
  distance = readUltrasonic();
  weight = scale.get_units();

  if (distance < 15) {
    stopMotors();
    delay(500);
    moveRight();
    delay(700);
    moveForward();
  }
  else {
    int left = digitalRead(IR_LEFT);
    int center = digitalRead(IR_CENTER);
    int right = digitalRead(IR_RIGHT);

    if (center == HIGH && left == LOW && right == LOW) {
      moveForward();
    } else if (left == HIGH) {
      moveLeft();
    } else if (right == HIGH) {
      moveRight();
    } else {
      stopMotors();
    }
  }

  if (weight > 200) {
    stopMotors();
    myServo.write(90);
    delay(2000);
    myServo.write(0);
  }
}
