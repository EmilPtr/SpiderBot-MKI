#ifndef MOTION_HPP
#define MOTION_HPP

#include <Arduino.h>
#include "Constants.hpp"

// ######### GAIT CONSTANTS #########
#define HOME_WALK_F 45
#define HOME_WALK_B 45
#define UNIT_WALK 5

#define HOME_TURN_F 45
#define HOME_TURN_B 45
#define UNIT_TURN 2

#define LEG_PLANT 180
#define LEG_GAIT_UP 160

// #####################################

enum MotionState {
    IDLE,
    LYING,
    WALKING,
    TURNING_LEFT,
    TURNING_RIGHT
};

struct Keyframe {
    int angles[NUM_SERVOS];
    uint32_t loops; // The amount of loops the keyframe should have before moving to the next keyframe, linearly interpolating the angles between the keyframes.
};

struct Motion {
    Keyframe keyframes[MAX_KEYFRAMES];
    int keyframeCount;
};

const Motion idleMotion = {
    .keyframes = {
        {
            .angles = {45, 180, 45, 180, 45, 180, 45, 180},
            .loops = 200
        },
    },
    .keyframeCount = 1
};

const Motion lieMotion = {
    .keyframes = {
        {
            .angles = {45, 90, 45, 90, 45, 90, 45, 90},
            .loops = 200
        }
    },
    .keyframeCount = 1
};

const Motion walkMotion = {
    .keyframes = {

    // ─────────────────────────────────────────
    // START
    // ─────────────────────────────────────────

    {
        .angles = {
            HOME_WALK_F,
            LEG_PLANT,

            HOME_WALK_F + (4 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (6 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (2 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },


    // ─────────────────────────────────────────
    // CREEP × 2
    // ─────────────────────────────────────────

    {
        .angles = {
            HOME_WALK_F + (1 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (5 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (7 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (3 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },

    {
        .angles = {
            HOME_WALK_F + (2 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (6 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (8 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (4 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },


    // ─────────────────────────────────────────
    // LIFT LB
    // ─────────────────────────────────────────

    {
        .angles = {
            HOME_WALK_F + (3 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (7 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (3 * UNIT_WALK),
            LEG_GAIT_UP,

            HOME_WALK_B - (5 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },

    {
        .angles = {
            HOME_WALK_F + (4 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (8 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B,
            LEG_PLANT,

            HOME_WALK_B - (6 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },


    // ─────────────────────────────────────────
    // CREEP × 2
    // ─────────────────────────────────────────

    {
        .angles = {
            HOME_WALK_F + (5 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (9 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (1 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (7 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },

    {
        .angles = {
            HOME_WALK_F + (6 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (10 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (2 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (8 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },


    // ─────────────────────────────────────────
    // LIFT RF
    // ─────────────────────────────────────────

    {
        .angles = {
            HOME_WALK_F + (7 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (5 * UNIT_WALK),
            LEG_GAIT_UP,

            HOME_WALK_B - (3 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (9 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },

    {
        .angles = {
            HOME_WALK_F + (8 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F,
            LEG_PLANT,

            HOME_WALK_B - (4 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (10 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },


    // ─────────────────────────────────────────
    // CREEP × 2
    // ─────────────────────────────────────────

    {
        .angles = {
            HOME_WALK_F + (9 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (1 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (5 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (11 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },

    {
        .angles = {
            HOME_WALK_F + (10 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (2 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (6 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (12 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },


    // ─────────────────────────────────────────
    // LIFT RB
    // ─────────────────────────────────────────

    {
        .angles = {
            HOME_WALK_F + (11 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (3 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (3 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (7 * UNIT_WALK),
            LEG_GAIT_UP
        },
        .loops = 15
    },

    {
        .angles = {
            HOME_WALK_F + (12 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (4 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (4 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B,
            LEG_PLANT
        },
        .loops = 15
    },


    // ─────────────────────────────────────────
    // CREEP × 2
    // ─────────────────────────────────────────

    {
        .angles = {
            HOME_WALK_F + (13 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (5 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (5 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (1 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },

    {
        .angles = {
            HOME_WALK_F + (14 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_F + (6 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (6 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (2 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },


    // ─────────────────────────────────────────
    // LIFT LF
    // ─────────────────────────────────────────

    {
        .angles = {
            HOME_WALK_F + (11 * UNIT_WALK),
            LEG_GAIT_UP,

            HOME_WALK_F + (7 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (7 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (3 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    },

    {
        .angles = {
            HOME_WALK_F,
            LEG_PLANT,

            HOME_WALK_F + (4 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (8 * UNIT_WALK),
            LEG_PLANT,

            HOME_WALK_B - (4 * UNIT_WALK),
            LEG_PLANT
        },
        .loops = 15
    }
},

.keyframeCount = 17
};



inline Motion getMotion(MotionState state) {
    switch (state) {
        case IDLE:
            return idleMotion;
        case LYING:
            return lieMotion;
        case WALKING:
            return walkMotion;
        case TURNING_RIGHT:
            return turnRightMotion;
        case TURNING_LEFT:
            return turnLeftMotion;
        default:
            return idleMotion; // Default to idle if unknown state
    }
}



#endif // MOTION_HPP
