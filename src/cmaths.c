#include <stdio.h>
#include <typedef.h>
#include <cmaths.h>
#include <math.h>
#include <stdbool.h>

// add two vectors
v3_t v3_add(v3_t a, v3_t b) {
    return (v3_t) {
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };
}

v3_t v3_sub(v3_t a, v3_t b) {
    return (v3_t) {
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z
    };
}

v3_t v3_mul(v3_t a, v3_t b) {
    return (v3_t) {
        .x = a.x * b.x,
        .y = a.y * b.y,
        .z = a.z * b.z
    };
}

v3_t v3_normalize(v3_t a) {
    float length = sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
    return (v3_t) {
        .x = a.x / length,
        .y = a.y / length,
        .z = a.z / length
    };
}

v3_t v3_cross(v3_t a, v3_t b) {
    return (v3_t) {
        .x = a.y * b.z - a.z * b.y,
        .y = a.z * b.x - a.x * b.z,
        .z = a.x * b.y - a.y * b.x
    };
}

float v3_dot(v3_t a, v3_t b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// ray equation: P = O + t(V-O)
// ray equation: P = O + tD
v3_t rayeq(const v3_t origin, const v3_t dir, const float step) {
    return (v3_t) {
        .x = origin.x + step * dir.x,
        .y = origin.y + step * dir.y,
        .z = origin.z + step * dir.z
    };
}

// B * t + A * (1-t)
float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

// NOTE: SDL already does this for you when you create a window with a smaller texture
// Determines which square on the viewport the pixel is in : Already done by SDL
// Vx = Cx * Vw/Cw : returns the x coordinate of the pixel in the viewport
// Vy = Cy * Vh/Ch : returns the y coordinate of the pixel in the viewport
__attribute__((deprecated)) v3_t getPixelIndex(uint32_t x, uint32_t y) {
   return (v3_t) {
       .x = (float) x * SCREEN_WIDTH / WINDOW_WIDTH,
       .y = (float) y * SCREEN_HEIGHT / WINDOW_HEIGHT,
       .z = 0
   };
}

void drawLine(void (setPixel)(int32_t x, int32_t y, uint32_t color), v2_t start, v2_t end, uint32_t color) {
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = start.x < end.x ? 1 : -1;
    int sy = start.y < end.y ? 1 : -1;
    int err = dx - dy;
    int e2;

    while(true) {
        setPixel(start.x, start.y, color);
        if(start.x == end.x && start.y == end.y) break;
        e2 = 2 * err;
        if(e2 > -dy) {
            err -= dy;
            start.x += sx;
        }
        if(e2 < dx) {
            err += dx;
            start.y += sy;
        }
    }
}

