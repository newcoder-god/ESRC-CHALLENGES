# Traffic Light with Pedestrian Crossing 🚦🚶

## Overview

This project simulates a real-world traffic signal system with a pedestrian crossing feature using Arduino Uno, RGB LEDs, a push button, and a buzzer. The traffic lights operate in a normal cycle, while pedestrians can request a crossing by pressing a button. The system safely transitions traffic to a stop before allowing pedestrians to cross.

---

## Features

* Two-way traffic light simulation.
* Normal traffic cycle:

  * Green → Yellow → Red
* Opposite road always shows the complementary signal.
* Pedestrian crossing request using a push button.
* Safe transition after the current green phase ends.
* Both roads turn red during pedestrian crossing.
* Buzzer sounds for 5 seconds as a walk signal.
* Automatically resumes normal traffic operation.

---

## Components Used

* Arduino Uno
* 2 × RGB LEDs (or separate Red, Yellow, Green LEDs)
* Push Button
* Passive/Active Buzzer
* Breadboard
* 220Ω Resistors
* Jumper Wires

---

## Working Principle

### Normal Traffic Cycle

#### Road A

```text
Green → Yellow → Red
```

#### Road B

```text
Red → Red → Green
```

The two roads always operate in opposite states to prevent conflicts.

---

### Pedestrian Request

When the push button is pressed:

1. The request is stored.
2. The current green light finishes its cycle.
3. Both directions switch to RED.
4. The buzzer sounds for 5 seconds.
5. Pedestrians safely cross.
6. Normal traffic operation resumes.

---

## Example Sequence

### Normal Operation

```text
Road A: Green
Road B: Red
```

↓

```text
Road A: Yellow
Road B: Red
```

↓

```text
Road A: Red
Road B: Green
```

---

### Pedestrian Crossing

Button Pressed

↓

```text
Road A: Red
Road B: Red
```

↓

```text
Buzzer ON (5 seconds)
```

↓

```text
Pedestrian Crossing Allowed
```

↓

```text
Normal Traffic Cycle Resumes
```

---

## Circuit Connections

### Traffic Light A

| Color  | Arduino Pin |
| ------ | ----------- |
| Red    | D2          |
| Yellow | D3          |
| Green  | D4          |

### Traffic Light B

| Color  | Arduino Pin |
| ------ | ----------- |
| Red    | D5          |
| Yellow | D6          |
| Green  | D7          |

### Push Button

| Button Pin | Arduino Pin |
| ---------- | ----------- |
| Signal     | D8          |
| Other Side | GND         |

Using:

```cpp
pinMode(8, INPUT_PULLUP);
```

---

### Buzzer

| Buzzer Pin   | Arduino Pin |
| ------------ | ----------- |
| Positive (+) | D9          |
| Negative (-) | GND         |

---

## Program Logic

1. Initialize traffic signals.
2. Start normal light sequence.
3. Continuously monitor the pedestrian button.
4. If button is pressed:

   * Save the request.
   * Wait until current green phase completes.
5. Activate pedestrian mode:

   * Both roads RED.
   * Buzzer ON for 5 seconds.
6. Resume normal cycle.

---

## Arduino Concepts Used

### Digital Outputs

```cpp
digitalWrite()
```

Controls LEDs and buzzer.

---

### Digital Inputs

```cpp
digitalRead()
```

Detects pedestrian button presses.

---

### Timing

```cpp
delay()
```

Controls traffic signal durations.

---

### Conditional Statements

```cpp
if
else
```

Handles pedestrian crossing requests.

---

## Learning Outcomes

* Traffic control system design.
* Event-driven programming.
* Human-machine interaction.
* Safe state transitions.
* LED and buzzer interfacing.
* Push button handling.
* Embedded system logic implementation.

---

## Applications

* Smart traffic management systems.
* Pedestrian crossing systems.
* Embedded control systems.
* Urban traffic simulations.
* Educational Arduino projects.

---

## Future Improvements

* Add countdown timers for pedestrians.
* Add LCD/OLED display.
* Add vehicle sensors for adaptive timing.
* Add multiple pedestrian crossings.
* Integrate IoT monitoring.
* Add emergency vehicle override.

---

## Project Outcome

The project successfully demonstrates a traffic light system with a pedestrian crossing mechanism. It ensures safe traffic control by coordinating vehicle movement and pedestrian requests using Arduino-based hardware.

---

## Author

Developed as part of the ESRC Arduino Challenge Series using Arduino Uno, RGB LEDs, Push Button, and Buzzer.
