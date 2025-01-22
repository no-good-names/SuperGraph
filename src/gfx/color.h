#ifndef COLOR_H
#define COLOR_H

#include "typedef.h"

#define MULTIPLY_COLOR(color, intensity) (uint32_t) ((color & 0xFF000000) | ((int) (((color & 0x00FF0000) >> 16) * intensity) << 16) | ((int) (((color & 0x0000FF00) >> 8) * intensity) << 8) | (int) ((color & 0x000000FF) * intensity))

#endif //COLOR_H
