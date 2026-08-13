#ifndef MOTION_CONTROLLER_HPP
#define MOTION_CONTROLLER_HPP

#include "Motion.hpp"

/**
 * @brief Reset the motion state machine.
 * 
 * @param state The target motion state.
 */
void resetStateMachine(MotionState state);

/**
 * @brief Update the motion state machine based on the current state.
 */
void updateStateMachine();

#endif // MOTION_CONTROLLER_HPP
