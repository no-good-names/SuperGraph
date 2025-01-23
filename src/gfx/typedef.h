#ifndef TYPEDEF_H
#define TYPEDEF_H

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

// Auto aspect ratio
#define VIEWPORT_WIDTH 1.0f
#define VIEWPORT_HEIGHT (VIEWPORT_WIDTH * (float) SCREEN_HEIGHT / SCREEN_WIDTH)

#define ASSERT(condition, message) if (!(condition)) { fprintf(stderr, "Assertion failed: %s\n", message); return 1; }
#define DEPRECATED(message) __attribute__((deprecated(message)))
#define RGB(r, g, b) (uint32_t) ((255 << 24) | (r << 16) | (g << 8) | b)

#endif // TYPEDEF_H
