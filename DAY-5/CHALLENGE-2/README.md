# Color Memory Challenge 🎨🧠

## Overview

The Color Memory Challenge is an Arduino-based game designed to test a player's memory and observation skills. The Arduino generates a random sequence of colored LEDs, displays them one by one, and asks the user to recall and enter the sequence through the Serial Monitor. The game runs for 2 minutes and tracks the player's score.

---

## Features

* Randomly generates a color sequence using 10 LEDs.
* Displays LEDs one by one for easy observation.
* User enters the sequence through the Serial Monitor.
* Automatically verifies answers.
* Keeps track of the score.
* Runs continuously for 2 minutes.
* Displays the final score at the end of the game.

---

## Components Used

* Arduino Uno
* 10 LEDs (Red, Green, Blue, Yellow)
* 10 × 220Ω Resistors
* Breadboard
* Jumper Wires

---

## Circuit Connections

| LED    | Arduino Pin |
| ------ | ----------- |
| LED 1  | D2          |
| LED 2  | D3          |
| LED 3  | D4          |
| LED 4  | D5          |
| LED 5  | D6          |
| LED 6  | D7          |
| LED 7  | D8          |
| LED 8  | D9          |
| LED 9  | D10         |
| LED 10 | D11         |

Connect each LED in series with a 220Ω resistor and connect the cathode to GND.

---

## How It Works

1. Arduino randomly selects 4 unique LEDs.
2. Each LED is associated with a predefined color:

   * R = Red
   * G = Green
   * B = Blue
   * Y = Yellow
3. The LEDs are displayed one by one.
4. The player memorizes the sequence.
5. The player enters the sequence in the Serial Monitor.
6. Arduino compares the input with the generated sequence.
7. Correct answers increase the score.
8. The game continues until 2 minutes have elapsed.
9. Final score is displayed.

---

## Example

Displayed Sequence:

R → G → B → Y

User Input:

RGBY

Result:

CORRECT!

---

## Arduino Concepts Used

* Random Number Generation (`random()`)
* Digital Output Control (`digitalWrite()`)
* Time Management (`millis()`)
* Serial Communication (`Serial.begin()`, `Serial.readStringUntil()`)
* Arrays
* String Comparison
* Conditional Statements
* Loops

---

## Learning Outcomes

* Understanding Arduino digital outputs
* Working with arrays and strings
* Implementing memory-based games
* Using Serial Monitor for user interaction
* Applying randomization techniques
* Managing game logic and scoring systems

---

## Future Improvements

* Add a buzzer for audio feedback.
* Add an LCD/OLED display for scores.
* Increase difficulty by increasing sequence length.
* Add multiple difficulty levels.
* Store and display high scores.

---

## Author

Developed as part of the ESRC Arduino Challenge Series.
