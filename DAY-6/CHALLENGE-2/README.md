# Magnetic Safe Cracker 🔐

## Overview

The Magnetic Safe Cracker is an Arduino-based security simulation game that uses a Magnetic Door Sensor (Reed Switch + Magnet) and a Passive Buzzer. A random 3-digit security code is briefly displayed on the Serial Monitor. Once the safe is opened by removing the magnet, a countdown begins and the user must enter the correct code before time runs out. Successfully entering the code disarms the safe, while an incorrect code or timeout triggers a lockdown alarm.

---

## Features

* Random 3-digit security code generation.
* Code displayed for exactly 2 seconds.
* Code automatically hidden after display.
* Reed switch detects safe opening.
* 5-second countdown timer.
* Rapid ticking sound during countdown.
* Correct code disarms the safe.
* Success melody on successful disarm.
* Continuous alarm on incorrect code or timeout.
* Uses only standard Arduino functions (`Serial.parseInt()`, `tone()`, `millis()`).

---

## Components Used

* Arduino Uno
* Magnetic Door Sensor (Reed Switch + Magnet)
* Passive Buzzer
* Breadboard
* Jumper Wires

---

## Circuit Connections

### Magnetic Door Sensor

| Sensor Pin | Arduino Pin |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| DO         | D2          |

---

### Passive Buzzer

| Buzzer Pin   | Arduino Pin |
| ------------ | ----------- |
| Positive (+) | D11         |
| Negative (-) | GND         |

---

## Working Principle

### Step 1: Generate Security Code

Arduino generates a random 3-digit code.

Example:

```text
Security Code: 472
```

The code remains visible for 2 seconds.

---

### Step 2: Hide the Code

After 2 seconds, the Serial Monitor is cleared and the code is hidden.

```text
Code Hidden.
Remove magnet to open safe.
```

---

### Step 3: Open the Safe

When the magnet is separated from the reed switch:

```text
SAFE OPENED!
Enter the 3-digit code.
Time Limit: 5 Seconds
```

A rapid ticking sound begins.

---

### Step 4: Enter the Code

The user enters the code through the Serial Monitor.

Example:

```text
472
```

---

### Success Condition

If the entered code matches the generated code:

```text
SAFE DISARMED!
ACCESS GRANTED
```

The ticking sound stops and a success melody is played.

---

### Failure Conditions

#### Wrong Code

```text
LOCKDOWN ACTIVATED!
ACCESS DENIED
```

#### Time Expires

If 5 seconds pass without the correct code:

```text
LOCKDOWN ACTIVATED!
ACCESS DENIED
```

A continuous alarm tone is activated.

---

## Program Logic

1. Generate a random 3-digit code.
2. Display code for 2 seconds.
3. Hide the code.
4. Wait for the magnet to be removed.
5. Start a 5-second countdown.
6. Play rapid ticking sounds.
7. Read user input using Serial Monitor.
8. Compare entered code with generated code.
9. If correct:

   * Stop ticking.
   * Play success melody.
10. If wrong or timeout:

    * Activate continuous alarm.

---

## Arduino Concepts Used

### Random Number Generation

```cpp
random()
```

Generates the 3-digit security code.

---

### Sensor Input

```cpp
digitalRead()
```

Reads the state of the reed switch.

---

### Serial Communication

```cpp
Serial.parseInt()
```

Receives the entered security code.

---

### Timing Functions

```cpp
millis()
```

Implements the 5-second countdown timer.

---

### Sound Generation

```cpp
tone()
noTone()
```

Used for ticking sounds, success melody, and alarm tones.

---

## Learning Outcomes

* Working with magnetic sensors.
* Using Serial Monitor for user interaction.
* Implementing countdown timers.
* Generating random security codes.
* Event-driven programming.
* Audio feedback using passive buzzers.
* Security system simulation using Arduino.

---

## Future Improvements

* Add a 7-segment display countdown.
* Add RGB LEDs for status indication.
* Display remaining time on an LCD.
* Add multiple difficulty levels.
* Store high scores or fastest disarm times in EEPROM.
* Add keypad input instead of Serial Monitor.

---

## Example Output

```text
================================
MAGNETIC SAFE CRACKER
================================

Security Code: 472

Code Hidden.
Remove magnet to open safe.

SAFE OPENED!
Enter the 3-digit code.
Time Limit: 5 Seconds

472

SAFE DISARMED!
ACCESS GRANTED
```

---

## Author

Developed as part of the ESRC Arduino Challenge Series using Arduino Uno, Reed Switch Sensor, and Passive Buzzer.
