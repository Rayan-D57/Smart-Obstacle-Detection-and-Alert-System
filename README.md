# Smart Obstacle Detection and Alert System

## Overview

The Smart Obstacle Detection and Alert System is an Arduino Uno project that detects nearby obstacles using an HC-SR04 ultrasonic sensor. According to the measured distance, the system responds with visual and audible alerts using LEDs, a servo motor, and an active buzzer.

This project demonstrates the integration of multiple electronic components to create a simple obstacle detection and warning system.

---

# Features

- Obstacle detection using an ultrasonic sensor.
- Three alert levels based on distance.
- Visual indication using three LEDs.
- Servo motor position changes according to the detected distance.
- Audible alerts using an active buzzer.
- Real-time obstacle monitoring.

---

# Components Used

| Component | Description |
|-----------|-------------|
| Arduino Uno | The main controller that processes sensor readings and controls all components. |
| HC-SR04 Ultrasonic Sensor | Measures the distance between the sensor and nearby objects using ultrasonic waves. |
| Servo Motor | Rotates to different angles to represent the current alert level. |
| Green LED | Indicates that the monitored area is safe. |
| Yellow LED | Indicates that an object is approaching. |
| Red LED | Indicates that an obstacle is very close. |
| Active Buzzer | Produces warning sounds to alert the user. |
| Breadboard | Used to assemble the circuit without soldering. |
| Jumper Wires | Used to connect all electronic components. |
| 220Ω Resistors | Protect the LEDs from excessive current. |

---

# System Operation

The ultrasonic sensor continuously measures the distance to the nearest object. The Arduino processes this value and activates different outputs depending on the measured distance.

###  Safe Zone (Distance > 15 cm)

- Green LED turns ON.
- Servo motor remains at 0°.
- Buzzer remains OFF.
- This indicates that no obstacle is nearby.

---

###  Warning Zone (Distance between 10 cm and 15 cm)

- Yellow LED turns ON.
- Servo motor rotates to 45° and remains in this position.
- The active buzzer plays one short warning tone when an object enters the warning zone, then stops.
- The LED and servo stay active until the object leaves the warning zone.

---

###  Danger Zone (Distance ≤ 10 cm)

- Red LED turns ON.
- Servo motor rotates to 90° and remains at this position.
- The active buzzer continuously sounds while the object remains in the danger zone.
- The alarm stops only when the obstacle moves away.

---

# Distance Behavior

| Distance | Green LED | Yellow LED | Red LED | Servo | Buzzer |
|----------|-----------|------------|---------|--------|---------|
| Greater than 15 cm | ON | OFF | OFF | 0° | OFF |
| Between 10 and 15 cm | OFF | ON | OFF | 45° | One short warning tone |
| Less than or equal to 10 cm | OFF | OFF | ON | 90° | Continuous alarm |

---

# Wiring Connections

| Component | Arduino Pin |
|-----------|-------------|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 Trig | D9 |
| HC-SR04 Echo | D10 |
| Servo Signal | D3 |
| Servo VCC | 5V |
| Servo GND | GND |
| Green LED | D5 |
| Yellow LED | D6 |
| Red LED | D7 |
| Active Buzzer | D8 |

---

# Project Images

## Front View

<img width="1280" height="960" alt="Front" src="https://github.com/user-attachments/assets/e883d404-c265-489d-ad12-3c0e3aaefd9d" />

---

## Side View

<img width="1280" height="960" alt="side" src="https://github.com/user-attachments/assets/ca7e2c68-de12-44ea-88a2-09ca3fba4bd8" />

---

## Top View

<img width="1280" height="960" alt="Top" src="https://github.com/user-attachments/assets/790bf311-6a23-4860-8f39-5a874399dde5" />

---

# Demonstration Video


https://github.com/user-attachments/assets/c071169c-0ff5-4091-9753-00592e03fe21


---

# Project Description

The project continuously monitors the surrounding area using an ultrasonic sensor. According to the measured distance, it changes the LED color, rotates the servo motor to indicate the alert level, and activates the buzzer to warn the user. The warning system becomes more noticeable as the detected object gets closer, making the project a simple example of an intelligent obstacle detection and alert system.

---

# Future Improvements

- Display the measured distance on an LCD or OLED display.
- Add Bluetooth or Wi-Fi connectivity.
- Send notifications to a mobile application.
- Add additional sensors for wider obstacle detection.
- Improve the system by logging distance measurements.












