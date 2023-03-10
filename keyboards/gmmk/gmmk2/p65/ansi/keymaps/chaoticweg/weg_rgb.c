#include "weg_rgb.h"
#include "weg_color.h"

typedef struct { uint8_t h, s; } weg_hs_t;

static weg_hs_t current_hs;
static weg_hs_t hs_per_layer[] = {
    [0] = { WEG_BLUE_HS },
    [1] = { WEG_PAPAYA_HS },
    [2] = { WEG_PURPLE_HS }
};

/** Copies the hue and saturation value from the static array to the weg_hs_t at the address provided */
void copy_hs_for_layer(weg_hs_t *hs, uint8_t layer) {
    memset(hs, 0, sizeof(weg_hs_t));
    memcpy(hs, &hs_per_layer[layer], sizeof(weg_hs_t));
}

/** Sets a solid red color */
void weg_rgb_set_caps_lock(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
            RGB_MATRIX_INDICATOR_SET_COLOR(i, 255, 0, 0);
        }
    }
}

/**
 * Overrides the hue and sat of the layer without saving to EEPROM.
 * Does NOT override the value; instead reads value from the matrix.
 */
void weg_rgb_set_layer(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    uint8_t val = rgb_matrix_get_val();

    copy_hs_for_layer(&current_hs, layer);
    rgb_matrix_sethsv_noeeprom(current_hs.h, current_hs.s, val);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    bool caps_locked = host_keyboard_led_state().caps_lock;

    if (caps_locked) {
        weg_rgb_set_caps_lock(led_min, led_max);
        return false;
    }

    weg_rgb_set_layer(led_min, led_max);
    return false;
}
