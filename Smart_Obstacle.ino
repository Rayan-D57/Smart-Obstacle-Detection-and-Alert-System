#include <Servo.h>

Servo servo;

// Ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

// LED pins
const int greenLED = 5;
const int yellowLED = 6;
const int redLED = 7;

// Buzzer pin
const int buzzer = 8;

long duration;
float distance;

// ==========================
// State Machine definition
// ==========================
enum Zone { SAFE, WARNING, DANGER };
Zone currentZone = SAFE;
Zone previousZone = (Zone)-1; // Dummy value to force first state execution on startup

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  servo.attach(3);
  servo.write(0);

  Serial.begin(9600);
}

float readDistance() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo with timeout to avoid blocking if no echo returns
  duration = pulseIn(echoPin, HIGH, 30000);
  float d = duration * 0.034 / 2;

  if (duration == 0) return 999; // No echo -> treat as safe distance
  return d;
}

void enterSafe() {
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);
  servo.write(0);
  Serial.println("STATE: SAFE");
}

void enterWarning() {
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(redLED, LOW);
  servo.write(45);

  // Warning beep played only once, on entry to this state
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }

  Serial.println("STATE: WARNING");
}

void enterDanger() {
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  servo.write(90);
  digitalWrite(buzzer, HIGH); // Stays ON continuously while in this state
  Serial.println("STATE: DANGER");
}

void loop() {
  distance = readDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // ==========================
  // Determine current zone based on distance
  // ==========================
  if (distance > 15) {
    currentZone = SAFE;
  }
  else if (distance > 10) {
    currentZone = WARNING;
  }
  else {
    currentZone = DANGER;
  }

  // ==========================
  // Run the "enter" action only when the zone actually changes
  // ==========================
  if (currentZone != previousZone) {
    switch (currentZone) {
      case SAFE:    enterSafe();    break;
      case WARNING: enterWarning(); break;
      case DANGER:  enterDanger();  break;
    }
    previousZone = currentZone;
  }

  delay(50);
}
