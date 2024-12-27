#ifndef CMATHS_H
#define CMATHS_H

#include <typedef.h>

// VECTOR MATHS
v3_t v3_add(v3_t a, v3_t b);
v3_t v3_sub(v3_t a, v3_t b);
v3_t v3_mul(v3_t a, v3_t b);
v3_t v3_cross(v3_t a, v3_t b);
float v3_dot(v3_t a, v3_t b);

// TODO: MOVE THIS TO A SEPARATE FILE
// MATRIX MATHS
#define MAT2_ADD(a, b) ((mat2_t){{  \
        a[0][0] + b[0][0],          \
        a[0][1] + b[0][1]},         \
        {a[1][0] + b[1][0],         \
        a[1][1] + b[1][1]}})
#define MAT2_SUB(a, b) ((mat2_t){{  \
        a[0][0] - b[0][0],          \
        a[0][1] - b[0][1]},         \
        {a[1][0] - b[1][0],         \
        a[1][1] - b[1][1]}})
#define MAT3_ADD(a, b) ((mat3_t){{  \
        a[0][0] + b[0][0],          \
        a[0][1] + b[0][1],          \
        a[0][2] + b[0][2]},         \
        {a[1][0] + b[1][0],         \
        a[1][1] + b[1][1],          \
        a[1][2] + b[1][2]},         \
        {a[2][0] + b[2][0],         \
        a[2][1] + b[2][1],          \
        a[2][2] + b[2][2]}})
#define MAT3_SUB(a, b) ((mat3_t){{  \
        a[0][0] - b[0][0],          \
        a[0][1] - b[0][1],          \
        a[0][2] - b[0][2]},         \
        {a[1][0] - b[1][0],         \
        a[1][1] - b[1][1],          \
        a[1][2] - b[1][2]},         \
        {a[2][0] - b[2][0],         \
        a[2][1] - b[2][1],          \
        a[2][2] - b[2][2]}})

// Ray equation
v3_t rayeq(const v3_t origin, const v3_t dir, const float step);
__attribute__((deprecated)) v3_t getPixelIndex(uint32_t x, uint32_t y);

#endif // CMATHS_H
