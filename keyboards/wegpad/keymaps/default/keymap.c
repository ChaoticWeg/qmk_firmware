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
        KC_A,    KC_B,    KC_C,    KC_D,    MO(WEG_LAYER_RGB),
        KC_F,    KC_G,    KC_H,    KC_I,    KC_NO,
        KC_K,    KC_L,    KC_M,    KC_NO,   KC_MPLY,
        KC_P,    KC_Q,    KC_R,    KC_NO,   KC_NO,
        KC_U,    KC_V,    KC_W,    KC_NO,   KC_NO
    ),

    [WEG_LAYER_RGB] = LAYOUT_ortho_5x5(
        QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   BL_TOGG,
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
