#include "ControlHandler.hpp"

MotionState prevState = IDLE;

void updateRobotState(MotionState state) {
    if (state != prevState) {
        prevState = state;
        resetStateMachine(state);
    } else {
        updateStateMachine();
    }
}