#ifndef CONTROL_HANDLER_HPP
#define CONTROL_HANDLER_HPP

#include "MotionController.hpp"

/**
 * @brief Update the robot's state and reset the state machine if the state has changed.
 * 
 * @param state The new motion state of the robot.
 */
void updateRobotState(MotionState state);

#endif // CONTROL_HANDLER_HPP
