# Elevator Control System

The Elevator Control System is an Arduino-based project that implements a simple elevator control system capable of operating across three floors. It utilizes various electronic components and programming logic to control the elevator's movement and doors.

## Components Used

The following components are used in this project:

- Arduino board (e.g., Arduino Uno)
- Stepper motor (with appropriate driver)
- Magnetic sensors (to detect the elevator's position)
- Push buttons (for floor selection)
- LEDs (to simulate doors)
- Motor driver (to control the stepper motor)
- Resistors, wires, and breadboard (for circuit connections)

## Setup

To set up the Elevator Control System, follow these steps:

1. Connect the Arduino board to the necessary components, including the stepper motor, magnetic sensors, push buttons, LEDs, and motor driver, as per the circuit diagram provided.

2. Upload the provided Arduino code (`elevator_control_system.ino`) to the Arduino board using the Arduino IDE or any other suitable method.

3. Verify the pin connections in the code and adjust them if necessary to match your specific wiring setup.

4. Power up the Arduino board and ensure that all the components are functioning correctly.

## How it Works

The Elevator Control System operates based on interrupt-based input from the floor buttons (push buttons) to register floor requests. The main code loop continuously checks the EEPROM memory for floor requests and performs the necessary actions to move the elevator and open/close the doors.

Here's an overview of the system's functioning:

1. When a floor button is pressed, the corresponding interrupt service routine (ISR) is triggered, and the requested floor is stored in the EEPROM memory.

2. The main code loop constantly checks the EEPROM memory for pending floor requests.

3. If a floor request is found in the EEPROM memory, the system takes appropriate action to move the elevator to the requested floor.

4. The magnetic sensors detect the elevator's position, allowing the system to determine the current floor.

5. The stepper motor is controlled to move the elevator between floors. The direction and number of steps are adjusted based on the floor request and the elevator's current position.

6. The motor driver receives signals from the Arduino to drive the stepper motor accordingly.

7. The doors are simulated using LEDs. The system turns on/off the appropriate LEDs to represent the open or closed state of the doors.

## Important Functions

The Elevator Control System includes the following important functions:

- `ISR1()`, `ISR2()`, `ISR3()`: These interrupt service routines handle the floor button presses. They store the requested floor in the EEPROM memory.

- `zero()`, `one()`, `two()`, `nul()`: These helper functions control the LED display to indicate the current floor.

- `showSeq()`: This helper function displays the sequence of floor requests stored in the EEPROM memory.

- `setup()`: This Arduino setup function initializes pin modes, attaches interrupt handlers, and performs other necessary setup tasks.

- `loop()`: This Arduino main loop function continuously checks the EEPROM memory for floor requests and controls the elevator's movement and doors accordingly.

## Usage and Limitations

- The Elevator Control System is designed for a three-floor setup. However, you can modify the code and hardware connections to support more floors if needed.

- The provided code offers a basic implementation. You can expand upon it to include additional features such as floor indicators, emergency stop functionality, or user interface enhancements.

## Author

- Prajwal Dutta
- GitHub: [SciNoLimits](https://github.com/SciNoLimits)
