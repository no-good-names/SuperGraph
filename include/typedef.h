#ifndef TYPEDEF_H
#define TYPEDEF_H

#if __cplusplus
extern "C" {
#endif

#include <stdint.h>

// Define the window width and height if not defined


#ifndef WINDOW_WIDTH
#define WINDOW_WIDTH 800
#endif
#ifndef WINDOW_HEIGHT
#define WINDOW_HEIGHT 600
#endif

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 400
#endif

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 300
#endif

#define PI 3.14159265358979323846

/////////////// MATH DEFS ///////////////
// Macros
#define DEG2RAD(deg) ((deg) * PI / 180.0f)
#define RAD2DEG(rad) ((rad) * 180.0f / PI)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct Vector2_t {
    float x;
    float y;
} v2_t;

typedef struct Vector3_t {
    float x;
    float y;
    float z;
} v3_t;

typedef struct Vector4_t {
    float x;
    float y;
    float z;
    float w;
} v4_t;

#define MAT2_IDENTITY ((mat2_t){    \
        {1, 0},                     \
        {0, 1}})
#define MAT3_IDENTITY ((mat3_t){    \
        {1, 0, 0},                  \
        {0, 1, 0},                  \
        {0, 0, 1}})
#define MAT4_IDENTITY ((mat4_t){    \
        {1, 0, 0, 0},               \
        {0, 1, 0, 0},               \
        {0, 0, 1, 0},               \
        {0, 0, 0, 1}})

typedef float mat2_t[2][2];
typedef float mat3_t[3][3];
typedef float mat4_t[4][4];
/////////////////////////////////////////

#if __cplusplus
}
#endif

#endif // TYPEDEF_H
