// ======================================
// TRAFFIC LIGHT WITH PEDESTRIAN CROSSING
// Arduino Uno
// ======================================

// Road A LEDs
const int A_RED = 2;
const int A_YELLOW = 3;
const int A_GREEN = 4;

// Road B LEDs
const int B_RED = 5;
const int B_YELLOW = 6;
const int B_GREEN = 7;

// Button and Buzzer
const int BUTTON = 8;
const int BUZZER = 9;

bool pedestrianRequest = false;

void setup() {
  pinMode(A_RED, OUTPUT);
  pinMode(A_YELLOW, OUTPUT);
  pinMode(A_GREEN, OUTPUT);

  pinMode(B_RED, OUTPUT);
  pinMode(B_YELLOW, OUTPUT);
  pinMode(B_GREEN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}

void loop() {

  // =========================
  // ROAD A GREEN
  // =========================
  digitalWrite(A_GREEN, HIGH);
  digitalWrite(A_YELLOW, LOW);
  digitalWrite(A_RED, LOW);

  digitalWrite(B_RED, HIGH);
  digitalWrite(B_YELLOW, LOW);
  digitalWrite(B_GREEN, LOW);

  waitWithButtonCheck(5000);

  // ROAD A YELLOW
  digitalWrite(A_GREEN, LOW);
  digitalWrite(A_YELLOW, HIGH);

  waitWithButtonCheck(2000);

  digitalWrite(A_YELLOW, LOW);
  digitalWrite(A_RED, HIGH);

  // Pedestrian crossing if requested
  if (pedestrianRequest) {
    pedestrianCrossing();
  }

  // =========================
  // ROAD B GREEN
  // =========================
  digitalWrite(B_RED, LOW);
  digitalWrite(B_GREEN, HIGH);
  digitalWrite(B_YELLOW, LOW);

  digitalWrite(A_RED, HIGH);
  digitalWrite(A_YELLOW, LOW);
  digitalWrite(A_GREEN, LOW);

  waitWithButtonCheck(5000);

  // ROAD B YELLOW
  digitalWrite(B_GREEN, LOW);
  digitalWrite(B_YELLOW, HIGH);

  waitWithButtonCheck(2000);

  digitalWrite(B_YELLOW, LOW);
  digitalWrite(B_RED, HIGH);

  // Pedestrian crossing if requested
  if (pedestrianRequest) {
    pedestrianCrossing();
  }
}

// ======================================
// CHECK BUTTON DURING WAIT
// ======================================
void waitWithButtonCheck(unsigned long duration) {
  unsigned long startTime = millis();

  while (millis() - startTime < duration) {

    if (digitalRead(BUTTON) == LOW) {
      pedestrianRequest = true;
    }

    delay(50);
  }
}

// ======================================
// PEDESTRIAN CROSSING MODE
// ======================================
void pedestrianCrossing() {

  // BOTH ROADS RED
  digitalWrite(A_RED, HIGH);
  digitalWrite(A_YELLOW, LOW);
  digitalWrite(A_GREEN, LOW);

  digitalWrite(B_RED, HIGH);
  digitalWrite(B_YELLOW, LOW);
  digitalWrite(B_GREEN, LOW);

  // Buzzer beeps for 5 seconds
  for (int i = 0; i < 5; i++) {
    tone(BUZZER, 1000);
    delay(500);

    noTone(BUZZER);
    delay(500);
  }

  pedestrianRequest = false;
}
