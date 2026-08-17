#include <Arduino.h>
#include "Constants.hpp"
#include "ServoController.hpp"
#include "ControlHandler.hpp"
#include "Motion.hpp"

static unsigned long pastMillis = 0;

MotionState state = TURNING_RIGHT;
static bool isMoving = true;

void setup() {
    Serial.begin(115200);
    initServos();
    Serial.println("Servos Initialized");
    setServo(SERVO_FL_SIDE, 45);
    setServo(SERVO_FR_SIDE, 45);
    setServo(SERVO_RL_SIDE, 45);
    setServo(SERVO_RR_SIDE, 45);
    setServo(SERVO_FL_UP, 180);
    setServo(SERVO_FR_UP, 180);
    setServo(SERVO_RL_UP, 180);
    setServo(SERVO_RR_UP, 180);
    delay(500);
}

void loop() {
    if ((millis() - pastMillis) >= LOOP_DURATION && isMoving) {
        updateRobotState(state);
        pastMillis = millis();
    }
}