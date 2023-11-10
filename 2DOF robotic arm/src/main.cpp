#include <AccelStepper.h>
#include <IRremote.h>

// Define stepper motor pins
#define MOTOR_LEFT_STEP 2
#define MOTOR_LEFT_DIR 3
#define MOTOR_RIGHT_STEP 4
#define MOTOR_RIGHT_DIR 5

// Define IR sensor pin
#define IR_SENSOR_PIN 6

// Define buttons for user input using IR remote
#define BUTTON_LEFT 0xFFA25D
#define BUTTON_RIGHT 0xFF629D
#define BUTTON_UP 0xFFE21D
#define BUTTON_DOWN 0xFF22DD

// Define other constants
#define STEPS_PER_DEGREE 10 // Adjust based on your motor and gearing

AccelStepper stepperLeft(AccelStepper::DRIVER, MOTOR_LEFT_STEP, MOTOR_LEFT_DIR);
AccelStepper stepperRight(AccelStepper::DRIVER, MOTOR_RIGHT_STEP, MOTOR_RIGHT_DIR);

IRrecv irrecv(IR_SENSOR_PIN);
decode_results results;

int numberOfBoxesLeft = 0;
int numberOfBoxesRight = 0;

void setup() {
  Serial.begin(9600);

  // Set up stepper motors
  stepperLeft.setMaxSpeed(1000);
  stepperLeft.setAcceleration(500);

  stepperRight.setMaxSpeed(1000);
  stepperRight.setAcceleration(500);

  // Set up IR sensor
  pinMode(IR_SENSOR_PIN, INPUT);

  // Start the IR receiver
  irrecv.enableIRIn();
}

void loop() {
  // Check IR remote for user input
  if (irrecv.decode(&results)) {
    handleRemoteInput(results.value);
    irrecv.resume();
  }

  // Check IR sensor for box presence
  if (digitalRead(IR_SENSOR_PIN) == HIGH) {
    palletize();
  }
}

void handleRemoteInput(unsigned long value) {
  switch (value) {
    case BUTTON_LEFT:
      moveLeft();
      break;
    case BUTTON_RIGHT:
      moveRight();
      break;
    case BUTTON_UP:
      increaseBoxes();
      break;
    case BUTTON_DOWN:
      decreaseBoxes();
      break;
    default:
      // Handle other remote button presses if needed
      break;
  }
}

void moveLeft() {
  // Move the left motor to the desired position
  stepperLeft.moveTo(calculateStepsForMovement()); // Adjust based on your requirement
  while (stepperLeft.distanceToGo() != 0) {
    stepperLeft.run();
  }
}

void moveRight() {
  // Move the right motor to the desired position
  stepperRight.moveTo(calculateStepsForMovement()); // Adjust based on your requirement
  while (stepperRight.distanceToGo() != 0) {
    stepperRight.run();
  }
}

void increaseBoxes() {
  // Increase the number of boxes to be placed
  numberOfBoxesLeft++;
  Serial.println("Number of boxes on the left: " + String(numberOfBoxesLeft));
}

void decreaseBoxes() {
  // Decrease the number of boxes to be placed
  if (numberOfBoxesLeft > 0) {
    numberOfBoxesLeft--;
    Serial.println("Number of boxes on the left: " + String(numberOfBoxesLeft));
  }
}

void palletize() {
  // Palletizing logic goes here
  // Implement the steps to pick and place boxes based on your design
  Serial.println("Palletizing operation");
  // Update the number of boxes or perform other actions as needed
}
