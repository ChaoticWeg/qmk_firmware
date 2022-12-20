#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    _BASE,  // default layer
    _NMBR,  // numpad
    _MOUS,  // mouse/arrows
    _CODE,  // code symbols
    _MDIA,  // media layer
    _SYMB,  // symbols
    _SWIN,  // shift-win-arrows
    _CWIN   // ctrl-win-arrows
};

#ifndef _______
#define _______ KC_TRNS
#endif

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,    KC_1,      KC_2,    KC_3,      KC_4,    KC_5,    KC_F11,     KC_F12,     KC_6,      KC_7,      KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,    KC_Q,      KC_W,    KC_E,      KC_R,    KC_T,    C(KC_LGUI), KC_NO,      KC_Y,      KC_U,      KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_CAPS,   KC_A,      KC_S,    KC_D,      KC_F,    KC_G,                                       KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,   KC_Z,      KC_X,    KC_C,      KC_V,    KC_B,    S(KC_LGUI), KC_NO,      KC_N,      KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  C(KC_NO), C(KC_NO),   KC_NO,   A(KC_NO),  KC_LGUI,                                                        KC_MINS, KC_EQL,  KC_QUOT, KC_LBRC, KC_RBRC,
                                                               MO(_NMBR), MO(_MOUS),  MO(_CODE), MO(_MDIA),
                                                                          KC_SYRQ,    KC_NO,
                                                       KC_SPC, MO(_SYMB), KC_LBRC,    KC_RBRC,   MO(_CODE), KC_ENT
),

[_NMBR] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_HOME, KC_PGUP, _______, _______,     _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, KC_END,  KC_PGDN, _______,                       _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                        C(KC_NO), _______, _______, _______, _______,
                                                 KC_NO, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),

[_MOUS] = LAYOUT_ergodox_pretty(
  // left hand
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                               _______,   KC_NO,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),

[_CODE] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_LPRN, KC_RPRN, _______, _______, _______, KC_SYRQ,     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_GRV,                        _______, KC_QUOT, KC_MINS, KC_EQL,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                               _______, _______,     KC_NO,   _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),

[_MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                               _______, _______,     _______, KC_NO,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),

[_SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______,   _______,   _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,   _______,   _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, MO(_SWIN), MO(_CWIN), _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,   _______,   _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,   _______,                                         _______, _______, _______, _______, _______,

                                                   _______, _______,     _______, _______,
                                                            _______,     _______,
                                        _______,   KC_NO,   _______,     _______, _______, _______
),

[_SWIN] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,      _______, _______,      _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,      _______, _______,      _______, _______,
  _______, _______, _______, KC_NO,   _______, _______,                       _______, LSG(KC_LEFT), _______, LSG(KC_RGHT), _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,      _______, _______,      _______, _______,
  _______, _______, _______, _______, _______,                                         _______,      _______, _______,      _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, KC_NO,   _______,     _______, _______, _______
),

[_CWIN] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,       _______, _______,       _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,       _______, _______,       _______, _______,
  _______, _______, _______, _______, KC_NO,   _______,                       _______, C(G(KC_LEFT)), _______, C(G(KC_RGHT)), _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,       _______, _______,       _______, _______,
  _______, _______, _______, _______, _______,                                         _______,       _______, _______,       _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, KC_NO,   _______,     _______, _______, _______
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
