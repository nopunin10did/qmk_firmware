#include QMK_KEYBOARD_H

enum keymap_layers {
    _QWERTY,
    _FN,
    _ADJUST
};

enum keymap_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE
};

// Default Layers
#define QWERTY   DF(_QWERTY)

// Momentary Layers
#define FN       MO(_FN)
#define ADJUST   MO(_ADJUST)

#define LSADEL   LSA_T(KC_DEL)
#define ALGRHOM  RALT_T(KC_HOME)
#define ALGREND  RALT_T(KC_END)
#define RCBS     RCTL_T(KC_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      |   `    |  | 6      | 7      | 8      | 9      | 0      | -      | Bckspc |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Tab    | Q      | W      | E      | R      | T      | \|     |  | Y      | U      | I      | O      | P      | [      | ]
     * |--------+--------+--------+--------+--------+--------+--------|  +--------+--------+--------+--------+--------+--------|
     * | Ctrl   | A      | S      | D      | F      | G      | =+     |  | H      | J      | K      | L      | :      | '      | Enter
     * |--------+--------+--------+--------+--------+--------+--------|  +--------+--------+--------+--------+--------+--------|
     * | Shift  | Z      | X      | C      | V      | B      | ASDel  |  | N      | M      | ,      | .      | /      | Shift  | Shift
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Ctrl   | Win    | Alt    | RGBTOG | FN     | Space  | Space  |  | AlGrHo | End    | Left   | Right  | Down   | Up     | Ctrl   |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     */
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV ,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSLS,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_EQL,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LSADEL,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, ADJUST,  FN,      KC_SPC,  KC_SPC,    ALGRHOM, ALGREND, KC_LEFT, KC_RIGHT,KC_DOWN , KC_UP,    RCBS
    ),

    [_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, RESET,   _______, KC_NUBS, _______, _______, KC_INS , _______, KC_PSCR, _______, _______,
        KC_CAPS, _______, _______, _______, _______, _______, KC_F12 , _______, _______, _______, KC_SLCK, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_PAUS, KC_CALC, _______, _______, _______, _______, _______, KC_RO  , _______,
        _______, _______, _______, RGB_TOG, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, RESET,   _______, _______, _______, _______, _______, _______, _______,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,
        _______, RGB_SPD, RGB_MOD, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,
        _______, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

// Default configuration: 3 tap zones, slide up, slide down
const uint16_t PROGMEM touch_encoders[][NUMBER_OF_TOUCH_ENCODERS][TOUCH_ENCODER_OPTIONS]  = {
    [_QWERTY] = TOUCH_ENCODER_LAYOUT( \
        KC_MNXT, KC_MPLY, KC_MPRV, KC_VOLU, KC_VOLD,
        KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP
        //RGB_RMOD, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,
        //RGB_RMOD, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD
    ),
    [_FN] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [_ADJUST] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    )
};

const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS][ENCODER_OPTIONS]  = {
    [_QWERTY] = ENCODER_LAYOUT( \
        KC_VOLU, KC_VOLD,
        KC_VOLU, KC_VOLD,
        KC_PGDN, KC_PGUP,
        KC_PGDN, KC_PGUP
    ),
    [_FN] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [_ADJUST] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TCH_TOG:
            touch_encoder_toggle();
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

#if defined(OLED_DRIVER_ENABLE)
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("FN"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
