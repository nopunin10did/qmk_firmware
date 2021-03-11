/* 
 * NoPunIn10Did Trio Keymap
 */
#include QMK_KEYBOARD_H

enum encoder_names {
  _TOP,
  _MIDDLE,
  _BOTTOM,
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
    [0] = LAYOUT(
        LGUI(KC_TAB),
        MEH(KC_F1),     // Assigned to global Zoom mute
        LSFT(KC_INS)    // Paste into bash
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) 
{
    
    if (index == _TOP) 
    {
        if (!is_alt_tab_active) 
        {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        
        alt_tab_timer = timer_read();
        
        if (!clockwise) 
        {
            tap_code16(KC_TAB);
        } 
        else 
        {
            tap_code16(S(KC_TAB));
        }
    }
}

void matrix_scan_user(void) 
{
    if (is_alt_tab_active) 
    {
        if (timer_elapsed(alt_tab_timer) > 1000) 
        {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}
