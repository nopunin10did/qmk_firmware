#pragma once

#include "quantum.h"
#include "sol3.h"

// clang-format off
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06,           R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26,           R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36,           R30, R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43, L44, L45, L46, L47, R40, R41, R42, R43, R44, R45, R46, R47  \
) \
{ \
    /* Left Half */ \
    { L00, L01, L02, L03, L04, L05, L06, KC_NO }, \
    { L10, L11, L12, L13, L14, L15, L16, KC_NO }, \
    { L20, L21, L22, L23, L24, L25, L26, KC_NO }, \
    { L30, L31, L32, L33, L34, L35, L36, KC_NO }, \
    { L40, L41, L42, L43, L44, L45, L46, L47}, \
    /* Right Half */ \
    { R06, R05, R04, R03, R02, R01, R00, KC_NO }, \
    { R16, R15, R14, R13, R12, R11, R10, KC_NO }, \
    { R26, R25, R24, R23, R22, R21, R20, KC_NO }, \
    { R36, R35, R34, R33, R32, R31, R30, KC_NO }, \
    { R47, R46, R45, R44, R43, R42, R41, R40 }  \
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

#define NUMBER_OF_ENCODERS 12
#define ENCODER_OPTIONS 2

#define ENCODER_LAYOUT( \
    E010, E011, \
    E020, E021, \
    E030, E031, \
    E040, E041, \
    E050, E051, \
    E060, E061, \
    E070, E071, \
    E080, E081, \
    E090, E091, \
    E100, E101, \
    E110, E111, \
    E120, E121 \
) \
{ \
    { E010, E011 }, \
    { E020, E021 }, \
    { E030, E031 }, \
    { E040, E041 }, \
    { E050, E051 }, \
    { E060, E061 }, \
    { E070, E071 }, \
    { E080, E081 }, \
    { E090, E091 }, \
    { E100, E101 }, \
    { E110, E111 }, \
    { E120, E121 } \
}
// clang-format on
