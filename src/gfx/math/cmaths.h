#ifndef CMATHS_H
#define CMATHS_H

#include "../typedef.h"
#include "vec3.h"


/////////////// MATH DEFS ///////////////
#define PI 3.14159265358979323846
// Macros
#define DEG2RAD(deg) ((deg) * PI / 180.0f)
#define RAD2DEG(rad) ((rad) * 180.0f / PI)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct Vector2_t {
	float x, y;
} v2_t;

typedef struct Vector3_t {
	float x, y, z;
} v3_t;

typedef struct IntVector3_t {
	int x, y, z;
} iv3_t;

typedef struct Vector4_t {
	float x, y, z, w;
} v4_t;

typedef struct Point_t {
	float x, y, z;
} Point_t;

typedef struct Sphere_t {
	v3_t center;
	float radius;
	uint32_t color;
} Sphere_t;

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

// VECTOR MATHS
v3_t v3_add(v3_t a, v3_t b);
v3_t v3_sub(v3_t a, v3_t b);
v3_t v3_mul(v3_t a, v3_t b);
v3_t v3_cross(v3_t a, v3_t b);
float v3_dot(v3_t a, v3_t b);
float v3_length(v3_t a);
v3_t v3_normalize(v3_t a);

// Ray equation
v3_t rayeq(v3_t origin, v3_t dir, float step);
// gets the pixel from the screen canvas at (x, y) and scales the pixel onto the window's canvas
// for future reference and/or playing around
DEPRECATED("This is done by SDL2 in this project") v3_t getPixelIndex(uint32_t x, uint32_t y);
#endif // CMATHS_H
