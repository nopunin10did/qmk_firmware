#include "rev1.h"

void dip_switch_update_kb(uint8_t index, bool active) {
    if (index == 0) {
#ifdef RGB_MATRIX_ENABLE
    if (active) {
        rgb_matrix_set_flag( LED_FLAG_LIMIT_BRIGHTNESS );
    } else {
        rgb_matrix_unset_flag( LED_FLAG_LIMIT_BRIGHTNESS );
    }

    rgb_matrix_sethsv(rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val());
#endif
    }

    dip_switch_update_user(index, active);
}

#if defined(ENCODER_ENABLE) && !defined(SOL_CUSTOM_ENCODERS)
extern const uint16_t encoders[][NUMBER_OF_ENCODERS][2];

void encoder_update_kb(uint8_t index, bool clockwise) {
    if (!is_keyboard_master()) return;
    uint8_t layer = biton32(layer_state);
    uint16_t keycode = pgm_read_word(&encoders[layer][index][clockwise]);
    while (keycode == KC_TRANSPARENT && layer > 0)
    {
        layer--;
        if ((layer_state & (1 << layer)) != 0)
            keycode = pgm_read_word(&encoders[layer][index][clockwise]);
    }
    if (keycode != KC_TRANSPARENT)
        tap_code16(keycode);
}
#endif

#if !defined(SOL_CUSTOM_TOUCH_ENCODERS)
extern const uint16_t touch_encoders[][NUMBER_OF_TOUCH_ENCODERS][TOUCH_ENCODER_OPTIONS];

static void process_touch_encoder(uint8_t index, uint8_t option) {
    if (!is_keyboard_master()) return;
    uint8_t layer = biton32(layer_state);
    uint16_t keycode = pgm_read_word(&touch_encoders[layer][index][option]);
    while (keycode == KC_TRANSPARENT && layer > 0)
    {
        layer--;
        if ((layer_state & (1 << layer)) != 0)
            keycode = pgm_read_word(&touch_encoders[layer][index][option]);
    }
    if (keycode != KC_TRANSPARENT)
        tap_code16(keycode);
}

void touch_encoder_update_kb(uint8_t index, bool clockwise) {
    process_touch_encoder(index, TOUCH_SEGMENTS + clockwise);
}

void touch_encoder_tapped_kb(uint8_t index, uint8_t section) {
    process_touch_encoder(index, section);
}
#endif

#ifdef RGB_MATRIX_ENABLE
// clang-format off
led_config_t g_led_config = { {
    {  41,  42,  43,  44,  45,  46,  47 },
    {  54,  53,  52,  51,  50,  49,  48 },
    {  55,  56,  57,  58,  59,  60,  61 },
    {  68,  67,  66,  65,  64,  63,  62 },
    {  69,  70,  71,  72,  73,  74,  75,  76 },
    { 119, 120, 121, 122, 123, 124, 125 },
    { 132, 131, 130, 129, 128, 127, 126 },
    { 133, 134, 135, 136, 137, 138, 139 },
    { 146, 145, 144, 143, 142, 141, 140 },
    { 147, 148, 149, 150, 151, 152, 153 }
}, { // ALL XY VALUES DIVIDE BY 2, THEN ADD 5
    {   1,   6 }, {   1,  13 }, {   1,  19 }, {   1,  25 }, {   1,  31 }, {   1,  37 }, {   1,  43 }, {   1,  49 }, {   4,  52 }, {  11,  52 },
    {  17,  52 }, {  23,  52 }, {  29,  52 }, {  35,  52 }, {  41,  54 }, {  46,  57 }, {  52,  60 }, {  57,  63 }, {  62,  66 }, {  68,  69 },
    {  73,  67 }, {  76,  62 }, {  79,  57 }, {  78,  51 }, {  77,  45 }, {  76,  39 }, {  76,  33 }, {  76,  27 }, {  76,  21 }, {  76,  14 },
    {  76,   8 }, {  72,   3 }, {  59,   3 }, {  53,   3 }, {  46,   3 }, {  40,   3 }, {  34,   3 }, {  28,   3 }, {  22,   3 }, {  10,   3 }, {   3,   3 },
    {   9,   6 }, {  21,   6 }, {  30,   6 }, {  40,   6 }, {  49,   6 }, {  59,   6 }, {  71,   6 },
    {  71,  16 }, {  59,  16 }, {  49,  16 }, {  40,  16 }, {  30,  16 }, {  21,  16 }, {   9,  16 },
    {   9,  25 }, {  21,  25 }, {  30,  25 }, {  40,  25 }, {  49,  25 }, {  59,  25 }, {  71,  25 },
    {  71,  35 }, {  59,  35 }, {  49,  35 }, {  40,  35 }, {  30,  35 }, {  21,  35 }, {   9,  35 },
    {   9,  44 }, {  21,  44 }, {  30,  44 }, {  40,  44 }, {  49,  44 }, {  66,  50 }, {  75,  54 }, {  70,  62 }, {  60,  60 },

    { 160,   6 }, { 160,  13 }, { 160,  19 }, { 160,  25 }, { 160,  31 }, { 160,  37 }, { 160,  43 }, { 160,  49 }, { 157,  52 }, { 151,  52 },
    { 145,  52 }, { 138,  52 }, { 132,  52 }, { 126,  52 }, { 120,  54 }, { 115,  57 }, { 110,  60 }, { 105,  63 }, {  99,  66 }, {  94,  69 },
    {  89,  67 }, {  86,  62 }, {  83,  57 }, {  83,  51 }, {  85,  45 }, {  86,  39 }, {  86,  33 }, {  86,  27 }, {  86,  21 }, {  86,  14 },
    {  86,   8 }, {  90,   3 }, { 103,   3 }, { 109,   3 }, { 115,   3 }, { 121,   3 }, { 127,   3 }, { 133,   3 }, { 140,   3 }, { 152,   3 }, { 158,   3 },
    { 153,   6 }, { 141,   6 }, { 131,   6 }, { 122,   6 }, { 112,   6 }, { 103,   6 }, {  91,   6 },
    {  91,  16 }, { 103,  16 }, { 112,  16 }, { 122,  16 }, { 131,  16 }, { 141,  16 }, { 153,  16 },
    { 153,  25 }, { 141,  25 }, { 131,  25 }, { 122,  25 }, { 112,  25 }, { 103,  25 }, {  91,  25 },
    {  91,  35 }, { 103,  35 }, { 112,  35 }, { 122,  35 }, { 131,  35 }, { 141,  35 }, { 153,  35 },
    { 153,  44 }, { 141,  44 }, { 131,  44 }, { 122,  44 }, { 112,  44 }, {  96,  50 }, {  87,  54 }, {  92,  62 }, { 102,  60 },
}, {
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    1, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1,

    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    1, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1
} };
// clang-format on
#endif
