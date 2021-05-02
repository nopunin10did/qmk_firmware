#pragma once

#include "quantum.h"
#include "zygomorph2.h"

// clang-format off
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
    L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, R45 \
) \
{ \
    /* Left Half */ \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { L40, L41, L42, L43, L44, L45}, \
    /* Right Half */ \
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, R33, R34, R35 }, \
    { R40, R41, R42, R43, R44, R45 }  \
}

#define NUMBER_OF_TOUCH_ENCODERS 2
#define TOUCH_ENCODER_OPTIONS TOUCH_SEGMENTS + 2

#define TOUCH_ENCODER_LAYOUT( \
    E10, E11, E12, E13, E14, \
    E20, E21, E22, E23, E24 \
) \
{ \
    { E10, E11, E12, E13, E14 }, \
    { E20, E21, E22, E23, E24 } \
}

#define NUMBER_OF_ENCODERS 4
#define ENCODER_OPTIONS 2

#define ENCODER_LAYOUT( \
    E10, E11, \
    E20, E21, \
    E30, E31, \
    E40, E41 \
) \
{ \
    { E10, E11 }, \
    { E20, E21 }, \
    { E30, E31 }, \
    { E40, E41 } \
}
// clang-format on
