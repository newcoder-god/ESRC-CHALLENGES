const int segPins[7] = {2,3,4,5,6,7,8};

const int greenLED = 9;
const int redLED   = 10;
const int buzzer   = 11;

// Common Anode 7-Segment Digits
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

String questions[] = {
  "The Earth revolves around the Sun.",
  "Arduino Uno uses ATmega328P.",
  "Water boils at 50 C.",
  "2 + 2 = 4.",
  "The Moon is a planet."
};

bool answers[] = {
  true,
  true,
  false,
  true,
  false
};

const int totalQuestions = 5;

int score = 0;

void setup()
{
  Serial.begin(9600);

  for(int i=0;i<7;i++)
    pinMode(segPins[i], OUTPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  clearDisplay();

  Serial.println("===== TRUE / FALSE QUIZ =====");
  Serial.println("Type T for TRUE");
  Serial.println("Type F for FALSE");
  Serial.println();
}

void loop()
{
  for(int q=0; q<totalQuestions; q++)
  {
    askQuestion(q);
  }

  Serial.println();
  Serial.println("===== QUIZ COMPLETE =====");

  Serial.print("Final Score: ");
  Serial.print(score);
  Serial.print("/");
  Serial.println(totalQuestions);

  if(score >= 4)
  {
    Serial.println("YOU WON!");

    for(int i=0;i<3;i++)
    {
      digitalWrite(greenLED,HIGH);
      tone(buzzer,1500);
      delay(200);

      digitalWrite(greenLED,LOW);
      noTone(buzzer);
      delay(200);
    }
  }
  else
  {
    Serial.println("YOU LOST!");

    digitalWrite(redLED,HIGH);
    tone(buzzer,300);
    delay(1500);
    noTone(buzzer);
    digitalWrite(redLED,LOW);
  }

  while(true);
}

void askQuestion(int q)
{
  Serial.println();
  Serial.print("Q");
  Serial.print(q+1);
  Serial.print(": ");
  Serial.println(questions[q]);

  Serial.println("Enter T or F");

  bool answered = false;
  bool userAnswer = false;

  for(int sec=9; sec>=0; sec--)
  {
    unsigned long startTime = millis();

    while(millis() - startTime < 1000)
    {
      showDigit(sec);

      if(Serial.available())
      {
        char c = toupper(Serial.read());

        if(c == 'T')
        {
          userAnswer = true;
          answered = true;
        }
        else if(c == 'F')
        {
          userAnswer = false;
          answered = true;
        }

        if(answered)
          break;
      }
    }

    if(answered)
      break;
  }

  clearDisplay();

  if(answered && userAnswer == answers[q])
  {
    score++;

    Serial.println("CORRECT!");

    digitalWrite(greenLED,HIGH);

    tone(buzzer,1200);
    delay(300);

    noTone(buzzer);
    digitalWrite(greenLED,LOW);
  }
  else
  {
    Serial.println("WRONG!");

    digitalWrite(redLED,HIGH);

    tone(buzzer,400);
    delay(700);

    noTone(buzzer);
    digitalWrite(redLED,LOW);
  }

  while(Serial.available())
    Serial.read();

  delay(500);
}

void showDigit(int num)
{
  for(int i=0;i<7;i++)
  {
    digitalWrite(segPins[i], digits[num][i]);
  }
}

void clearDisplay()
{
  for(int i=0;i<7;i++)
  {
    digitalWrite(segPins[i], HIGH);
  }
}
