# 2DOF-Palletizing-Robotic-Arm


https://github.com/ron3545/2DOF-Palletizing-Robotic-Arm/assets/86136180/2ca8c2c6-7654-45f2-bd2a-3b558dc1a0e7

## Overview

This Arduino program is designed for a 2 Degrees of Freedom (2DOF) robotic arm used in a palletizing system. The system incorporates two NEMA 17 stepper motors for arm movement and an IR sensor for box detection. The user can interact with the system using an IR remote control to specify the number of boxes to be placed on the left side of the robotic arm.

## Components

- **Stepper Motors:**
  - Left Motor (MOTOR_LEFT_STEP, MOTOR_LEFT_DIR)
  - Right Motor (MOTOR_RIGHT_STEP, MOTOR_RIGHT_DIR)

- **IR Sensor:**
  - Pin: IR_SENSOR_PIN

- **IR Remote:**
  - Buttons:
    - Left: BUTTON_LEFT
    - Right: BUTTON_RIGHT
    - Up: BUTTON_UP
    - Down: BUTTON_DOWN

## Libraries Used

- **AccelStepper:**
  - Used for smooth acceleration and deceleration of stepper motors.

- **IRremote:**
  - Used for interfacing with the IR remote control.

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

## Notes

- This is a basic template; customize it based on your specific robotic arm design and requirements.
- Ensure proper connections and power supply for the motors and sensors.
- Refer to the datasheets of your components for detailed specifications.
