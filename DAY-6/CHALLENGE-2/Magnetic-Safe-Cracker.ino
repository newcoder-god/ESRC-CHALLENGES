const int reedPin = 2;
const int buzzer = 11;

int secretCode;

bool safeOpened = false;
bool gameOver = false;

unsigned long countdownStart;
unsigned long lastTick = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(reedPin, INPUT);
  pinMode(buzzer, OUTPUT);

  randomSeed(analogRead(A0));

  Serial.println("================================");
  Serial.println("MAGNETIC SAFE CRACKER");
  Serial.println("================================");
  Serial.println("Keep magnet near sensor.");
  Serial.println();

  // Generate random 3-digit code
  secretCode = random(100, 1000);

  Serial.print("Security Code: ");
  Serial.println(secretCode);

  delay(2000);

  // Hide code
  for(int i=0; i<30; i++)
  {
    Serial.println();
  }

  Serial.println("Code Hidden.");
  Serial.println("Remove magnet to open safe.");
}

void loop()
{
  if(gameOver)
    return;

  // Detect safe opening
  if(!safeOpened && digitalRead(reedPin) == HIGH)
  {
    safeOpened = true;
    countdownStart = millis();

    Serial.println();
    Serial.println("SAFE OPENED!");
    Serial.println("Enter the 3-digit code.");
    Serial.println("Time Limit: 5 Seconds");
  }

  if(safeOpened)
  {
    // Rapid ticking sound
    if(millis() - lastTick >= 150)
    {
      lastTick = millis();

      tone(buzzer, 1800);
      delay(30);
      noTone(buzzer);
    }

    // Read entered code
    if(Serial.available())
    {
      int enteredCode = Serial.parseInt();

      while(Serial.available())
        Serial.read();

      if(enteredCode == secretCode)
      {
        disarmSafe();
      }
      else
      {
        lockdown();
      }
    }

    // Timeout
    if(millis() - countdownStart >= 5000)
    {
      lockdown();
    }
  }
}

void disarmSafe()
{
  gameOver = true;

  noTone(buzzer);

  Serial.println();
  Serial.println("SAFE DISARMED!");
  Serial.println("ACCESS GRANTED");

  tone(buzzer, 1000);
  delay(150);

  tone(buzzer, 1400);
  delay(150);

  tone(buzzer, 1800);
  delay(300);

  noTone(buzzer);
}

void lockdown()
{
  gameOver = true;

  Serial.println();
  Serial.println("LOCKDOWN ACTIVATED!");
  Serial.println("ACCESS DENIED");

  tone(buzzer, 400);

  while(true)
  {
    // Continuous alarm
  }
}
