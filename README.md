# Professional Traffic Light Sequence Using Arduino

# You can test the traffic light simulation directly in your browser: 
[Run Traffic Light Simulation](https://wokwi.com/projects/440885017258592257)

# Description

This project simulates a realistic traffic light system using an Arduino Uno. It demonstrates:

1. Non-blocking timing using millis() (no delay() used)
2. State machine design for clean, professional code
3. Sequential LED control for Red, Yellow, and Green lights
4. Realistic traffic light timing

The LED sequence follows real-world behavior:

# State	Duration
  RED	             5   seconds
  RED + YELLOW	   2   seconds
  GREEN            5   seconds
  YELLOW           2   seconds
# Components Required

1. Arduino Uno (or compatible)
2. 3 LEDs (Red, Yellow, Green)
3. 220Ω resistors for each LED
4. Breadboard and connecting wires

# How to Use

Connect the LEDs to the Arduino pins as described below.

Upload the Arduino sketch to your board.

The traffic light sequence will run continuously in real-time.

# Pin Assignments
# LED	Arduino Pin

1. RED	4
2. YELLOW	5
3. GREEN	6

# Features

Non-blocking real-time operation — can be extended for additional functionality
State machine-based design — modular, easy to maintain

State machine-based design — modular, easy to maintain

Simulation-ready
