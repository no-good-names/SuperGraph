//
// Created by cp176 on 1/19/2025.
//

#ifndef CAMERA_H
#define CAMERA_H

#include "math/cmaths.h"

enum CAMERA_TYPE {
	CAMERA_NONE = 0,
	CAMERA_PERSPECTIVE,
	CAMERA_ORTHOGRAPHIC
};

typedef struct Camera_t {
	v3_t position;
	v3_t view_dir;
	enum CAMERA_TYPE type;
} Camera_t;

Camera_t createCamera(v3_t position, v3_t view_dir);
// rotates the camera horizontally
v3_t rotateX(v3_t v, float angle);
// TODO: FIX
// rotates the camera vertically
v3_t rotateY(v3_t v, float angle);

#endif //CAMERA_H
