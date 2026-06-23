# Motion Alert System 🚨

## Overview

The Motion Alert System is an Arduino-based security project that uses a PIR (Passive Infrared) Motion Sensor to detect movement in the surrounding area. When motion is detected, the system activates a Red LED, sounds a buzzer alarm, and displays "1" on a 7-segment display. When no motion is present, the LED and buzzer remain OFF and the display shows "0".

---

## Features

* Real-time motion detection using a PIR sensor.
* Red LED visual alert.
* Passive buzzer audio alert.
* 7-segment display status indicator.
* Continuous monitoring of the environment.
* Simple and efficient security alert system.

---

## Components Used

* Arduino Uno
* PIR Motion Sensor
* Common Anode 7-Segment Display
* Red LED
* Passive Buzzer
* 220Ω Resistor
* Breadboard
* Jumper Wires

---

## Circuit Connections

### PIR Motion Sensor

| PIR Pin | Arduino Pin |
| ------- | ----------- |
| VCC     | 5V          |
| GND     | GND         |
| OUT     | D9          |

---

### Red LED

| LED Pin     | Arduino Pin               |
| ----------- | ------------------------- |
| Anode (+)   | D10 through 220Ω resistor |
| Cathode (-) | GND                       |

---

### Passive Buzzer

| Buzzer Pin   | Arduino Pin |
| ------------ | ----------- |
| Positive (+) | D11         |
| Negative (-) | GND         |

---

### 7-Segment Display (Common Anode)

| Segment | Arduino Pin |
| ------- | ----------- |
| a       | D2          |
| b       | D3          |
| c       | D4          |
| d       | D5          |
| e       | D6          |
| f       | D7          |
| g       | D8          |

Common Anode Pin(s) → 5V

---

## Working Principle

### No Motion Detected

When the PIR sensor detects no movement:

* Red LED remains OFF.
* Buzzer remains OFF.
* 7-segment display shows:

```text
0
```

---

### Motion Detected

When the PIR sensor detects movement:

* Red LED turns ON.
* Buzzer sounds an alert.
* 7-segment display shows:

```text
1
```

* A message is printed in the Serial Monitor:

```text
Motion Detected!
```

---

## System Logic

1. Continuously read the PIR sensor output.
2. If motion is detected:

   * Turn ON Red LED.
   * Activate buzzer.
   * Display "1".
3. If no motion is detected:

   * Turn OFF Red LED.
   * Stop buzzer.
   * Display "0".
4. Repeat continuously.

---

## Example Output

### Normal State

```text
Display: 0
LED: OFF
Buzzer: OFF
```

### Motion Detected

```text
Display: 1
LED: ON
Buzzer: ON

Motion Detected!
```

---

## Arduino Concepts Used

### Digital Input

```cpp
digitalRead()
```

Reads the PIR sensor output.

---

### Digital Output

```cpp
digitalWrite()
```

Controls the LED and display segments.

---

### Sound Generation

```cpp
tone()
```

Activates the buzzer.

```cpp
noTone()
```

Stops the buzzer.

---

### Conditional Statements

```cpp
if
else
```

Used to determine whether motion is present.

---

## Learning Outcomes

* Interfacing PIR motion sensors with Arduino.
* Using LEDs as visual indicators.
* Generating alerts using passive buzzers.
* Controlling 7-segment displays.
* Implementing real-time monitoring systems.
* Understanding digital input and output operations.

---

## Applications

* Home security systems.
* Intruder detection systems.
* Smart room occupancy monitoring.
* Automatic alert systems.
* Motion-triggered automation projects.

---

## Future Improvements

* Add an LCD or OLED display.
* Add multiple PIR sensors for wider coverage.
* Integrate GSM or Wi-Fi notifications.
* Store motion events in memory.
* Add a countdown timer before alarm activation.
* Include RGB LEDs for different alert levels.

---

## Project Outcome

This project demonstrates a basic yet effective motion detection and alert system using Arduino. It combines sensor input, visual feedback, and audio alerts to provide real-time monitoring of movement in a protected area.

---

## Author

Developed as part of the ESRC Arduino Challenge Series using Arduino Uno, PIR Motion Sensor, Red LED, Passive Buzzer, and 7-Segment Display.
