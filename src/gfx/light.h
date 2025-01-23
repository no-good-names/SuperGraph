//
// Created by cp176 on 1/9/2025.
//

#ifndef LIGHT_H
#define LIGHT_H

#include "math/cmaths.h"
#include "SDL2/SDL_stdinc.h"

enum LIGHT_TYPE {
	LIGHT_NONE = 0,
	LIGHT_POINT,
	LIGHT_DIRECTIONAL,
	LIGHT_SPOT,
	LIGHT_AMBIENT
};

typedef struct Light_t {
	enum LIGHT_TYPE type;
	v3_t position;
	float intensity;
	v3_t direction;
} Light_t;

float compute_light(Light_t light, v3_t point, v3_t normal);

#endif //LIGHT_H
