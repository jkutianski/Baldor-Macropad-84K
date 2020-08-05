/* Copyright 2020 Juan Pablo Kutianski
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "encoder_action.h"

static keyevent_t encoder_event[ENCODERS];
static keypos_t encoder_cw[ENCODERS] = ENCODERS_CW_KEY;
static keypos_t encoder_ccw[ENCODERS] = ENCODERS_CCW_KEY;


void encoder_action_unregister(void) {
    int index;
    for (index = 0; index < ENCODERS; ++index) {
        if (IS_PRESSED(encoder_event[index])) {
            encoder_event[index].pressed = false;
            encoder_event[index].time = (timer_read() | 1);
            action_exec(encoder_event[index]);
        }
    }
}

void encoder_action_register(uint8_t index, bool clockwise) {
    encoder_event[index] = (keyevent_t) {
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    action_exec(encoder_event[index]);
}
