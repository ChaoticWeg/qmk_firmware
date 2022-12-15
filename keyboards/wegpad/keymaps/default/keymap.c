#include QMK_KEYBOARD_H
#include "weg_keymap.h"
#include "print.h"

void keyboard_post_init_user(void) {
    #if defined(WEG_DEBUG) && defined(CONSOLE_ENABLE)
        debug_enable = true;
    #endif
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WEG_LAYER_BASE] = LAYOUT_ortho_5x5(
        KC_NUM,  KC_F13,  KC_F14,  KC_HOME, MO(WEG_LAYER_RGB),
        KC_P7,   KC_P8,   KC_P9,   KC_END,  KC_NO,
        KC_P4,   KC_P5,   KC_P6,   KC_NO,   KC_MPLY,
        KC_P1,   KC_P2,   KC_P3,   KC_NO,   KC_NO,
        KC_P0,   KC_P0,   KC_PDOT, KC_NO,   KC_NO
    ),

    [WEG_LAYER_RGB] = LAYOUT_ortho_5x5(
        QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   RGB_TOG,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO
    )
};

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [1] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
    };
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef WEG_DEBUG
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
