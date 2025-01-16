//
// Created by cp176 on 1/15/2025.
//

#include "rays.h"

//
// Created by cp176 on 12/28/2024.
//

#include <math.h>
#include <stdlib.h>
#include "renderer.h"

// IMPORTANT
// NOTE: THIS CODE ONLY WORKS WITH SPHERES FOR NOW

v2_t IntersectRaySphere(const v3_t origin, const v3_t direction, const Sphere_t sphere) {
	const float r = sphere.radius;
	const v3_t CO = v3_sub(origin, sphere.center);

	const float a = v3_dot(direction, direction);
	const float b = 2 * v3_dot(CO, direction);
	const float c = v3_dot(CO, CO) - r * r;

	const float discriminant = b * b - 4 * a * c;
	if (discriminant < 0) {
		return (v2_t) {INFINITY, INFINITY};
	}

	const float t1 = (-b + sqrtf(discriminant)) / (2 * a);
	const float t2 = (-b - sqrtf(discriminant)) / (2 * a);
	return (v2_t) {t1, t2};
}

uint32_t TraceRay(const v3_t origin, const v3_t direction, const float t_min, const float t_max, Sphere_t *s, const int numOfS) {
	float closest_t = INFINITY;
	Sphere_t *closest_sphere = NULL;
	for (uint32_t i = 0; i < numOfS; i++) {
		v2_t t = IntersectRaySphere(origin, direction, s[i]);
		if (t.x >= t_min && t.x <= t_max && t.x < closest_t) {
			closest_t = t.x;
			closest_sphere = &s[i];
		}
		if (t.y >= t_min && t.y <= t_max && t.y < closest_t) {
			closest_t = t.y;
			closest_sphere = &s[i];
		}
	}
	if (closest_sphere == NULL) {
		return RGB(0,0,0);
	}
	return closest_sphere->color;
}

