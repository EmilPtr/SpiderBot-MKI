#include "ControlHandler.hpp"

MotionState prevState = STOPPED;

void updateRobotState(MotionState state) {
    if (state != prevState) {
        prevState = state;
        resetStateMachine(state);
    } else {
        updateStateMachine();
    }
}