#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _ALPHAS, // 0
    _NAV,   // 1
    _NUM,   // 2
    _SYM,   // 3
    _MEDIA, // 4
    _MOUSE, // 5
    _FN,    // 6
    _SYS    // 7
};

enum combos {
    QW_ESC
};

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);    // always required before the auto mouse feature will work
}

#define HRM_A LSFT_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LCTL_T(KC_D)
#define HRM_F LGUI_T(KC_F)
#define HRM_J RGUI_T(KC_J)
#define HRM_K RCTL_T(KC_K)
#define HRM_L RALT_T(KC_L)
#define HRM_QUOT RSFT_T(KC_QUOT)

#define SPACE_NAV       LT(1, KC_SPACE)
#define BSPC_NUM        LT(2, KC_BSPC)
#define TAB_SYM         LT(3, KC_TAB)
#define SPACE_MEDIA     LT(4, KC_SPACE)
#define BSPC_MEDIA      LT(4, KC_BSPC)
#define ENTER_FN        LT(6, KC_ENT)
#define DEL_SYS         LT(7, KC_DEL)

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE
};

bool set_scrolling = false;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 100.0
#define SCROLL_DIVISOR_V 100.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            // Toggle set_scrolling when DRAG_SCROLL key is pressed or released
            set_scrolling = record->event.pressed;
            break;
        default:
            break;
    }
    return true;
}

// Function to handle layer changes and disable drag scrolling when not in AUTO_MOUSE_DEFAULT_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    if (get_highest_layer(state) != AUTO_MOUSE_DEFAULT_LAYER) {
        set_scrolling = false;
    }
    return state;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHAS] = LAYOUT_right_ball(
        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                               KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        HRM_A,      HRM_S,      HRM_D,      HRM_F,      KC_G,                               KC_H,       HRM_J,      HRM_K,      HRM_L,      HRM_QUOT,
        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                               KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,
        KC_LCTL,    KC_LGUI,    KC_LALT,    DEL_SYS,    BSPC_NUM,   TAB_SYM,    ENTER_FN,   SPACE_NAV,                                      KC_ESC
    ),

    [_NAV] = LAYOUT_right_ball(
        _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,
        HRM_A,      HRM_S,      HRM_D,      HRM_F,      KC_G,                               KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,
        _______,    _______,    _______,    _______,    _______,                            KC_END,     KC_PGDN,    KC_PGUP,    KC_HOME,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    SPACE_MEDIA,                                    _______
    ),

    [_NUM] = LAYOUT_right_ball(
        KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
        KC_LSFT,    KC_LALT,    KC_LCTL,    KC_RGUI,    _______,                            KC_MINS,    KC_EQL,     _______,    _______,    KC_SCLN,
        _______,    _______,    _______,    _______,    _______,                            KC_COLN,    KC_PLUS,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    BSPC_MEDIA, _______,    _______,    _______,                                        _______
    ),

    [_SYM] = LAYOUT_right_ball(
        KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                            KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,
        KC_LSFT,    KC_LALT,    KC_LCTL,    KC_RGUI,    _______,                            KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_SCLN,
        _______,    _______,    _______,    _______,    _______,                            KC_COLN,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_BSLS,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                                        _______
    ),

    [_MEDIA] = LAYOUT_right_ball(
        _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    KC_MPRV,
        _______,    KC_PSCR,    KC_BRIU,    KC_BRID,    _______,                            KC_MPLY,    KC_VOLD,    KC_VOLU,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,                            KC_MNXT,    KC_MUTE,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                                        _______
    ),

    [_MOUSE] = LAYOUT_right_ball(
        _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,
        _______,    _______,    DRAG_SCROLL,KC_RGUI,    _______,                            _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, _______,    _______,                                        _______
    ),

    [_FN] = LAYOUT_right_ball(
        KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,
        _______,    _______,    _______,    _______,    _______,                            KC_F12,     KC_F11,     _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                                        _______
    ),

    [_SYS] = LAYOUT_right_ball(
        _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    QK_BOOT,    QK_REBOOT,  _______,                                        _______
    ),
};

const uint16_t PROGMEM qw_esc_combo[] = {KC_Q, KC_W, COMBO_END};
combo_t key_combos[] = {
    [QW_ESC] = COMBO(qw_esc_combo, KC_ESC),
};
