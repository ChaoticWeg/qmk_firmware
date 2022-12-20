#include QMK_KEYBOARD_H
#include "weg_keymap.h"
#include "print.h"

#ifndef ______
#   define _______ KC_TRNS
#endif

#ifndef XXXXXXX
#   define XXXXXXX KC_NO
#endif

#define CW_LEFT C(G(KC_LEFT))
#define CW_RGHT C(G(KC_RGHT))

void keyboard_post_init_user(void) {
    #ifdef CONSOLE_ENABLE
        debug_enable = true;
    #endif
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_5x5(
        KC_NUM,  KC_F13,  KC_F14,  KC_HOME, MO(_RGB),
        KC_P7,   KC_P8,   KC_P9,   KC_END,  MO(_WIN),
        KC_P4,   KC_P5,   KC_P6,   XXXXXXX, KC_MPLY,
        KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX,
        KC_P0,   KC_P0,   KC_PDOT, XXXXXXX, XXXXXXX
    ),

    [_RGB] = LAYOUT_ortho_5x5(
        QK_BOOT, _______, _______, _______, XXXXXXX,
        _______, _______, _______, _______, _______,
        _______, _______, _______, XXXXXXX, RGB_TOG,
        _______, _______, _______, XXXXXXX, XXXXXXX,
        _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [_WIN] = LAYOUT_ortho_5x5(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, XXXXXXX,
        CW_LEFT, _______, CW_RGHT, XXXXXXX, _______,
        _______, _______, _______, XXXXXXX, XXXXXXX,
        _______, _______, _______, XXXXXXX, XXXXXXX
    )
};

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [_RGB]  = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
        [_WIN]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) }
    };
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        if (record->event.pressed) {
            // Only print on key-up
            uprintf(
                "KL :: kc=0x%04X :: col=%2u :: row=%2u\n",
                keycode, record->event.key.col, record->event.key.row
            );
        }
    #endif

    return true;
}
