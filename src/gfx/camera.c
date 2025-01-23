//
// Created by cp176 on 1/19/2025.
//

#include "camera.h"

#include <math.h>

Camera_t createCamera(v3_t position, v3_t view_dir) {
	return (Camera_t) {
		.position = position,
		.view_dir = view_dir
	};
}

// Function to rotate a vector around the Y-axis
v3_t rotateX(v3_t v, float angle) {
	float cosAngle = cosf(angle);
	float sinAngle = sinf(angle);
	return (v3_t) {
		.x = v.x * cosAngle - v.z * sinAngle,
		.y = v.y,
		.z = v.x * sinAngle + v.z * cosAngle
	};
}

// Function to rotate a vector around the X-axis
v3_t rotateY(v3_t v, float angle) {
	float cosAngle = cosf(angle);
	float sinAngle = sinf(angle);
	return (v3_t) {
		.x = v.x,
		.y = v.y * cosAngle - v.z * sinAngle,
		.z = v.y * sinAngle + v.z * cosAngle
	};
}

