const int ledPins[10] = {2,3,4,5,6,7,8,9,10,11};

char ledColors[10] = {
  'R','G','B','Y','R',
  'R','G','Y','B','G'
};

unsigned long gameStart;
int score = 0;

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  randomSeed(analogRead(A0));

  Serial.println("================================");
  Serial.println("COLOR MEMORY CHALLENGE");
  Serial.println("================================");
  Serial.println("Game Duration: 2 Minutes");
  Serial.println();

  gameStart = millis();
}

void loop() {

  // End game after 2 minutes
  if(millis() - gameStart >= 120000) {
    Serial.println();
    Serial.println("===== GAME OVER =====");
    Serial.print("Final Score: ");
    Serial.println(score);

    while(true);
  }

  // Clear serial buffer
  while(Serial.available()) {
    Serial.read();
  }

  int pattern[4];
  String answer = "";

  // Generate 4 unique LEDs
  for(int i = 0; i < 4; i++) {

    bool unique;

    do {
      unique = true;
      pattern[i] = random(10);

      for(int j = 0; j < i; j++) {
        if(pattern[i] == pattern[j]) {
          unique = false;
        }
      }

    } while(!unique);

    answer += ledColors[pattern[i]];
  }

  Serial.println();
  Serial.println("Watch the sequence!");

  // Debug output (remove during final demo)
  Serial.print("Correct Sequence: ");
  Serial.println(answer);

  // Show LEDs ONE BY ONE
  for(int i = 0; i < 4; i++) {

    digitalWrite(ledPins[pattern[i]], HIGH);

    delay(1000);

    digitalWrite(ledPins[pattern[i]], LOW);

    delay(300);
  }

  Serial.println();
  Serial.println("Enter sequence (Example: RGBY)");

  while(!Serial.available()) {
    // wait
  }

  String userInput = Serial.readStringUntil('\n');

  userInput.trim();
  userInput.toUpperCase();

  Serial.print("You Entered: ");
  Serial.println(userInput);

  Serial.print("Expected: ");
  Serial.println(answer);

  if(userInput == answer) {

    score++;

    Serial.println("CORRECT!");
    Serial.print("Score: ");
    Serial.println(score);

  } else {

    Serial.println("WRONG!");
    Serial.print("Correct Answer: ");
    Serial.println(answer);
  }

  Serial.println("-------------------------");

  delay(1500);
}
