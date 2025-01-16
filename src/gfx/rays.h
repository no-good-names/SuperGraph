//
// Created by cp176 on 1/15/2025.
//

#ifndef RAYS_H
#define RAYS_H

#include "light.h"
#include "typedef.h"
#include "math/cmaths.h"

static v3_t CanvasToViewport(const int32_t x, const int32_t y) {
	// Depth z = 1 for now
	v3_t ray_dir = {
		(float) x * VIEWPORT_WIDTH / SCREEN_WIDTH,
		(float) y * VIEWPORT_HEIGHT / SCREEN_HEIGHT,
		1 // Assuming the camera is looking along +Z initially
	};
	return ray_dir;
}

v2_t IntersectRaySphere(v3_t origin, v3_t direction, Sphere_t sphere);
uint32_t TraceRay(v3_t origin, v3_t direction, float t_min, float t_max, Sphere_t *s, int numOfS);

#endif //RAYS_H
