//
// Created by cp176 on 12/28/2024.
//

#ifndef SCENE_H
#define SCENE_H

#include <typedef.h>
#include <cmaths.h>

#ifndef MAX_OBJECTS
#define MAX_OBJECTS 100
#endif

enum OBJ_TYPE {
	OBJ_NONE = 0, // its just here
	OBJ_SPHERE,
};

typedef struct Object_t {
	int type;
	float x, y, z;
	float radius;
	float color;
} object_t;

// TODO:
typedef struct node_t {
	object_t object;
	struct node_t *next;
} node_t;

typedef struct Scene_t {
	object_t scene_objects[MAX_OBJECTS];
	uint32_t object_count;
} scene_t;

void init_scene(scene_t *scene);
void createSceneObject(scene_t *scene, object_t object);

#endif //SCENE_H
