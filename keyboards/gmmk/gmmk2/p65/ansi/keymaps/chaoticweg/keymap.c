/* Copyright 2022 Shawn Lutch <shawn@chaoticweg.cc>
 * Derived from original keymap.c by Glorious, LLC <salman@pcgamingrace.com>
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

#define WEG_CAPS    LT(_FL, KC_CAPS)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum custom_layers {
    _BL,
    _FL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ┌─────────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
     * │   GESC  │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │  -   │  =   │ Bksp │ Null │
     * ├─────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * │   Tab   │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │  [   │  ]   │  \   │ Null │
     * ├─────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┴──────┼──────┤
     * │ FL/CAPS │   A  │   S  │   D  │   F  │   G  │   H  │   J  │   K  │   L  │   ;  │   '  │    Enter    │ Null │
     * ├─────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┴──────┬──────┼──────┤
     * │  Shift  │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │     Gui     │  Up  │ Null │
     * ├─────────┼──────┼──────┼──────┴──────┴──────┴──────┴──────┴──────┼──────┴───┬──┴──────┬──────┼──────┼──────┤
     * │   Ctrl  │ Win  │ Alt  │                 Space                   │    FL    |   Alt   │ Left │ Down │ Right│
     * └─────────┴──────┴──────┴─────────────────────────────────────────┴──────────┴─────────┴──────┴──────┴──────┘
     */
    [_BL] = LAYOUT(
        QK_GESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_MPLY,
        KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_VOLU,
        WEG_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,             KC_VOLD,
        KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RGUI,            KC_UP,    KC_NO,
        KC_LCTL,   KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    /* Function layer
     * ┌─────────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
     * │    `    │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  F7  │  F8  │  F9  │ F10  │ F11  │ F12  │ Del  │ Ins  │
     * ├─────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * │         │      │      │      │      │      │      │      │      │      │PtScn │ ScLk │ PsBk │      │      │
     * ├─────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┴──────┼──────┤
     * │         │      │      │      │      │      │      │      │      │      │      │      │             │      │
     * ├─────────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┴──────┬──────┼──────┤
     * │         │      │      │      │      │      │      │      │      │      │      │             │ PgUp │      │
     * ├─────────┼──────┼──────┼──────┴──────┴──────┴──────┴──────┴──────┼──────┴───┬──┴──────┬──────┼──────┼──────┤
     * │         │      │      │                QK_BOOT                  │          |         │ Home │ PgDn │ End  │
     * └─────────┴──────┴──────┴─────────────────────────────────────────┴──────────┴─────────┴──────┴──────┴──────┘
     */
    [_FL] = LAYOUT(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,    KC_DEL,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  KC_SCRL,   KC_PAUS,   KC_INS,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,             _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  C(KC_GRV),            KC_PGUP,  _______,
        _______,  _______,  _______,                                QK_BOOT,                                _______,  _______,   KC_HOME,   KC_PGDN,  KC_END
    )
};

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_WEG_BREATHING);
}
