/*
Copyright 2019 Ryan Caltabiano <https://github.com/XScorpion2>

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

#include <stdint.h>
#include <stdbool.h>

#ifndef TOUCH_TERM
#    define TOUCH_TERM 500
#endif

#ifndef TOUCH_SEGMENTS
#    define TOUCH_SEGMENTS 3
#elif TOUCH_SEGMENTS < 1 || TOUCH_SEGMENTS > 5
#    error TOUCH_SEGMENTS must be between 1 and 5.
#endif

#ifndef TOUCH_DEADZONE
#    define TOUCH_DEADZONE 50
#endif

#ifndef TOUCH_RESOLUTION
#    define TOUCH_RESOLUTION 25
#endif

void touch_encoder_init(void);
void touch_encoder_update(void);

void touch_encoder_calibrate(void);
bool touch_encoder_calibrating(void);

void touch_encoder_toggle(void);
bool touch_encoder_toggled(void);

// Called when touch encoder is tapped, weak function overridable by the kb
void touch_encoder_tapped_kb(uint8_t index, uint8_t section);

// Called when touch encoder is slid, weak function overridable by the kb
void touch_encoder_update_kb(uint8_t index, bool clockwise);

// Called when touch encoder is tapped, weak function overridable by the user
void touch_encoder_tapped_user(uint8_t index, uint8_t section);

// Called when touch encoder is slid, weak function overridable by the user
void touch_encoder_update_user(uint8_t index, bool clockwise);

// For split transport only
typedef struct {
    uint8_t position;
    uint8_t taps;
} slave_touch_status_t;

void touch_encoder_get_raw(slave_touch_status_t* slave_state);
void touch_encoder_set_raw(slave_touch_status_t slave_state);
