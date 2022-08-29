/* Copyright 2019 /u/KeepItUnder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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
#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// LAYERS
enum Layer {
    _QWERTY = 0,        // Standard QWERTY layer
    _FUNCTION,          // Function key layer
    _COLOUR             // RGB key layer
};
#define _QW _QWERTY
#define _FN _FUNCTION
#define _CLR _COLOUR
/* #define _QWERTY 0       // Standard QWERTY layer */
/* #define _QW _QWERTY */
/* #define _FUNCTION 1     // Function key layer */
/* #define _FN _FUNCTION */
/* #define _COLOUR 2       // RGB key layer */
/* #define _CLR _COLOUR */

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  DK_SW1,
  DK_SW2,
  DK_SW3,
  DK_SW4,
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_all(
        //       2        3        4        5        6        7        8        9        10       11       12       13       14         15
        KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_LGUI,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGDN,
        KC_LSFT,  KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        MO(1),    KC_LALT, KC_LCTL,                            KC_SPC,                    KC_RCTL, KC_RALT, MO(1) ,  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FUNCTION] = LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,
        KC_CAPS, _______, _______, _______, _______, RGB_MOD, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_MENU, KC_PGUP,
        _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, KC_ENT,  KC_PGDN,
        _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,   _______, KC_PGUP,
        _______, _______, MO(2),                              _______,                     MO(2), _______, _______,  KC_HOME, KC_PGDN, KC_END
    ),

    [_COLOUR] = LAYOUT_all(
        KC_ESC, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MSTP,
        _______, _______, _______,                            _______,                   _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
    ),
};

int RGB_current_mode;

void matrix_init_user(void) {
    //user initialization
    /* rgblight_sethsv (147,112,219); //set rgb color to medium purple on boot */
    /* rgblight_mode(25); //mode 24 = set animation mode to individual key light per key press on boot */

    /*
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
  enum rgb_matrix_effects {
      RGB_MATRIX_SOLID_COLOR = 1,
  #ifdef RGB_MATRIX_KEYPRESSES
      RGB_MATRIX_SOLID_REACTIVE,
  #endif
      RGB_MATRIX_EFFECT_MAX
  };
  */

}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // switch (keycode) {
  // }
  return true;
}

// void matrix_init_user(void) {

// }

// void matrix_scan_user(void) {

// }

// void led_set_user(uint8_t usb_led) {

// }
