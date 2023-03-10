#pragma once

#define IGNORE_MOD_TAP_INTERRUPT

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 175

#include "weg_color.h"

#define RGB_MATRIX_DEFAULT_HUE  WEG_PAPAYA_HUE
