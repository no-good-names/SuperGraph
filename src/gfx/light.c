//
// Created by cp176 on 1/9/2025.
//

#include "light.h"
#include "math/cmaths.h"

float compute_light(Light_t light, v3_t point, v3_t normal) {
    float i = 0.0f;
    v3_t l;
    if(light.type == LIGHT_AMBIENT) {
        i += light.intensity;
    } else {
        if(light.type == LIGHT_POINT) {
            l = v3_normalize(v3_sub(light.position, point));
        } else if(light.type == LIGHT_DIRECTIONAL) {
            l = v3_normalize(light.direction);
        }
        float n_dot_l = v3_dot(normal, l);
        if(n_dot_l > 0) {
            i += light.intensity * n_dot_l / (v3_length(normal) * v3_length(l));
        }
    }
    if(i >= 1) {
        return 1;
    }
    return i;
}
