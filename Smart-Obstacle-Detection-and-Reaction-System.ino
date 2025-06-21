#include <Stepper.h>

#define IR_PIN 6            // IR sensor D OUT
#define TRIG_PIN 2          // Ultrasonic trigger
#define ECHO_PIN 3          // Ultrasonic echo
#define BUZZER_PIN 8        // Buzzer

// 7-segment pins (common cathode)
int segmentPins[] = {9, 10, 11, 12, A0, A5, A6}; // a to g

// 4 LED disco pins
#define LED1 A1
#define LED2 A2
#define LED3 A3
#define LED4 A4

// Stepper motor pins
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7);

// Digit mapping for 7-segment (0–9)
byte digits[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

void setup() {
  Serial.begin(9600);

  pinMode(IR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  for (int i = 0; i < 7; i++) pinMode(segmentPins[i], OUTPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  myStepper.setSpeed(60);  // Set motor speed
}

void loop() {
  if (digitalRead(IR_PIN) == LOW) {  // IR triggered
    long duration;
    int distance;

    // Trigger ultrasonic pulse
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure echo
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 10 && distance >= 0) {
      int displayNum = (distance > 9) ? 9 : distance;
      showDigit(displayNum);

      digitalWrite(BUZZER_PIN, HIGH);
      discoLights();
      myStepper.step(stepsPerRevolution);  // Rotate 360°
      digitalWrite(BUZZER_PIN, LOW);
    } else {
      showDigit(0);
      turnOffAll();
    }
  } else {
    showDigit(0);
    turnOffAll();
  }

  delay(500);
}

// Show digit 0–9 on 7-segment
void showDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}

// Turn off buzzer + LEDs
void turnOffAll() {
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}

// Disco LED effect
void discoLights() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(LED1, i % 2);
    digitalWrite(LED2, (i + 1) % 2);
    digitalWrite(LED3, (i + 2) % 2);
    digitalWrite(LED4, (i + 3) % 2);
    delay(100);
  }
  turnOffAll();
}
