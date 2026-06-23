const int segPins[7] = {2,3,4,5,6,7,8};

const int pirPin = 9;
const int redLED = 10;
const int buzzer = 11;

// Common Anode
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

void setup()
{
  Serial.begin(9600);

  for(int i=0;i<7;i++)
    pinMode(segPins[i], OUTPUT);

  pinMode(pirPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  showDigit(0);

  Serial.println("MOTION ALERT SYSTEM READY");
}

void loop()
{
  int motion = digitalRead(pirPin);

  if(motion == HIGH)
  {
    digitalWrite(redLED, HIGH);

    tone(buzzer, 1000);

    showDigit(1);

    Serial.println("Motion Detected!");
  }
  else
  {
    digitalWrite(redLED, LOW);

    noTone(buzzer);

    showDigit(0);
  }

  delay(100);
}

void showDigit(int num)
{
  for(int i=0;i<7;i++)
  {
    digitalWrite(segPins[i], digits[num][i]);
  }
}
