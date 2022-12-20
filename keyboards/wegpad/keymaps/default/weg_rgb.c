#include QMK_KEYBOARD_H
#include "weg_keymap.h"
#include "weg_rgb.h"

static uint8_t max_v;

static HSV underglow_hsv = (HSV) { WEG_LAYER_COLOR_UNDERGLOW };
static HSV colors_per_layer[] = {
    [_BASE] = (HSV) { WEG_LAYER_COLOR_BASE },
    [_RGB] = (HSV) { WEG_LAYER_COLOR_RGB },
    [_WIN] = (HSV) { WEG_LAYER_COLOR_WIN }
};

static void clamp_hsv_val(HSV *hsv) {
    max_v = rgb_matrix_get_val();
    hsv->v = MIN(hsv->v, max_v);
}

static void copy_hsv(HSV *dst, HSV *src) {
    memset(dst, 0, sizeof(HSV));
    memcpy(dst, src, sizeof(HSV));
    clamp_hsv_val(dst);
}

static RGB get_layer_color(uint8_t layer) {
    HSV result_hsv;
    copy_hsv(&result_hsv, &colors_per_layer[layer]);
    return hsv_to_rgb(result_hsv);
}

static RGB get_underglow_color(void) {
    HSV result_hsv;
    copy_hsv(&result_hsv, &underglow_hsv);
    return hsv_to_rgb(result_hsv);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    uint8_t row, col, index;
    keypos_t keypos;
    RGB active_rgb;

    // Light up keys
    active_rgb = get_layer_color(layer);
    for (row = 0; row < MATRIX_ROWS; row++) {
        for (col = 0; col < MATRIX_COLS; col++) {
            index = g_led_config.matrix_co[row][col];
            RGB_MATRIX_INDICATOR_SET_COLOR(index, active_rgb.r, active_rgb.g, active_rgb.b);

            // Don't do anything if this index is outside led_min/max or NO_LED
            if (index < led_min || index >= led_max || index == NO_LED) {
                continue;
            }

            keypos = (keypos_t) {col, row};

            if (keymap_key_to_keycode(layer, keypos) == QK_BOOT) {
                rgb_matrix_set_color(index, WEG_RGB_COLOR_QK_BOOT);
            }
        }
    }

    // Light up underglow - can start at i=20 since that's the first underglow LED in the chain
    active_rgb = get_underglow_color();
    for (index = 20; index < RGB_MATRIX_LED_COUNT; index++) {
        RGB_MATRIX_INDICATOR_SET_COLOR(index, active_rgb.r, active_rgb.g, active_rgb.b);
    }

    return false;
}
