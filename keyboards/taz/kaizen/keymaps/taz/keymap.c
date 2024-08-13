#include QMK_KEYBOARD_H
#include "kaizen.h"
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 *        ,----------------------------------.             ,----------------------------------.
 *        |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |
 *        |------+------+------+------+------|             |------+------+------+------+------|
 *        |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |
 *        |------+------+------+------+------|             |------+------+------+------+------|
 *        |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |
 *        `----------------------------------'             `----------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Bkspc| Tab  |    | Enter| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT(
    KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
    LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN),
    KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                              KC_BSLS,        KC_BSPC,      KC_TAB,        KC_ENT,   KC_SPC,       KC_DEL,
                _______,                                                                                    _______,
        _______,_______,_______,                                                                    _______,_______,_______,
                _______,                                                                                    _______
),
};
