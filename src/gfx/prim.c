#include "prim.h"

#include <math.h>

void drawLine(void (setPixel)(int32_t x, int32_t y, uint32_t color), v2_t start, v2_t end, uint32_t color) {
    if (start.x > end.x) {
        swap(start, end);
    }

    const float a = (end.y - start.y) / (end.x - start.x);
    float y = start.y;

    for (int32_t x = (int) start.x; (float) x <= end.x; x++) {
        setPixel(x, (int32_t)roundf(y), color); // Use round to handle fractional y
        y += a; // Increment y based on the slope
    }
}
