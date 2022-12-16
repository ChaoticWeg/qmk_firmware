#include "weg_rgb.h"

static bool caps_locked;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    caps_locked = host_keyboard_led_state().caps_lock;
    if (!caps_locked) return false;

    for (uint8_t i = led_min; i < led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
            rgb_matrix_set_color(i, RGB_RED);
        }
    }

    return false;
}
