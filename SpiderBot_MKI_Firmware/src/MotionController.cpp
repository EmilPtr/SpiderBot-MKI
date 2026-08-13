#include "MotionController.hpp"
#include "ServoController.hpp"
#include "Motion.hpp"

static int loopCounter = 0;
static int keyframeIndex = 0;
static MotionState currentState = LYING;

void resetStateMachine(MotionState state) {
    currentState = state;
    loopCounter = 0;
    keyframeIndex = 0;
}

void updateStateMachine() {
    if (loopCounter > idleMotion.keyframes[keyframeIndex].loops) {
        setServos(idleMotion.keyframes[keyframeIndex].angles);
    }
    loopCounter++;
}