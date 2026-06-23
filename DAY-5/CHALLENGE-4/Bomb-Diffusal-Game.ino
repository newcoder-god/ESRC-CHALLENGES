const int segPins[7] = {2,3,4,5,6,7,8};
const int digitPins[2] = {12,13};
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

int timerValue = 50;
int correctCount = 0;

unsigned long lastSecond = 0;

int num1, num2;
int correctAnswer;

bool gameOver = false;
bool gameWon = false;

void setup()
{
  Serial.begin(9600);

  for(int i=0;i<7;i++)
    pinMode(segPins[i], OUTPUT);

  pinMode(digitPins[0], OUTPUT);
  pinMode(digitPins[1], OUTPUT);

  pinMode(buzzer, OUTPUT);

  randomSeed(analogRead(A0));

  askQuestion();
}

void loop()
{
  if(gameOver)
  {
    if(gameWon)
    {
      blankDisplay();
    }
    else
    {
      showDigit(0,0);
      showDigit(0,1);
    }
    return;
  }

  int tens = timerValue / 10;
  int ones = timerValue % 10;

  showDigit(tens,0);
  showDigit(ones,1);

  if(millis() - lastSecond >= 1000)
  {
    lastSecond = millis();
    timerValue--;

    if(timerValue <= 0)
    {
      loseGame();
    }
  }

  if(Serial.available())
  {
    int answer = Serial.parseInt();

    while(Serial.available())
      Serial.read();

    if(answer == correctAnswer)
{
  timerValue += 5;

  if(timerValue > 99)
    timerValue = 99;

  correctCount++;

  Serial.print("Correct! +5 seconds   Score: ");
  Serial.print(correctCount);
  Serial.println("/5");

  blink88();

  tone(buzzer,1000,150);

  if(correctCount >= 5)
  {
    winGame();
  }
  else
  {
    askQuestion();

    // pause timer during animation
    lastSecond = millis();
  }
}
    else
    {
      timerValue -= 2;

      Serial.println("Wrong! -2 seconds");

      blinkMinus();

      tone(buzzer,300,150);
      delay(200);
      tone(buzzer,300,150);

      askQuestion();
    }
  }
}

void askQuestion()
{
  num1 = random(0,6);
  num2 = random(0,6);

  correctAnswer = num1 + num2;

  Serial.println();
  Serial.print("Question ");
  Serial.print(correctCount + 1);
  Serial.print("/5 : ");
  Serial.print(num1);
  Serial.print(" + ");
  Serial.print(num2);
  Serial.println(" = ?");
}

void showDigit(int num, int digit)
{
  digitalWrite(digitPins[0], LOW);
  digitalWrite(digitPins[1], LOW);

  for(int i=0;i<7;i++)
    digitalWrite(segPins[i], digits[num][i]);

  digitalWrite(digitPins[digit], HIGH);

  delay(5);
}

void showMinus(int digit)
{
  digitalWrite(digitPins[0], LOW);
  digitalWrite(digitPins[1], LOW);

  for(int i=0;i<7;i++)
    digitalWrite(segPins[i], HIGH);

  digitalWrite(segPins[6], LOW);

  digitalWrite(digitPins[digit], HIGH);

  delay(5);
}

void blink88()
{
  unsigned long start = millis();

  // Show 88
  while(millis() - start < 500)
  {
    showDigit(8,0);
    showDigit(8,1);
  }

  // Then blank display
  start = millis();

  while(millis() - start < 300)
  {
    blankDisplay();
  }
}

void blinkMinus()
{
  for(int k=0;k<2;k++)
  {
    unsigned long start = millis();

    while(millis() - start < 250)
    {
      showMinus(0);
      showMinus(1);
    }

    start = millis();

    while(millis() - start < 150)
    {
      blankDisplay();
    }
  }
}

void blankDisplay()
{
  digitalWrite(digitPins[0], LOW);
  digitalWrite(digitPins[1], LOW);

  for(int i=0;i<7;i++)
  {
    digitalWrite(segPins[i], HIGH);
  }
}

void winGame()
{
  gameOver = true;
  gameWon = true;

  Serial.println();
  Serial.println("***** BOMB DEFUSED *****");

  tone(buzzer,1000,200);
  delay(250);

  tone(buzzer,1500,200);
  delay(250);

  tone(buzzer,2000,300);

  blankDisplay();
}

void loseGame()
{
  gameOver = true;
  gameWon = false;

  Serial.println();
  Serial.println("***** BOOM! BOMB EXPLODED *****");

  tone(buzzer,400);
  delay(3000);
  noTone(buzzer);
}
