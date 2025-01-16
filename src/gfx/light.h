//
// Created by cp176 on 1/9/2025.
//

#ifndef LIGHT_H
#define LIGHT_H

#include "math/cmaths.h"

enum LIGHT_TYPE {
	LIGHT_NONE = 0,
	LIGHT_POINT,
	LIGHT_DIRECTIONAL,
	LIGHT_SPOT
};

typedef struct Light_t {
	int type;
	v3_t position;
	float intensity;
	v3_t direction;
} Light_t;

#endif //LIGHT_H
