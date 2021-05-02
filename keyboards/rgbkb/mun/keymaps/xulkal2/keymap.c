#include QMK_KEYBOARD_H

enum keymap_layers {
    _QWERTY,
    _FUNCTION,
    _ADJUST
};

enum keymap_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

// Default Layers
#define QWERTY   DF(_QWERTY)

// Momentary Layers
#define FN       OSL(_FUNCTION)
#define ADJ      OSL(_ADJUST)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * | `~/ESC | 1      | 2      | 3      | 4      | 5      |        |  |        | 6      | 7      | 8      | 9      | 0      | Bckspc |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Tab    | Q      | W      | E      | R      | T      |        |  |        | Y      | U      | I      | O      | P      | \      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Caps   | A      | S      | D      | F      | G      | Play   |  | MN BTN | H      | J      | K      | L      | :      | Enter  |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Shft[  | Z      | X      | C      | V      | B      | {      |  | }      | N      | M      | ,      | .      | /      | Shft]  |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Ctrl-  | Win    | Alt    | Del    | Space  |        | ADJ    |  | FN     |        | Space  | '"     | Alt    | App    | Ctrl=  |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     */
    [_QWERTY] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,      KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,      KC_NO,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MPLY,    KC_MPLY, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, //MENU_BTN
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR,    KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
        KC_LCPO, KC_LGUI, KC_LALT, KC_DEL,  KC_SPC,  KC_NO,   ADJ,        FN,      KC_NO,   KC_SPC,  KC_QUOTE,KC_RALT, KC_APP,  KC_RCPC
    ),

    /* Function
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * | F12    | F1     | F2     | F3     | F4     | F5     |        |  |        | F6     | F7     | F8     | F9     | F10    | F11    |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | SPDI   | SAI    | VAI    | HUI    | RGBMD  |        |  |        |        |        | PrtScr | ScrLck | PseBrk |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | SPDD   | SAD    | VAD    | HUD    | RGBRMD |        |  |        |        |        | Ins    | Home   | PgUp   |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | RGBRST |        |        |        | RGBTOG |        |  |        |        |        | Del    | End    | PgDn   |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |  |        |        | Play   | Next   | VolUp  | VolDn  | Mute   |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     */
    [_FUNCTION] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, RGB_SPI, RGB_SAI, RGB_VAI, RGB_HUI, RGB_MOD, _______,    _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,
        _______, RGB_SPD, RGB_SAD, RGB_VAD, RGB_HUD, RGB_RMOD,_______,    _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______,
        _______, RGB_RST, _______, _______, _______, RGB_TOG, _______,    _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_MPLY, KC_MNXT, KC_VOLU, KC_VOLD, KC_MUTE
    ),

    /* Adjust
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * |        |        |        |        |        |        |        |  |        |        | NumLck | /      | *      | -      | Del    |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        |        | Up     |        | Reset  | T_TOG  |        |  |        |        | 7      | 8      | 9      | +      |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        | Left   | Down   | Right  |        |        |        |  |        |        | 4      | 5      | 6      | +      |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        | EepRst |        |  |        |        | 1      | 2      | 3      | Enter  |        |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |  |        |        |        | 0      | .      | Enter  |        |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     */
    [_ADJUST] = LAYOUT(
        KC_GRAVE, _______, _______, _______, _______, _______, _______,    _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_DEL,
        _______, _______, KC_UP,   _______, RESET,   TCH_TOG, _______,    _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______, _______,    _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______,
        _______, _______, _______, _______, _______, EEP_RST, _______,    _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_KP_0, KC_PDOT, KC_PENT, _______
    )
};

