#pragma once

// Colors courtesy of Nord <https://www.nordtheme.com>
// ALL COLORS ARE IN HSV TO SUPPORT RGB_VAI/VAD ON ENCODER LAYER 1
#define WEG_COLOR_BLACK         155, 71, 10
#define WEG_COLOR_WHITE         155, 17, 232
#define WEG_COLOR_LIGHT_BLUE    148, 84, 193
#define WEG_COLOR_DARK_BLUE     150, 114, 170
#define WEG_COLOR_CYAN          136, 89, 209
#define WEG_COLOR_RED           250, 124, 191
#define WEG_COLOR_GREEN         65,  120, 191
#define WEG_COLOR_PURPLE        220, 53, 181

// Fallback in case we get an invalid layer or something else weird like that
#define WEG_LAYER_COLOR_FALLBACK    WEG_COLOR_WHITE

// Underglow color
#define WEG_LAYER_COLOR_UNDERGLOW   WEG_COLOR_BLACK

// Color for each layer
#define WEG_LAYER_COLOR_BASE        WEG_COLOR_PURPLE
#define WEG_LAYER_COLOR_RGB         WEG_COLOR_CYAN
#define WEG_LAYER_COLOR_WIN         WEG_COLOR_GREEN

// Color for particular keycodes
// RGB is fine here
#define WEG_RGB_COLOR_QK_BOOT       RGB_RED
