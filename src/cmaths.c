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

v3_t v3_dot(v3_t a, v3_t b) {
    return (v3_t) {
        .x = a.x * b.x,
        .y = a.y * b.y,
        .z = a.z * b.z
    };
}

// sqrtf((x2) - (x1))^2 + ((y2) - (y1))^2 + ((z2) - (z1))^2
v3_t RayDistance(v3_t a, v3_t b) {
    return (v3_t) {
        .x = b.x - a.x,
        .y = b.y - a.y,
        .z = b.z - a.z
    };
}

// A^2 + B^2 + C^2 = D^2
float length(v3_t a) {
    return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

// linear interpolation
v3_t lerp(v3_t a, v3_t b, float t) {
    return (v3_t) {
        .x = a.x + t * (b.x - a.x),
        .y = a.y + t * (b.y - a.y),
        .z = a.z + t * (b.z - a.z)
    };
}

// ray equation: P = O + t(V-O)
// ray equation: P = O + tD
v3_t RayCast(v3_t origin, v3_t direction, float t) {
    return (v3_t) {
        .x = origin.x + t * (float) RayDistance(origin, direction).x,
        .y = origin.y + t * (float) RayDistance(origin, direction).y,
        .z = origin.z + t * (float) RayDistance(origin, direction).z
    };
}

// NOTE: SDL already does this for you when you create a window with a smaller texture

// Determines which square on the viewport the pixel is in : Already done by SDL
// Vx = Cx * Vw/Cw : returns the x coordinate of the pixel in the viewport
// Vy = Cy * Vh/Ch : returns the y coordinate of the pixel in the viewport
// v3_t getPixelIndex(uint32_t x, uint32_t y) {
//    return (v3_t) {
//        .x = (float) x * SCREEN_WIDTH / WINDOW_WIDTH,
//        .y = (float) y * SCREEN_HEIGHT / WINDOW_HEIGHT,
//        .z = 0
//    };
// }

