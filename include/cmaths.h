#ifndef CMATHS_H
#define CMATHS_H

#if __cplusplus
extern "C" {
#endif
#include <typedef.h>

// VECTOR MATHS
v3_t v3_add(v3_t a, v3_t b);
v3_t v3_sub(v3_t a, v3_t b);
v3_t v3_mul(v3_t a, v3_t b);
v3_t v3_cross(v3_t a, v3_t b);
v3_t v3_dot(v3_t a, v3_t b);

v3_t lerp(v3_t a, v3_t b, float t);
v3_t v3_normalize(v3_t a);

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
// RAY MATHS
v3_t RayDistance(v3_t a, v3_t b);

#if __cplusplus
}
#endif

#endif // CMATHS_H
