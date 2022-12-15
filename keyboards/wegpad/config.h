// Copyright 2022 Shawn Lutch (@chaoticweg)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

/* RGB */

#ifdef RGB_MATRIX_ENABLE
#   define RGB_DI_PIN                      B15     // GPIO to data
#   define RGB_MATRIX_LED_COUNT            33      // Number of LEDs
#endif

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
