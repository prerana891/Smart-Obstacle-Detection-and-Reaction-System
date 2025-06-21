# Smart-Obstacle-Detection-and-Reaction-System
# Obstacle Detection and Smart Response System Using Arduino Nano 

---

## 📝 Project Overview

This project is a **smart obstacle detection and response system** built using **Arduino Nano**. It integrates an **IR sensor** for motion triggering, an **ultrasonic sensor** for distance measurement, a **7-segment display** for visual feedback, a **buzzer**, a **stepper motor** for rotation, and **disco-style LEDs** for visual alert.

---

## 🎯 Objective

To build a reactive embedded system that:
- Detects objects using an IR sensor.
- Measures object distance using an ultrasonic sensor.
- Reacts to nearby obstacles with:
  - Distance display on a 7-segment display.
  - Audible buzzer alert.
  - Stepper motor rotation (360°).
  - Disco light flashing using LEDs.
  - Debug output via Serial Monitor.

---

## 🔧 Hardware Used

| Component                              | Quantity |
|----------------------------------------|----------|
| Arduino Nano                           | 1        |
| IR Sensor Module                       | 1        |
| Ultrasonic Sensor (HC-SR04)            | 1        |
| Buzzer                                 | 1        |
| 7-Segment Display (Common Cathode)     | 1        |
| Stepper Motor (28BYJ-48 + ULN2003)     | 1        |
| LEDs                                   | 4        |
| Resistors (220Ω for 7-segment display) | 7        |
| Jumper Wires                           | As needed|
| Breadboard                             | 1        |
| External 5V Supply(for motor, optional)| 1        |

---

## ⚙️ Pin Configuration

| Module/Part          | Arduino Nano Pin              |
|----------------------|-------------------------------|
| IR Sensor (D OUT)    | D13                           |
| Ultrasonic Trig      | D2                            |
| Ultrasonic Echo      | D3                            |
| Stepper Motor IN1–IN4| D4, D5, D6, D7                |
| Buzzer               | D8                            |
| 7-Segment (a→g)      | D9, D10, D11, D12, A0, A5, A6 |
| LEDs                 | A1, A2, A3, A4                |



---

## 🧠 Working Principle

1. The IR sensor detects any motion in front.
2. The ultrasonic sensor measures how far the object is.
3. If the object is **less than 10 cm** away:
   - The distance is shown on a **7-segment display**.
   - A **buzzer** sounds.
   - A **stepper motor** rotates 360°.
   - Four **LEDs** blink in disco style.
   - The distance is printed on the **Serial Monitor**.
4. If no object is close, it resets the system:
   - 7-segment shows `0`
   - LEDs and buzzer turn off

---

## 🧾 Code Overview

- Uses `Stepper.h` for stepper motor control.
- IR sensor is active-low and starts the system.
- Distance is measured and displayed in cm.
- 7-segment is driven using an array lookup.
- Real-time output via Serial Monitor.



