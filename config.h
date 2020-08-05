#pragma once

#include "config_common.h"

// USB Device descriptor parameter
#define VENDOR_ID       0x1209
#define PRODUCT_ID      0x0BAB
#define DEVICE_VER      0x0001
#define MANUFACTURER    Baldor
#define PRODUCT         Baldor MacroPAD 84K
#define DESCRIPTION     Macro PAD Keyboard

// Add teensy core
#define CORE_TEENSY

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS \
    { A0, A1, A2, A3, A4, A5, A6, A7, F0, NO_PIN }
#define MATRIX_COL_PINS \
    { E0, E1, C0, C1, C2, C3, C4, C5, C6, C7, F7, F6 }
// LED PINS are B7, D6, D7
#define UNUSED_PINS \
    { B2, B1, B0, D0, D1, D3, D4, E7, E6, E5, E4, F1 }

#define ENCODERS 1

#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { B5 }

#define ENCODERS_CW_KEY  { { 0, 9 } }
#define ENCODERS_CCW_KEY { { 1, 9 } }

#define ENCODER_RESOLUTION 4

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// Set 0 if debouncing isn't needed
#define DEBOUNCE 5

// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
// #define LOCKING_SUPPORT_ENABLE
// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE

// Disable RGB Backlight
#define RGB_BACKLIGHT_ENABLED 0

// Define layers count
#ifndef DYNAMIC_KEYMAP_LAYER_COUNT
#    define DYNAMIC_KEYMAP_LAYER_COUNT 8
#endif

// Define keymap macro count
#ifndef DYNAMIC_KEYMAP_MACRO_COUNT
#    define DYNAMIC_KEYMAP_MACRO_COUNT 16
#endif

// This is the default EEPROM max address to use for dynamic keymaps.
// The default is the Teensy 2.0++ EEPROM max address.
// Explicitly override it if the keyboard uses a microcontroller with
// more or less EEPROM.
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 4095

// Define bootmagic on ESC
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

// Leds at start bootmagic
#define BOOTMAGIC_LEDSEQ_COUNT 3
#define BOOTMAGIC_LEDSEQ_STEP 200

// Layer led blink time
#define LAYER_BLINK_TIME 200

/* For production disable debug and print */
#ifndef DEVELOPMENT
#    define NO_DEBUG
#    define NO_PRINT
#endif

// AUDIO
#ifdef AUDIO_ENABLE
#   define B6_AUDIO
#   define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

/*
 * MIDI options
 */
#ifdef MIDI_ENABLE
/* Prevent use of disabled MIDI features in the keymap */
# define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/
#   define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
#   define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
#define MIDI_TONE_KEYCODE_OCTAVES 5
#endif
