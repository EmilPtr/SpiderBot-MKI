#include <Arduino.h>
#include <ESP32Servo.h>
#include "Constants.hpp"
#include "ServoController.hpp"

static u_int8_t servosPos[NUM_SERVOS] = {0};

// Servo objects for each of the 8 servos
static Servo servos[NUM_SERVOS];

// Initialize all servos and attach them to their respective pins
void initServos() {
    for (int i = 0; i < NUM_SERVOS; i++) {
        servos[i].attach(servoPins[i]);
    }
}

// Calculate the actual physical servo angle, adding calibration offset and applying inversion if necessary
int getServoAngle(int index, int requestedAngle) {

    // Clamp requested angle to this servo's allowed range
    int angle = constrain(
        requestedAngle,
        servoMin[index],
        servoMax[index]
    );

    // Universal 0-180 inversion
    if (inverted[index]) {
        angle = 180 - angle;
    }

    // Apply calibration offset AFTER inversion
    angle += servoOffset[index];

    return angle;
}


// Set the position of one servo
void setServo(int index, int requestedAngle) {

    if (index < 0 || index >= NUM_SERVOS) {
        return;
    }

    int actualAngle = getServoAngle(
        index,
        requestedAngle
    );

    servos[index].write(actualAngle);
    servosPos[index] = requestedAngle; // Store the requested angle, not the actual angle
}

void setServos(const u_int8_t angles[NUM_SERVOS]) {
    for (int i = 0; i < NUM_SERVOS; i++) {
        setServo(i, angles[i]);
    }
}

u_int8_t* getServosPos() {
    return servosPos;
}