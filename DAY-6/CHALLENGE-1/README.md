# True/False Quiz Game 🎯

## Overview

The True/False Quiz Game is an Arduino-based interactive quiz system that challenges users to answer True or False questions within a limited time. A 7-segment display acts as a countdown timer, while LEDs and a buzzer provide immediate feedback for correct and incorrect answers.

---

## Features

* 5 True/False quiz questions.
* 10-second countdown timer for each question.
* Single Common Anode 7-Segment Display.
* Green LED indicates a correct answer.
* Red LED indicates a wrong answer or timeout.
* Passive buzzer provides audio feedback.
* Final score calculation.
* Win/Lose result displayed in the Serial Monitor.

---

## Components Used

* Arduino Uno
* 1 × Common Anode 7-Segment Display
* Green LED
* Red LED
* Passive Buzzer
* 220Ω Resistors
* Breadboard
* Jumper Wires

---

## Circuit Connections

### 7-Segment Display

| Segment | Arduino Pin |
| ------- | ----------- |
| a       | D2          |
| b       | D3          |
| c       | D4          |
| d       | D5          |
| e       | D6          |
| f       | D7          |
| g       | D8          |

**Common Anode Pin(s) → 5V**

---

### LEDs

#### Green LED

| Connection  | Pin                      |
| ----------- | ------------------------ |
| Anode (+)   | D9 through 220Ω resistor |
| Cathode (-) | GND                      |

#### Red LED

| Connection  | Pin                       |
| ----------- | ------------------------- |
| Anode (+)   | D10 through 220Ω resistor |
| Cathode (-) | GND                       |

---

### Passive Buzzer

| Connection   | Pin |
| ------------ | --- |
| Positive (+) | D11 |
| Negative (-) | GND |

---

## How the Game Works

1. A True/False question appears in the Serial Monitor.
2. The 7-segment display counts down from 9 to 0.
3. The player enters:

   * `T` for True
   * `F` for False
4. The answer is checked immediately.
5. Feedback is provided:

   * Correct → Green LED + high-pitched beep.
   * Wrong → Red LED + low-pitched beep.
6. After all questions, the final score is displayed.
7. A score of 4 or more results in a win.

---

## Example Gameplay

### Question

```text
Q1: The Earth revolves around the Sun.
Enter T or F
```

### User Input

```text
T
```

### Output

```text
CORRECT!
```

---

## Win Condition

```text
Score >= 4
```

Output:

```text
YOU WON!
```

Green LED flashes and victory tones are played.

---

## Lose Condition

```text
Score < 4
```

Output:

```text
YOU LOST!
```

Red LED lights and a low warning tone is played.

---

## Arduino Concepts Used

### Serial Communication

```cpp
Serial.begin()
Serial.available()
Serial.read()
```

Used to receive user answers.

### Countdown Timer

```cpp
millis()
```

Used to create the 10-second response timer.

### Display Control

```cpp
digitalWrite()
```

Controls the 7-segment display and LEDs.

### Audio Feedback

```cpp
tone()
noTone()
```

Generates sounds using the passive buzzer.

### Conditional Logic

```cpp
if
else
```

Used to evaluate answers and determine results.

---

## Learning Outcomes

* Arduino digital output control
* Serial Monitor interaction
* Countdown timers using millis()
* LED and buzzer interfacing
* User input validation
* Game logic implementation
* Interactive embedded systems design

---

## Future Improvements

* Add more questions from a larger question bank.
* Randomize question order.
* Add score display on a dual 7-segment display.
* Include multiple difficulty levels.
* Add an LCD or OLED display.
* Store high scores in EEPROM.

---

## Project Outcome

This project demonstrates how Arduino can be used to create an interactive quiz system that combines user input, visual indicators, audio feedback, and real-time decision making.

---

## Author

Developed as part of the ESRC Arduino Challenge Series using Arduino Uno.
