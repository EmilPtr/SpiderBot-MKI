#include "ControlHandler.hpp"

MotionState prevState = LYING;

void updateRobotState(MotionState state) {
    if (state != prevState) {
        prevState = state;
        resetStateMachine(state);
    } else {
        updateStateMachine();
    }
}