// Copyright 2022 Shawn Lutch (@chaoticweg)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "wegpad.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    // Key Matrix to LED Index
    {
        // Keys
        { 4,      3,      2,       1,       0      },
        { 5,      6,      7,       8,       9      },
        { 12,     11,     10,      NO_LED,  19     },
        { 13,     14,     15,      NO_LED,  NO_LED },
        { 18,     17,     16,      NO_LED,  NO_LED }
    },
    // LED Index to Physical Position
    {
        // Key leds
        {224, 0},   {168, 0},   {112, 0},   {56, 0},    {0, 0},
        {0, 16},    {56, 16},   {112, 16},  {168, 16},  {224, 16},
        {224, 32},  {168, 32},  {112, 32},  {56, 32},   {0, 32},
        {0, 48},    {56, 48},   {112, 48},  {168, 48},  {224, 48},
        {112, 64},  {56, 64},   {0, 64},

        // Underglow is slightly offset on the back of the board
                {28, 8},  {84, 8},  {140, 8},  {196, 8},
                                               {196, 24},
                                               {196, 40},
                {28, 56}, {84, 56}, {140, 56}, {196, 56}

    },
    // LED Index to Flag
    {
        // Keys
        [0 ... 19] = 4,

        // Underglow
        [20 ... 32] = 2
    }
};
#endif
