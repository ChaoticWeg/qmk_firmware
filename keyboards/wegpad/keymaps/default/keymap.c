#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │
     * ├───┼───┼───┼───┼───┤
     * │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┤
     * │ K │ L │ M │   │ > │ <-- [2, 4] is encoder click
     * ├───┼───┼───┼───┼───┤
     * │ P │ Q │ R │   │   │
     * ├───┼───┼───┼───┼───┤
     * │ U │ V │ W │   │   │
     * └───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_5x5(
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,
        KC_F,    KC_G,    KC_H,    KC_I,    KC_J,
        KC_K,    KC_L,    KC_M,    KC_NO,   KC_MPLY,
        KC_P,    KC_Q,    KC_R,    KC_NO,   KC_NO,
        KC_U,    KC_V,    KC_W,    KC_NO,   KC_NO
    )
};
