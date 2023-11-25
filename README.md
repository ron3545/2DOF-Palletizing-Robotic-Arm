# 2DOF-Palletizing-Robotic-Arm


https://github.com/ron3545/2DOF-Palletizing-Robotic-Arm/assets/86136180/2ca8c2c6-7654-45f2-bd2a-3b558dc1a0e7

## Overview

The goal of this project is to create a robotic system capable of precise control and movement. The system consists of multiple joints, each driven by individual motors, and it incorporates sensor feedback to achieve accurate positioning. The project aims to demonstrate the integration of various technologies to build a functional robotic arm.

## Setup

1. Connect the stepper motors to the specified pins (MOTOR_LEFT_STEP, MOTOR_LEFT_DIR, MOTOR_RIGHT_STEP, MOTOR_RIGHT_DIR).
2. Connect the IR sensor to the specified pin (IR_SENSOR_PIN).
3. Ensure that the IR remote control is available for user input.

## Functions

### `setup()`

- Initializes serial communication.
- Sets up the stepper motors with acceleration parameters.
- Configures the IR sensor pin as an input.
- Enables the IR receiver.

### `loop()`

- Listens for user input through the IR remote.
- Checks the IR sensor for box presence.
- Calls relevant functions based on user input or box detection.

### `handleRemoteInput(unsigned long value)`

- Handles different remote button presses.
- Calls corresponding functions for movement control and box counting.

### `moveLeft()`

- Moves the left motor to the desired position.
- Blocks until the movement is complete.

### `moveRight()`

- Moves the right motor to the desired position.
- Blocks until the movement is complete.

### `increaseBoxes()`

- Increases the number of boxes to be placed on the left side.
- Prints the updated number of boxes.

### `decreaseBoxes()`

- Decreases the number of boxes on the left side (if greater than zero).
- Prints the updated number of boxes.

### `palletize()`

- Placeholder function for the palletizing logic.
- Executes when the IR sensor detects a box.
- Modify this function to implement the specific palletizing operations.

## Customization

- Adjust `STEPS_PER_DEGREE` based on your motor and gearing specifications.
- Modify `calculateStepsForMovement()` to suit the required movement for your robotic arm.
- Implement palletizing logic in the `palletize()` function based on your project requirements.

## Challenges Faced During the Build
- Motor Control and Positioning - Implementing accurate motor control and positioning is a significant challenge. This involves integrating encoders and sensors to ensure precise movement and alignment of each joint.
- Sensor Intigration - Implementing accurate motor control and positioning is a significant challenge. This involves integrating encoders and sensors to ensure precise movement and alignment of each joint.
- PS2 Controller Interface - mplementing a robust interface with a PS2 controller involves managing joystick and button inputs, translating them into meaningful commands, and ensuring real-time responsiveness.
- Technology Integration - Bringing together various technologies, including magnetic encoders, motor control algorithms, sensor feedback, and PS2 controller communication, requires careful integration and coordination.

## Technologies Behind It
- Magnetic Encoders - Magnetic encoders, such as the AS5600, are used for precise angle measurement. They provide feedback to control the position and movement of each joint.
- Motor Control - Motor control involves using PID algorithms and custom motor control logic to accurately position and move the motors. Stepper and normal motors are employed based on specific requirements.
- PS2 Controller Interface - The project utilizes a PlayStation 2 (PS2) controller for user input. The PS2 library facilitates the communication and interpretation of joystick and button signals.
- Arduino Platform - The Arduino platform is the core of the project, providing an environment for coding, sensor integration, and motor control. The code is written in C++ using the Arduino IDE.
- Wiring and Electronics - The project involves wiring and electronics to connect and interface sensors, motors, and controllers. Careful circuit design and wiring are essential for reliable operation.
  
## Notes

- This is a basic template; customize it based on your specific robotic arm design and requirements.
- Ensure proper connections and power supply for the motors and sensors.
- Refer to the datasheets of your components for detailed specifications.
