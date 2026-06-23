const int segPins[7] = {2,3,4,5,6,7,8};
const int digitPins[2] = {12,13};

const int irPin = 10;
const int buzzer = 11;

const byte digits[10][7] = {
 {LOW,LOW,LOW,LOW,LOW,LOW,HIGH},
 {HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH},
 {LOW,LOW,HIGH,LOW,LOW,HIGH,LOW},
 {LOW,LOW,LOW,LOW,HIGH,HIGH,LOW},
 {HIGH,LOW,LOW,HIGH,HIGH,LOW,LOW},
 {LOW,HIGH,LOW,LOW,HIGH,LOW,LOW},
 {LOW,HIGH,LOW,LOW,LOW,LOW,LOW},
 {LOW,LOW,LOW,HIGH,HIGH,HIGH,HIGH},
 {LOW,LOW,LOW,LOW,LOW,LOW,LOW},
 {LOW,LOW,LOW,LOW,HIGH,LOW,LOW}
};

int score = 0;

unsigned long startTime;
bool gameStarted = false;
bool gameOver = false;

bool lastSensorState = HIGH;

void setup()
{
  Serial.begin(9600);

  for(int i=0;i<7;i++)
    pinMode(segPins[i], OUTPUT);

  pinMode(digitPins[0], OUTPUT);
  pinMode(digitPins[1], OUTPUT);

  pinMode(irPin, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.println("===== SPEED SWIPE CHALLENGE =====");
  Serial.println("Wave object in front of IR sensor.");
  Serial.println("Game starts on first detection.");
}

void loop()
{
  if(gameOver)
  {
    displayNumber(score);
    return;
  }

  bool sensorState = digitalRead(irPin);

  if(!gameStarted)
  {
    if(lastSensorState == HIGH && sensorState == LOW)
    {
      gameStarted = true;
      startTime = millis();

      Serial.println("GO! 15 Seconds Started");
    }

    lastSensorState = sensorState;
    displayNumber(15);
    return;
  }

  int timeLeft = 15 - ((millis() - startTime) / 1000);

  if(timeLeft < 0)
    timeLeft = 0;

  displayNumber(timeLeft);

  if(lastSensorState == HIGH && sensorState == LOW)
  {
    score++;

    tone(buzzer, 2000, 30);

    Serial.print("Score: ");
    Serial.println(score);
  }

  lastSensorState = sensorState;

  if(millis() - startTime >= 15000)
  {
    gameOver = true;

    Serial.println();
    Serial.println("===== GAME OVER =====");

    Serial.print("Final Score: ");
    Serial.println(score);

    if(score > 40)
      Serial.println("CHALLENGE PASSED!");
    else
      Serial.println("CHALLENGE FAILED!");

    tone(buzzer, 500);
    delay(2000);
    noTone(buzzer);
  }
}

void displayNumber(int number)
{
  int tens = number / 10;
  int ones = number % 10;

  showDigit(tens,0);
  showDigit(ones,1);
}

void showDigit(int num,int digit)
{
  digitalWrite(digitPins[0], LOW);
  digitalWrite(digitPins[1], LOW);

  for(int i=0;i<7;i++)
    digitalWrite(segPins[i], digits[num][i]);

  digitalWrite(digitPins[digit], HIGH);

  delay(5);
}
