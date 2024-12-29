//
// Created by cp176 on 12/28/2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <typedef.h>
#include <cmaths.h>

v3_t CanvasToViewport(const int32_t x, const int32_t y);
v2_t IntersectRaySphere(v3_t origin, v3_t direction, Sphere_t sphere);
uint32_t TraceRay(v3_t origin, v3_t direction, float t_min, float t_max, Sphere_t *s, int numOfS);

#endif //RENDERER_H
