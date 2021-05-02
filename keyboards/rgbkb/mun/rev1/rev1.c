#include "rev1.h"

static void tap_keycode(uint16_t keycode) {
    if (keycode < QK_MODS_MAX) {
        tap_code16(keycode);
    }
    else {
        keyrecord_t pressed = {{{0,0},true,0}, {0,0,0,0,0}};
        process_record_quantum_keycode(keycode, &pressed);
    #if TAP_CODE_DELAY > 0
        wait_ms(TAP_CODE_DELAY);
    #endif
        pressed.event.pressed = false;
        process_record_quantum_keycode(keycode, &pressed);
    }

    // if (keycode >= SAFE_RANGE) {
    //     xprintf("kc\n");
    //     keyrecord_t pressed = {{{0,0},true,0}, {0,0,0,0,0}};
    //     process_record_kb(keycode, &pressed);
    // }
    // else
    //     tap_code16(keycode);
}

#if defined(ENCODER_ENABLE) && !defined(MUN_CUSTOM_ENCODERS)
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
    if (keycode != KC_TRANSPARENT) {
        tap_keycode(keycode);
    }
}
#endif

#if !defined(MUN_CUSTOM_TOUCH_ENCODERS)
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
    if (keycode != KC_TRANSPARENT) {
        tap_keycode(keycode);
    }
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
    {   0,   1,   2,   3,   4,   5,   6 },
    {  13,  12,  11,  10,   9,   8,   7 },
    {  14,  15,  16,  17,  18,  19,  20 },
    {  27,  26,  25,  24,  23,  22,  21 },
    {  28,  29,  30,  31,  32,  33,  34 },
    {  49,  50,  51,  52,  53,  54,  55 },
    {  62,  61,  60,  59,  58,  57,  56 },
    {  63,  64,  65,  66,  67,  68,  69 },
    {  76,  75,  74,  73,  72,  71,  70 },
    {  77,  78,  79,  80,  81,  82,  83 }
}, {
    {  16,  16},{  34,  16},{  49,  16},{  64,  16},{  79,  16},{  94,  16},{ 109,  16},
    { 109,  31},{  94,  31},{  79,  31},{  64,  31},{  49,  31},{  34,  31},{  16,  31},
    {  16,  46},{  34,  46},{  49,  46},{  64,  46},{  79,  46},{  94,  46},{ 109,  46},
    { 109,  61},{  94,  61},{  79,  61},{  64,  61},{  49,  61},{  34,  61},{  16,  61},
    {  16,  76},{  34,  76},{  49,  76},{  64,  76},{  83,  72},{  98,  72},{ 113,  72},
    {  97,   5},{  91,   5},{  86,   5},{  80,   5},{  75,   5},{  69,   5},{  63,   5},{  58,   5},{  52,   5},{  46,   5},{  41,   5},{  35,   5},{  30,   5},{  24,   5},
    { 240,  16},{ 222,  16},{ 207,  16},{ 192,  16},{ 177,  16},{ 162,  16},{ 147,  16},
    { 147,  31},{ 162,  31},{ 177,  31},{ 192,  31},{ 207,  31},{ 222,  31},{ 240,  31},
    { 240,  46},{ 222,  46},{ 207,  46},{ 192,  46},{ 177,  46},{ 162,  46},{ 147,  46},
    { 147,  61},{ 162,  61},{ 177,  61},{ 192,  61},{ 207,  61},{ 222,  61},{ 240,  61},
    { 240,  76},{ 222,  76},{ 207,  76},{ 192,  76},{ 180,  72},{ 165,  72},{ 150,  72},
    { 159,   5},{ 164,   5},{ 170,   5},{ 176,   5},{ 181,   5},{ 187,   5},{ 192,   5},{ 198,   5},{ 204,   5},{ 209,   5},{ 215,   5},{ 221,   5},{ 226,   5},{ 232,   5},
}, {
    1, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 1,
    1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    1, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 1,
    1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
} };
// clang-format on
#endif
