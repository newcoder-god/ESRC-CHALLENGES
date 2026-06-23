# Speed Swipe Challenge 🚀

## Overview

The Speed Swipe Challenge is an Arduino-based reaction and speed game that uses an IR Sensor Module, a Passive Buzzer, and a Dual 7-Segment Display. The objective is to swipe an object repeatedly in front of the IR sensor within 15 seconds and achieve the highest possible score.

---

## Features

* 15-second countdown timer.
* IR sensor detects hand or object swipes.
* Score increases for every successful detection.
* High-pitched click sound for each swipe.
* Dual 7-segment display shows the remaining time.
* Final score displayed in the Serial Monitor.
* Long buzzer tone when the game ends.
* Challenge target: More than 40 swipes.

---

## Components Used

* Arduino Uno
* IR Sensor Module
* Passive Buzzer
* Dual Common Anode 7-Segment Display
* Breadboard
* Jumper Wires

---

## Circuit Connections

### IR Sensor

| Sensor Pin | Arduino Pin |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| OUT (DO)   | D10         |

### Passive Buzzer

| Buzzer Pin   | Arduino Pin |
| ------------ | ----------- |
| Positive (+) | D11         |
| Negative (-) | GND         |

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

### Digit Control

| Digit       | Arduino Pin |
| ----------- | ----------- |
| Left Digit  | D12         |
| Right Digit | D13         |

---

## Working Principle

1. The system waits for the first swipe.
2. On the first detection, a 15-second countdown begins.
3. Each swipe detected by the IR sensor:

   * Increases the score by 1.
   * Produces a short click sound.
4. The 7-segment display shows the remaining time.
5. After 15 seconds:

   * A long beep indicates the end of the game.
   * Final score is displayed.
6. The goal is to achieve more than 40 swipes.

---

## Example Output

```text
===== SPEED SWIPE CHALLENGE =====

GO! 15 Seconds Started

Score: 1
Score: 2
Score: 3
...
Score: 42

===== GAME OVER =====
Final Score: 42
CHALLENGE PASSED!
```

---

## Arduino Concepts Used

### Sensor Input

```cpp
digitalRead()
```

Reads the IR sensor state.

### Timing

```cpp
millis()
```

Creates the 15-second countdown.

### Sound Generation

```cpp
tone()
noTone()
```

Generates click sounds and the game-over alarm.

### Display Multiplexing

Two 7-segment displays share segment pins and are refreshed rapidly.

### Conditional Logic

```cpp
if
else
```

Used for swipe detection and game-state management.

---

## Learning Outcomes

* Working with IR sensors.
* Event detection using digital inputs.
* Countdown timers using millis().
* Multiplexed 7-segment displays.
* Score tracking systems.
* Audio feedback using passive buzzers.

---

## Author

Developed as part of the ESRC Arduino Challenge Series using Arduino Uno, IR Sensor Module, Passive Buzzer, and Dual 7-Segment Displays.
