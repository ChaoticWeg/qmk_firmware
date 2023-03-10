#include QMK_KEYBOARD_H

#include "version.h"
#include "colors.h"

typedef struct
{
    uint8_t r, g, b;
}
rgb_t;

static rgb_t LAYER_COLORS[] = {
    [0] = { RGB_LAYER_0 },
    [1] = { RGB_LAYER_1 },
    [2] = { RGB_LAYER_2 },
    [3] = { RGB_LAYER_3 },
    [4] = { RGB_LAYER_4 },
    [5] = { RGB_LAYER_5 },
    [6] = { RGB_LAYER_6 },
    [7] = { RGB_LAYER_7 }
};

static rgb_t CAPS_LOCK_COLOR = { RGB_RED };

static void get_layer_color(uint8_t layer, bool caps_lock, rgb_t *dest)
{
    rgb_t *src = caps_lock ? &CAPS_LOCK_COLOR : &LAYER_COLORS[layer];
    memset(dest, 0, sizeof(rgb_t));
    memcpy(dest, src, sizeof(rgb_t));
}

enum layers {
    _BASE,  // default layer
    _NMBR,  // numpad
    _MOUS,  // mouse/arrows
    _CODE,  // code symbols
    _MDIA,  // media layer
    _SYMB,  // symbols
    _SWIN,  // shift-win-arrows
    _CWIN,  // ctrl-win-arrows
};

#ifndef _______
#   define _______ KC_TRNS
#endif

#ifndef XXXXXXX
#   define XXXXXXX KC_NO
#endif

#ifndef CG
#   define CG(...) C(G(__VA_ARGS__))
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
  KC_ESC,          KC_1,      KC_2,    KC_3,      KC_4,    KC_5,    KC_F11,     KC_F12,     KC_6,      KC_7,      KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,          KC_Q,      KC_W,    KC_E,      KC_R,    KC_T,    C(KC_LGUI), KC_NO,      KC_Y,      KC_U,      KC_I,    KC_O,    KC_P,    KC_BSLS,
  LSFT_T(KC_CAPS), LCTL_T(KC_A),      LSFT_T(KC_S),    LGUI_T(KC_D),      LALT_T(KC_F),    KC_G,                                       KC_H,      RALT_T(KC_J),    RGUI_T(KC_K),    RSFT_T(KC_L),    RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,         KC_Z,      KC_X,    KC_C,      KC_V,    KC_B,    S(KC_LGUI), KC_NO,      KC_N,      KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  C(KC_NO),        C(KC_NO),  KC_NO,   A(KC_NO),  KC_LGUI,                                                        KC_MINS, KC_EQL,  KC_QUOT, KC_LBRC, KC_RBRC,
                                                               MO(_NMBR), MO(_MOUS),  MO(_CODE), MO(_MDIA),
                                                                          KC_PSCR,    KC_NO,
                                                       KC_SPC, MO(_SYMB), KC_LBRC,    KC_RBRC,   MO(_CODE), KC_ENT
),

[_NMBR] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, KC_HOME, KC_PGUP, _______, _______,     _______, _______, _______, KC_PGUP, _______, _______, _______,
  _______, _______, _______, KC_END,  KC_PGDN, _______,                       _______, KC_HOME, KC_PGDN, KC_END,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                        C(KC_NO), _______, _______, _______, _______,
                                               XXXXXXX, _______,     _______, _______,
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

                                               _______, XXXXXXX,     _______, _______,
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

                                               _______, _______,     XXXXXXX, _______,
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

                                               _______, _______,     _______, XXXXXXX,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),

[_SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______,   _______,   _______, _______,     _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, _______,   _______,   _______, _______,     _______, _______, _______, KC_PGUP, _______, _______, _______,
  _______, _______, _______, MO(_SWIN), MO(_CWIN), _______,                       _______, KC_HOME, KC_PGDN, KC_END,  _______, _______,
  _______, _______, _______, _______,   _______,   _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,   _______,                                           _______, _______, _______, _______, _______,

                                                    _______, _______,     _______, _______,
                                                             _______,     _______,
                                         _______,   XXXXXXX, _______,     _______, _______, _______
),

[_SWIN] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,      _______, _______,      _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,      _______, _______,      _______, _______,
  _______, _______, _______, XXXXXXX, _______, _______,                       _______, LSG(KC_LEFT), _______, LSG(KC_RGHT), _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,      _______, _______,      _______, _______,
  _______, _______, _______, _______, _______,                                         _______,      _______, _______,      _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, XXXXXXX, _______,     _______, _______, _______
),

[_CWIN] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,       _______, _______,       _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,       _______, _______,       _______, _______,
  _______, _______, _______, _______, XXXXXXX, _______,                       _______, CG(KC_LEFT),   _______, CG(KC_RGHT),   _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______,       _______, _______,       _______, _______,
  _______, _______, _______, _______, _______,                                         _______,       _______, _______,       _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, XXXXXXX, _______,     _______, _______, _______
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void)
{

}

// Layer indication
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    uint8_t layer = get_highest_layer(layer_state);
    bool caps_lock = host_keyboard_led_state().caps_lock;

    rgb_t layer_color;
    get_layer_color(layer, caps_lock, &layer_color);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row)
    {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col)
        {
            uint8_t index = g_led_config.matrix_co[row][col];

            // Skip if index out of range or index has no LED
            if (index < led_min || index >= led_max || index == NO_LED)
            {
                continue;
            }

            if (keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS)
            {
                rgb_matrix_set_color(index, layer_color.r, layer_color.g, layer_color.b);
            }
            else
            {
                rgb_matrix_set_color(index, RGB_OFF);
            }
        }
    }

    return false;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
}
