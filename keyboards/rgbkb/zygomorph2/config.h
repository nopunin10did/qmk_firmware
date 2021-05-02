/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x3535
#define PRODUCT_ID      0x3505
#define MANUFACTURER    RGBKB
#define PRODUCT         Zygomorph 2

#define USB_POLLING_INTERVAL_MS 1

/* Matrix Configuration - Rows are doubled up */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS  { A13, B10, A2, C14, A6 }
#define MATRIX_COL_PINS  { B13, B2, B1, A3, A14, A15}
#define MATRIX_IO_DELAY 5

#define SPLIT_HAND_PIN B12

/* Encoder Configuration */
#define ENCODERS_PAD_A { B8 }
#define ENCODERS_PAD_B { B9 }
#define ENCODERS_PAD_C { A13, B10}

#define TOUCH_SEGMENTS 3

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Split Keyboard Configuration */
//#define EE_HANDS
#define SPLIT_USB_DETECT
#define SPLIT_TRANSPORT_MIRROR
#define SOFT_SERIAL_PIN A9
#define SERIAL_USART_SPEED (1 * 1024 * 1024)
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PAL_MODE 7
#define SERIAL_USART_TIMEOUT 5

/* RGB LED Configuration */
#define RGB_DI_PIN B11

#define RGBLED_NUM 84
#define RGBLED_SPLIT { 42, 42 }
#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_ANIMATIONS

#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_SPLIT RGBLED_SPLIT
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS RGBLIGHT_LIMIT_VAL
#define RGB_MATRIX_CENTER { 104, 38 }
#define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_MATRIX_LED_PROCESS_LIMIT 10
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#define WS2812_PWM_DRIVER PWMD2
#define WS2812_PWM_CHANNEL 4
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 2

#define TOUCH_UPDATE_INTERVAL 33
#define OLED_UPDATE_INTERVAL 33
#define TAP_CODE_DELAY 1

#ifdef AUDIO_ENABLE
#undef AUDIO_PIN
#define AUDIO_PIN A5
#define AUDIO_PIN_ALT A4
#define AUDIO_PIN_ALT_AS_NEGATIVE
#endif


// #define DIP_SWITCH_PIN A14