// Default configuration: 3 tap zones, slide up, slide down
const uint16_t PROGMEM touch_encoders[][NUMBER_OF_TOUCH_ENCODERS][TOUCH_ENCODER_OPTIONS]  = {
    [_QWERTY] = TOUCH_ENCODER_LAYOUT( \
        KC_MNXT, KC_MPLY, KC_MPRV, KC_VOLU, KC_VOLD,
        RGB_RMOD, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI
    ),
    [_FUNCTION] = TOUCH_ENCODER_LAYOUT( \
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
        KC_VOLD, KC_VOLU,
        KC_VOLD, KC_VOLU,
        KC_PGDN, KC_PGUP,
        KC_PGDN, KC_PGUP
        //MENU_DN, MENU_UP,
        //MENU_DN, MENU_UP
    ),
    [_FUNCTION] = ENCODER_LAYOUT( \
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

#define RGB_FUNCTION_COUNT 5
typedef void (*rgb_matrix_f)(void);
const rgb_matrix_f rgb_matrix_functions[RGB_FUNCTION_COUNT][2] = {
    { rgb_matrix_increase_hue,      rgb_matrix_decrease_hue     },
    { rgb_matrix_increase_sat,      rgb_matrix_decrease_sat     },
    { rgb_matrix_increase_val,      rgb_matrix_decrease_val     },
    { rgb_matrix_increase_speed,    rgb_matrix_decrease_speed   },
    { rgb_matrix_step,              rgb_matrix_step_reverse     }
};
// clang-format on

typedef struct {
    bool selecting;
    uint8_t selection;
} kb_menu_status_t;

static kb_menu_status_t rgb_menu = { false, 4 };

static void rgb_menu_action(bool clockwise) {
    if (rgb_menu.selecting)  {
        if (clockwise) {
            rgb_menu.selection = (rgb_menu.selection - 1);
            if (rgb_menu.selection >= RGB_FUNCTION_COUNT)
                rgb_menu.selection = RGB_FUNCTION_COUNT - 1;
        }
        else {
            rgb_menu.selection = (rgb_menu.selection + 1) % RGB_FUNCTION_COUNT;
        }
    }
    else {
        (*rgb_matrix_functions[rgb_menu.selection][clockwise])();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case MENU_BTN:
            if (record->event.pressed) {
                rgb_menu.selecting = !rgb_menu.selecting;
            }
            return false;
        case MENU_UP:
            if (record->event.pressed) {
                rgb_menu_action(true);
            }
            return false;
        case MENU_DN:
            if (record->event.pressed) {
                rgb_menu_action(false);
            }
            return false;
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;
    }
}

/*static void render_logo(void) {
    static const char PROGMEM font_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    oled_write_P(font_logo, false);
}*/

static void render_icon(void) {
    static const char PROGMEM font_icon[] = {
        0x9b,0x9c,0x9d,0x9e,0x9f,
        0xbb,0xbc,0xbd,0xbe,0xbf,
        0xdb,0xdc,0xdd,0xde,0xdf,0
    };
    oled_write_P(font_icon, false);
}

static void render_rgb_menu(void) {
    static char buffer[53] = {0};
    snprintf(buffer, sizeof(buffer), " Hue  %3d  Sat  %3d  Val  %3d  Spd  %3d  Mod  %3d ", 
    rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode);

    if (rgb_menu.selecting) {
        buffer[rgb_menu.selection * 10] = '*';
        buffer[4 + rgb_menu.selection * 10] = '*';
    }
    else {
        buffer[rgb_menu.selection * 10] = '>';
        buffer[4 + rgb_menu.selection * 10] = '<';
    }
    oled_write(buffer, false);
}

static void render_layer(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("BASE "), false);
            break;
        case _FUNCTION:
            oled_write_ln_P(PSTR("FUNC "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJS "), false);
            break;
    }
}

static void render_leds(void)
{
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUMLK")     : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPLK")    : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRLK")  : PSTR("     "), false);
}

static void render_touch(void)
{
    // Host Touch LED Status
    oled_write_P(!touch_encoder_toggled() ? PSTR("TOUCH")  : PSTR("     "), false);
    oled_write_P(touch_encoder_calibrating() ? PSTR("CLBRT")  : PSTR("     "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer();
        oled_write_P(PSTR("     "), false);
        render_leds();
        oled_write_P(PSTR("     "), false);
        render_touch();
        oled_set_cursor(0, 12);
        render_icon();
    }
    else {
        render_rgb_menu();
        oled_set_cursor(0, 12);
        render_icon();
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}