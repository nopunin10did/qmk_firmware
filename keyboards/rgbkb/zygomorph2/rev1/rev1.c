#include "rev1.h"

#if defined(ENCODER_ENABLE) && !defined(ZYGOMORPH_CUSTOM_ENCODERS)
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

#if !defined(ZYGOMORPH_CUSTOM_TOUCH_ENCODERS)
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
    {   0,   1,   2,   3,   4,   5 },
    {  11,  10,   9,   8,   7,   6 },
    {  12,  13,  14,  15,  16,  17 },
    {  23,  22,  21,  20,  19,  18 },
    {  24,  25,  26,  27,  28,  29 },
    {  42,  43,  44,  45,  46,  47 },
    {  53,  52,  51,  50,  49,  48 },
    {  54,  55,  56,  57,  58,  59 },
    {  65,  64,  63,  62,  61,  60 },
    {  66,  67,  68,  69,  70,  71 }
}, {
    {   0,   0 }, {  19,   0 }, {  38,   0 }, {  57,   0 }, {  76,   0 }, {  95,   0 },
    {  95,  19 }, {  76,  19 }, {  57,  19 }, {  38,  19 }, {  19,  19 }, {   0,  19 },
    {   0,  38 }, {  19,  38 }, {  38,  38 }, {  57,  38 }, {  76,  38 }, {  95,  38 },
    {  95,  57 }, {  76,  57 }, {  57,  57 }, {  38,  57 }, {  19,  57 }, {   0,  57 },
    {   0,  76 }, {  19,  76 }, {  38,  76 }, {  57,  76 }, {  76,  76 }, {  95,  76 },

    {  67,  76 }, {  48,  76 }, {  29,  76 }, {  10,  57 }, {  10,  38 }, {  10,  19 }, {  29,   0 }, {  48,   0 }, {  67,   0 }, {  86,  19 }, {  86,  38 }, {  86,  57 },
    
    { 114,   0 }, { 133,   0 }, { 152,   0 }, { 171,   0 }, { 190,   0 }, { 209,   0 },
    { 209,  19 }, { 190,  19 }, { 171,  19 }, { 152,  19 }, { 133,  19 }, { 114,  19 },
    { 114,  38 }, { 133,  38 }, { 152,  38 }, { 171,  38 }, { 190,  38 }, { 209,  38 },
    { 209,  57 }, { 190,  57 }, { 171,  57 }, { 152,  57 }, { 133,  57 }, { 114,  57 },
    { 114,  76 }, { 133,  76 }, { 152,  76 }, { 171,  76 }, { 190,  76 }, { 209,  76 },
    
    { 181,  76 }, { 162,  76 }, { 143,  76 }, { 124,  57 }, { 124,  38 }, { 124,  19 }, { 143,   0 }, { 162,   0 }, { 181,   0 }, {  86,  19 }, {  86,  38 }, {  86,  57 },
}, {
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    1, 1, 1, 1, 1, 1,

    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

    4, 4, 4, 4, 4, 1,
    4, 4, 4, 4, 4, 1,
    4, 4, 4, 4, 4, 1,
    4, 4, 4, 4, 4, 1,
    1, 1, 1, 1, 1, 1,

    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
} };
// clang-format on
#endif
