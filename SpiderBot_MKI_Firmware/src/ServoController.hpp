#ifndef SERVO_CONTROLLER_HPP
#define SERVO_CONTROLLER_HPP

#include "Constants.hpp"

/**
 * @brief Initialize all servos and attach them to their respective pins.
 */
void initServos();

/**
 * @brief Calculate the actual physical servo angle, adding calibration offset and applying inversion if necessary.
 * 
 * @param index The index of the servo.
 * @param requestedAngle The desired angle (0-180) before calibration/inversion.
 * @return The final angle to be sent to the physical servo.
 */
int getServoAngle(int index, int requestedAngle);

/**
 * @brief Set the position of one servo by index.
 * 
 * @param index The index of the servo (0 to NUM_SERVOS - 1).
 * @param requestedAngle The desired logical angle (0-180).
 */
void setServo(int index, int requestedAngle);

/**
 * @brief Set the positions of all servos at once.
 * 
 * @param angles An array of desired logical angles (0-180) for each servo.
 */
void setServos(const u_int8_t angles[NUM_SERVOS]);

/**
 * @brief Get the current positions of all servos.
 * 
 * @return A pointer to an array containing the current angles of all servos.
 */
u_int8_t* getServosPos();

#endif // SERVO_CONTROLLER_HPP
