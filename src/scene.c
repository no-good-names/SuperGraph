//
// Created by cp176 on 12/28/2024.
//

#include <scene.h>

void init_scene(scene_t *scene) {
	scene->object_count = 0;
}

// TODO: Implement this
void createSceneObject(scene_t *scene, const object_t object) {
	if (scene->object_count < MAX_OBJECTS) {
		scene->scene_objects[scene->object_count++] = object;
	}
}
