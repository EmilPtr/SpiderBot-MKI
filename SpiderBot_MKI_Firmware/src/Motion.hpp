#ifndef MOTION_HPP
#define MOTION_HPP

#include <Arduino.h>
#include "Constants.hpp"

enum MotionState {
    IDLE,
    LYING,
    WALKING,
    TURNING_LEFT,
    TURNING_RIGHT
};

struct Keyframe {
    uint8_t angles[NUM_SERVOS];
    uint32_t loops; // The amount of loops the keyframe should have before moving to the next keyframe, linearly interpolating the angles between the keyframes.
};

struct Motion {
    Keyframe keyframes[MAX_KEYFRAMES];
    uint8_t keyframeCount;
};

const Motion idleMotion = {
    .keyframes = {
        {
            .angles = {45, 180, 45, 180, 45, 180, 45, 180},
            .loops = 200
        },
        {
            .angles = {45, 90, 45, 90, 45, 90, 45, 90},
            .loops = 200
        }
    },
    .keyframeCount = 2
};

const Motion lieMotion = {
    .keyframes = {
        {
            .angles = {45, 90, 45, 90, 45, 90, 45, 90},
            .loops = 2000
        }
    },
    .keyframeCount = 1
};

inline Motion getMotion(MotionState state) {
    switch (state) {
        case IDLE:
            return idleMotion;
        case LYING:
            return lieMotion;
        default:
            return idleMotion; // Default to idle if unknown state
    }
}

#endif // MOTION_HPP
