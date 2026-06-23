const int leds[] = {2, 3, 4, 5, 6};
const int numLEDs = 5;

unsigned long startTime;
bool waitingForReaction = false;
int activeLED = -1;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < numLEDs; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  randomSeed(analogRead(A0));

  Serial.println("=== Reaction Speed Counter ===");
  Serial.println("Type 'start' and press Enter");
}

void loop() {

  // Waiting for user to start game
  if (!waitingForReaction) {

    if (Serial.available()) {
      String cmd = Serial.readStringUntil('\n');
      cmd.trim();

      if (cmd == "start") {

        Serial.println("Get Ready...");

        int waitTime = random(0, 10001);
        delay(waitTime);

        activeLED = random(numLEDs);

        digitalWrite(leds[activeLED], HIGH);

        startTime = millis();
        waitingForReaction = true;
      }
    }
  }

  // Waiting for user reaction
  else {

    if (Serial.available()) {

      Serial.readStringUntil('\n');

      unsigned long reactionTime = millis() - startTime;

      digitalWrite(leds[activeLED], LOW);

      Serial.print("Reaction Time: ");
      Serial.print(reactionTime);
      Serial.println(" ms");

      if (reactionTime < 250)
        Serial.println("Excellent!");
      else if (reactionTime < 500)
        Serial.println("Good!");
      else
        Serial.println("Try Again!");

      Serial.println();
      Serial.println("Type 'start' to play again");

      waitingForReaction = false;
    }
  }
}
