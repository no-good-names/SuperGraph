#ifndef PRIM_H
#define PRIM_H

// PRIMITIVE STUFF

#include "typedef.h"
#include "math/cmaths.h"
#include "utils/utils.h"

void drawLine(void (*setPixel)(int32_t x, int32_t y, uint32_t color), v2_t start, v2_t end, uint32_t color);

#endif //PRIM_H
