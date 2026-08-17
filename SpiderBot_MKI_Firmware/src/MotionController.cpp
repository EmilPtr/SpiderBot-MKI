#include "MotionController.hpp"
#include "ServoController.hpp"
#include "Motion.hpp"
#include <Easing.h>
#include <Arduino.h>

EasingFunc<Ease::Linear> interpolator;

static int loopCounter = 0;
static int keyframeIndex = 0;
static MotionState currentState = LYING;

static int startAnglesBuffer[NUM_SERVOS];

void resetStateMachine(MotionState state) {
    currentState = state;
    loopCounter = 0;
    keyframeIndex = 0;
}

void commandMotion(int* start, int* target, int loops) {
    float progress = loopCounter / (float)loops; // Calculate progress as a float between 0 and 1
    float easedProgress = interpolator.get(progress); // Apply easing function

    for (int i = 0; i < NUM_SERVOS; i++) {
        int startAngle = start[i];
        int targetAngle = target[i];
    
        int error = targetAngle - startAngle;
        int newAngle = startAngle + (error * easedProgress);

        setServo(i, newAngle);
    }
}

void updateStateMachine() {
    int* startingPoint = nullptr;
    int* targetPoint = nullptr;

    if (keyframeIndex == 0) {
        if (loopCounter == 0) {
            // Store the current servo angles as the starting point for the first keyframe
            for (int i = 0; i < NUM_SERVOS; i++) {
                startAnglesBuffer[i] = getServosPos()[i];
            }
        }

        startingPoint = startAnglesBuffer;
        targetPoint = getMotion(currentState).keyframes[keyframeIndex].angles;
    } else {
        startingPoint = getMotion(currentState).keyframes[keyframeIndex - 1].angles;
        targetPoint = getMotion(currentState).keyframes[keyframeIndex].angles;
    }
    if (loopCounter < getMotion(currentState).keyframes[keyframeIndex].loops) {
        commandMotion(startingPoint, targetPoint, getMotion(currentState).keyframes[keyframeIndex].loops);
        loopCounter++;
    } else {
        keyframeIndex++;

        if (keyframeIndex >= getMotion(currentState).keyframeCount) {
            keyframeIndex = 0; // Loop back to the first keyframe
        }
        loopCounter = 0;
    }
}