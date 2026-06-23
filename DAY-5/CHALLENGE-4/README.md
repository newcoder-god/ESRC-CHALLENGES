# Arduino Bomb Defusal Game 💣⏱️

## Overview

The Bomb Defusal Game is an Arduino-based interactive challenge that combines a countdown timer, mental arithmetic, and real-time decision making. Players must answer addition questions correctly before the countdown reaches zero. Correct answers increase the remaining time, while incorrect answers reduce it. Defuse the bomb by answering 5 questions correctly before time runs out.

---

## Features

* 50-second countdown timer displayed on dual 7-segment displays.
* Random addition questions generated through the Serial Monitor.
* Correct answer rewards +5 seconds.
* Wrong answer penalizes -2 seconds.
* Visual feedback using 7-segment animations.
* Audio feedback using a buzzer.
* Win by answering 5 questions correctly.
* Lose if the timer reaches 0.

---

## Components Used

* Arduino Uno
* 2 × Common Anode 7-Segment Displays
* Active/Passive Buzzer
* Breadboard
* Jumper Wires
* 220Ω Resistors

---

## Pin Connections

### 7-Segment Segment Pins

| Segment | Arduino Pin |
| ------- | ----------- |
| a       | D2          |
| b       | D3          |
| c       | D4          |
| d       | D5          |
| e       | D6          |
| f       | D7          |
| g       | D8          |

### Display Control Pins

| Display     | Arduino Pin |
| ----------- | ----------- |
| Left Digit  | D12         |
| Right Digit | D13         |

### Buzzer

| Component | Arduino Pin |
| --------- | ----------- |
| Buzzer    | D11         |

---

## Game Rules

### Start Condition

* Countdown begins at 50 seconds.
* Questions appear in the Serial Monitor.

### Correct Answer

* Gain +5 seconds.
* Score increases by 1.
* "88" animation appears on the displays.
* Success beep plays.

### Wrong Answer

* Lose 2 seconds.
* "--" animation appears on the displays.
* Error beep plays.

### Win Condition

* Answer 5 questions correctly.
* Bomb is successfully defused.

### Lose Condition

* Timer reaches 0 seconds.
* Bomb explodes.

---

## Example Gameplay

Question:

```text
Question 1/5 : 3 + 2 = ?
```

User Input:

```text
5
```

Output:

```text
Correct! +5 seconds   Score: 1/5
```

---

## Display Animations

### Correct Answer

Displays:

```text
88
```

followed by a brief blank display.

### Wrong Answer

Displays:

```text
--
```

twice as an error indication.

### Win

Display turns completely blank and victory tones are played.

### Lose

Display shows:

```text
00
```

while the buzzer sounds continuously.

---

## Program Logic

1. Start countdown at 50 seconds.
2. Generate a random addition problem.
3. Display timer continuously on the dual 7-segment display.
4. Wait for answer through Serial Monitor.
5. Verify answer:

   * Correct → Add time and increase score.
   * Wrong → Deduct time.
6. Continue until:

   * Score reaches 5 (Win)
   * Timer reaches 0 (Lose)

---

## Arduino Concepts Used

### Random Number Generation

```cpp
random()
```

Used to generate arithmetic questions.

### Serial Communication

```cpp
Serial.begin()
Serial.parseInt()
```

Used to display questions and receive answers.

### Time Tracking

```cpp
millis()
```

Used for countdown timing.

### Multiplexing

Two 7-segment displays share segment pins and are refreshed rapidly to display a two-digit timer.

### Sound Generation

```cpp
tone()
noTone()
```

Used for success, error, and game-over sounds.

---

## Learning Outcomes

* Understanding multiplexed 7-segment displays
* Working with timers using millis()
* Serial communication
* Random number generation
* User interaction through hardware and software
* Game-state management
* Audio feedback using buzzers

---

## Future Improvements

* Add multiple difficulty levels.
* Include multiplication and subtraction questions.
* Add LCD/OLED display support.
* Store high scores in EEPROM.
* Add buttons instead of Serial Monitor input.
* Add RGB LEDs for visual status indication.

---

## Author

Developed as part of the ESRC Arduino Challenge Series using Arduino Uno, dual 7-segment displays, and a buzzer.
