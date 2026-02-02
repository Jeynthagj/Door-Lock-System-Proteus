Arduino-Based Digital Door Lock System
Project Overview
This project is an AI-Ready Electronic Security System designed to simulate a secure entry point. It uses a 4x3 Matrix Keypad for user input, an Arduino Uno for logic processing, and provides both visual feedback (LCD/LED) and physical actuation (Servo Motor).

Hardware Components (Proteus Simulation)
Microcontroller: Arduino Uno R3

Input: 4x3 Matrix Keypad

Output (Display): 16x2 I2C/Parallel LCD (LM016L)

Output (Actuator): Servo Motor (representing the lock bolt)

Indicators: Red LED for "Access Denied" signaling

How It Works
System Initialization: Upon startup, the LCD prompts the user to "ENTER PASSWORD".

Input Handling: The user enters a 4-digit code using the keypad.

Validation: * If the code matches the predefined password (1902), the LCD displays "PASS CORRECT", and the Servo Motor rotates 90° to unlock the door for 3 seconds.

If the code is incorrect, the LCD displays "PASS WRONG" and the Red LED flashes three times as an alarm.

Reset: The system automatically clears the input and returns to the "ENTER PASSWORD" state after each attempt.

Technical Implementation
The project is written in C++ (Arduino Framework) and utilizes the following libraries:

Keypad.h for matrix scanning.

Servo.h for PWM-based motor control.

LiquidCrystal.h for the 16x2 character display.
