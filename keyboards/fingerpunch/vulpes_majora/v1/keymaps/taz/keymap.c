#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _ALPHAS,
    _NAV,
    _NUM,
    _SYMBOLS,
    _ADJUST
};

#define LAYOUT LAYOUT_vulpes_majora
#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)
#define LAYOUT_vulpes_majora_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K31, K32, K33, K34, K35, K36 \
  ) \
  LAYOUT_wrapper( \
        KC_MS_BTN3,   K01,    K02,    K03,    K04,    K05,                                         K06,    K07,    K08,    K09,    K0A,    FP_ZOOM_TOG,    \
        KC_MS_BTN1,   K11,    K12,    K13,    K14,    K15,                                         K16,    K17,    K18,    K19,    K1A,    FP_SCROLL_TOG,  \
        KC_MS_BTN2,   K21,    K22,    K23,    K24,    K25,                                         K26,    K27,    K28,    K29,    K2A,    FP_SNIPE_TOG,   \
                                      K31,    K32,    K33,   KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2,   K34,    K35,    K36,                                 \
               KC_VOLU,                  KC_MS_BTN3,  KC_MS_BTN1,  KC_MS_BTN2,         KC_VOLD,  KC_MUTE,  KC_VOLU,                  KC_VOLU,               \
      KC_MPRV, KC_MPLY, KC_MNXT,                                                                                            KC_MPRV, KC_MPLY, KC_MNXT,      \
               KC_VOLD,                                                                                                              KC_VOLD                \
    )


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ALPHAS
 *
 * ,----------------------------------.             ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'             `----------------------------------'
 *               ,--------------------.             ,--------------------.
 *               | Del | BckSpc | Tab |             | Enter| Space | Esc |
 *               `--------------------'             `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_ALPHAS] = LAYOUT_vulpes_majora_base(
  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,              KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
  LSFT_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LGUI_T(KC_F), KC_G,              KC_H,    RGUI_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RSFT_T(KC_QUOT),
  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,              KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                              KC_DEL,  LT(2, KC_BSPC), LT(3, KC_TAB),        KC_ENT,  LT(1, KC_SPC),   KC_ESC
),

/* Navigation
 * TODO: Cut, Copy and Paste
 * ,----------------------------------.             ,----------------------------------.
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * | LSft | LAlt | LCtl | RGui |      |             | Left |  Up  | Down |Right |      |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |      |  Cut | Copy |Paste |      |             |  End | PgDn | PgUp | Home |      |
 * `----------------------------------'             `----------------------------------'
 *               ,--------------------.             ,--------------------.
 *               | Del | BckSpc | Tab |             | Enter| Space | Esc |
 *               `--------------------'             `--------------------.
 */

[_NAV] = LAYOUT_vulpes_majora_base(
  _______, _______, _______, _______, _______,      _______, _______, _______, _______,  _______,
  KC_LSFT, KC_LALT, KC_LCTL, KC_RGUI, _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  _______,
  _______, _______, _______, _______, _______,      KC_END,  KC_PGDN, KC_PGUP, KC_HOME,  _______,
                    _______, _______, _______,      _______, _______, _______
),


/* Numbers
 *
 * ,----------------------------------.             ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * | LSft | LAlt | LCtl | RGui |      |             |   -  |   =  |      |      |      |
 * |------+------+------+------+------|             |------+------+------+------+------|
 * |      |      |      |      |      |             |   :  |   +  |      |      |      |
 * `----------------------------------'             `----------------------------------'
 *               ,--------------------.             ,--------------------.
 *               | Del | BckSpc | Tab |             | Enter| Space | Esc |
 *               `--------------------'             `--------------------.
 */

[_NUM] = LAYOUT_vulpes_majora_base(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
  KC_LSFT, KC_LALT, KC_LCTL, KC_RGUI, _______,      KC_MINS, KC_EQL, _______, _______,  _______,
  _______, _______, _______, _______, _______,      KC_COLN, KC_PLUS, _______, _______,  _______,
                    _______, _______, _______,      _______, _______, _______
),

/* Symbols
 *
 * ,----------------------------------.             ,-----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )   |
 * |------+------+------+------+------|             |------+------+------+------+-------|
 * |      |      |      |      |      |             |   -  |   =  |   [  |   ]  |   ;   |
 * |------+------+------+------+------|             |------+------+------+------+-------|
 * |  Caps|      |      |      |      |             |   :  |   +  |   {  |   }  |   "   |
 * `----------------------------------'             `-----------------------------------'
 *               ,--------------------.             ,--------------------.
 *               | RST | BckSpc | Tab |             | Enter| Space |  `  |
 *               `--------------------'             `--------------------.
 */

[_SYMBOLS] = LAYOUT_vulpes_majora_base(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_LSFT, KC_LALT, KC_LCTL, KC_RGUI, _______,      KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_SCLN,
  KC_CAPS, _______, _______, _______, _______,      KC_COLN, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                    QK_BOOT, _______, _______,      _______, _______, KC_GRV
),

/* Adjust (Lower + Raise)

 * ,----------------------------------.             ,----------------------------------.
 * | RGB_T| RGB_R| RGB_F|      |QWERTY|             |   F1 |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------|             |------+------+------+------+------+
 * | SPD_I| HUE_I| SAT_I| VAL_I|COLEMK|             |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|             |------+------+------+------+------+
 * | SPD_D| HUE_D| SAT_D| VAL_D|      |             |  F11 |  F12 |      |      |  RST |
 * `----------------------------------'             `----------------------------------'
 *               ,--------------------.             ,--------------------.
 *               | Del | BckSpc | Tab |             | Enter| Space | Esc |
 *               `--------------------'             `--------------------.
 */

[_ADJUST] =  LAYOUT_vulpes_majora_base(
  RGB_TOG, RGB_RMOD, RGB_MOD, _______, _______,     KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,
  RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, _______,     KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
  RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,     KC_F11,  KC_F12,  _______, _______,  QK_BOOT,
                     _______, _______, _______,     _______, _______, _______
)
};
