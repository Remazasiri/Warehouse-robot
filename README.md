# Warehouse Line-Following Robot with Obstacle Avoidance and Load Detection

## Overview
This project implements an autonomous warehouse robot capable of following a line, avoiding obstacles, detecting load weight, and dropping off packages using a servo mechanism.

## Features
- **Line Following**: Uses 3 IR sensors to detect and follow a black line.
- **Obstacle Avoidance**: Uses an ultrasonic sensor to detect obstacles and change path.
- **Load Detection**: Measures weight using a load cell.
- **Automated Drop-off**: Servo motor releases package when load is detected.

## Components
- Arduino Uno
- L298N Motor Driver
- 2x DC Motors with Wheels
- 3x IR Line Sensors
- HC-SR04 Ultrasonic Sensor
- HX711 Load Cell Amplifier + Load Cell
- Servo Motor (SG90 or similar)
- Li-ion Battery 7.4V
- Wires, Breadboard

## Wiring Diagram
- **Motors**: Connected to L298N motor driver outputs.
- **IR Sensors**: Connected to digital pins 2, 3, 4.
- **Ultrasonic Sensor**: TRIG to pin 12, ECHO to pin 13.
- **Servo**: Connected to pin 8.
- **Load Cell**: DOUT to A1, SCK to A0.

## How to Use
1. Connect the components as per the wiring diagram.
2. Upload `robot_code.ino` to the Arduino Uno.
3. Place the robot on a line track.
4. Ensure a load is placed for testing the drop-off feature.

## Working Envelope
- Designed for indoor warehouse floors with a predefined track.
- Operates on smooth, flat surfaces.
- Can carry small packages up to the load cell capacity.

## License
MIT License
