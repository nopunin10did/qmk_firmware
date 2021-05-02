#include QMK_KEYBOARD_H
#include "kageurufu.h"

extern keymap_config_t keymap_config;
extern uint8_t is_master;

/* Base Layout
  * ,------------------------------------------------.  ,------------------------------------------------.
  * |   `  |      |      |      |      |      |      |  |      |      |      |      |      |      | BkSp |
  * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
  * | Tab  |      |      |      |      |      |      |  |      |      |      |      |      |      |   \  |
  * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
  * | Esc  |      |      |      |      |      |      |  |      |      |      |      |      |      |   '  |
  * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
  * | Sft( |      |      |      |      |      |      |  |      |      |      |      |      |      | Sft) |
  * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
  * | Ctrl |  Win |  Win |  Alt |  FN  | Space|  RGB |  |  FN  |  FN  |   -  |   =  | Down | PgUp | PgDn |
  * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
  *                                    | Space| Bksp |  | Enter| Space|
  *                                    `-------------'  `--------=----'
  */
#define EXPAND_LAYOUT(...) LAYOUT(__VA_ARGS__)
#define _BASE_LAYOUT( \
  _00, _01, _02, _03, _04,  _05, _06, _07, _08, _09, \
  _10, _11, _12, _13, _14,  _15, _16, _17, _18, _19, \
  _20, _21, _22, _23, _24,  _25, _26, _27, _28, _29 \
) \
EXPAND_LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   RGB_MOD,                   KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
      KC_TAB,  _00,     _01,     _02,     _03,     _04,    KC_LBRC,                   KC_RBRC, _05,     _06,     _07,     _08,     _09,     KC_BSLS, \
      FN_ESC,  _10,     _11,     _12,     _13,     _14,    RGB_SAI,                   RGB_VAI, _15,     _16,     _17,     _18,     _19,     KC_QUOT, \
      KC_LSPO, _20,     _21,     _22,     _23,     _24,    RGB_SAD,                   RGB_VAD, _25,     _26,     _27,     _28,     _29,     KC_RSPC, \
      KC_LCTL, KC_LGUI, KC_LGUI, KC_LALT, FN,      KC_SPC, KC_MUTE, KC_BSPC, KC_ENT,  FN,      KC_SPC,  KC_MINS, KC_EQL,  KC_DOWN, KC_PGUP, KC_PGDN  \
)
#define BASE_LAYOUT(...) _BASE_LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = BASE_LAYOUT( \
      _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, \
      _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, \
      _________________QWERTY_L3_________________, _________________QWERTY_R3_________________ \
  ),

  [_FN] = EXPAND_LAYOUT( \
      ________________FUNCTION_L1________________, _______,                   KC_PSCR, ________________FUNCTION_R1________________, \
      ________________FUNCTION_L2________________, _______,                   _______, ________________FUNCTION_R2________________, \
      ________________FUNCTION_L3________________, _______,                   _______, ________________FUNCTION_R3________________, \
      ________________FUNCTION_L4________________, _______,                   _______, ________________FUNCTION_R4________________, \
      ________________FUNCTION_L5________________, ADJ,     KC_DEL,  _______, ADJ,     ________________FUNCTION_R5________________  \
      ),

  [_ADJ] = EXPAND_LAYOUT( \
      _________________ADJUST_L1_________________, _______,                   _______, _________________ADJUST_R1_________________, \
      _________________ADJUST_L2_________________, _______,                   _______, _________________ADJUST_R2_________________, \
      _________________ADJUST_L3_________________, _______,                   _______, _________________ADJUST_R3_________________, \
      _________________ADJUST_L4_________________, _______,                   _______, _________________ADJUST_R4_________________, \
      _________________ADJUST_L5_________________, _______, _______, _______, _______, _________________ADJUST_R5_________________  \

      )
};


// Default configuration: 3 tap zones, slide up, slide down
const uint16_t PROGMEM touch_encoders[][NUMBER_OF_TOUCH_ENCODERS][TOUCH_ENCODER_OPTIONS]  = {
    [_QWERTY] = TOUCH_ENCODER_LAYOUT( \
        RGB_RMOD, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,
        RGB_RMOD, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD
    ),
    [_FN] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [_ADJ] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    )
};

const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS][ENCODER_OPTIONS]  = {
    [_QWERTY] = ENCODER_LAYOUT( \
        KC_VOLD, KC_VOLU,
        _______, _______,
        _______, _______,
        KC_LEFT, KC_RIGHT,
        _______, _______,
        _______, _______,
        KC_VOLD, KC_VOLU,
        _______, _______,
        _______, _______,
        KC_LEFT, KC_RIGHT,
        _______, _______,
        _______, _______
    ),
    [_FN] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        RGB_HUD, RGB_HUI,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [_ADJ] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        RGB_VAD, RGB_VAI,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    )
};


// For RGBRST Keycode
#if defined(RGB_MATRIX_ENABLE)
void rgb_matrix_increase_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}

void rgb_matrix_decrease_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  static uint16_t reset_timer;
  switch (keycode) {
    case RGBRST:
#if defined(RGBLIGHT_ENABLE)
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
#elif defined(RGB_MATRIX_ENABLE)
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
        }
#endif
      return false;
    case RESET:
      if (record->event.pressed) {
          reset_timer = timer_read();
      } else {
          if (timer_elapsed(reset_timer) >= 500) {
              reset_keyboard();
          }
      }
      return false;
#if defined(RGB_MATRIX_ENABLE) && !defined(KEYBOARD_rgbkb_sol_rev1)
    case RGB_TOG:
      if (record->event.pressed) {
        rgb_matrix_increase_flags();
      }
      return false;
#endif
  }
  return true;
}
