#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

//#################################SERVO DEFINITIONS#################################
#define SERVO_FL_SIDE  0
#define SERVO_FL_UP    1

#define SERVO_FR_SIDE  2
#define SERVO_FR_UP    3

#define SERVO_RL_SIDE  4
#define SERVO_RL_UP    5

#define SERVO_RR_SIDE  6
#define SERVO_RR_UP    7

const int NUM_SERVOS = 8;

const int servoPins[NUM_SERVOS] = {
    13, 14, 16, 17,
    18, 19, 21, 22
};

// Minimum safe angle for each servo
const int servoMin[NUM_SERVOS] = {
    0, 0, 60, 0,
    60, 0, 0, 0
};

// Maximum safe angle for each servo
const int servoMax[NUM_SERVOS] = {
    120, 180, 180, 180,
    180, 180, 120, 180
};

// Calibration offset for each servo.
//
// Positive = servo moves further forward
// Negative = servo moves further backward
//
// Example:
//   Requested 90°, offset +5 → servo receives 95°
// Applied after inversion
const int servoOffset[NUM_SERVOS] = {
    0,  -7,  -12,  0,
    -7,  4,  -12,  0
};

const bool inverted[8] = {
    false,  // Servo 1
    false,   // Servo 2
    true,  // Servo 3
    true,   // Servo 4
    true,  // Servo 5
    true,  // Servo 6
    false,   // Servo 7
    false   // Servo 8
};

//#################################MOTION DEFINITIONS#################################
#define MAX_KEYFRAMES 16
#define LOOP_DURATION 5 // ms, 200Hz loop

#endif // CONSTANTS_HPP
