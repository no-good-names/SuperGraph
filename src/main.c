#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "SDL2/SDL_scancode.h"
#include "gfx/camera.h"
#include "gfx/gfx.h"
#include "gfx/rays.h"

struct {
    SDL_Window *window; // canvas
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    uint32_t pixels[SCREEN_WIDTH * SCREEN_HEIGHT]; // viewport
    Camera_t camera;
    bool running;
} state;

// temp global
// Test Spheres
static uint8_t numberOfSpheres = 4;
Sphere_t s[4] = {
    //          x,     y,    z,          radius,     r,    g,    b
    {.center = {-2.2f, 0.0f, 5.0f}, .radius = 1, RGB(0xFF, 0x00, 0xFF) },
    {.center = { 1.5f, 0.0f, 4.0f}, .radius = 1, RGB(0xFF, 0x00, 0x00) },
    {.center = {-0.3f, 0.0f, 5.0f}, .radius = 1, RGB(0x00, 0x00, 0xFF) },
    {.center = {-0.3f, 1.0f, 6.0f}, .radius = 1, RGB(0x00, 0xFF, 0x11) }
};

Light_t light = {
    .type = LIGHT_POINT,
    .position = {0, 0, 0},
    .intensity = 0.6f
};

// Sets the pixel at the given x and y coordinates to the given color
void setPixel(int32_t x, int32_t y, const uint32_t color) {
    // start at the middle of the screen
    x += SCREEN_WIDTH/2;
    y += SCREEN_HEIGHT/2;
    // Check if x or y is out of bounds
    // EX: x=-SCREEN_WIDTH/2 - 1; x+= SCREEN_WIDTH/2; x=-1; doesn't draw
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }
    state.pixels[(y * SCREEN_WIDTH) + x] = color;
}

// render function
void render() {
    for (int y = -SCREEN_HEIGHT/2; y < SCREEN_HEIGHT / 2; y++) {
        for (int x = -SCREEN_WIDTH/2; x < SCREEN_WIDTH/2; x++) {
            // Use the updated view_dir for rendering
            v3_t ray_dir = rotateX(CanvasToViewport(x, y), atan2f(state.camera.view_dir.z, state.camera.view_dir.x));
            uint32_t color = TraceRay(state.camera.position, ray_dir, 0, INFINITY, s, numberOfSpheres, light);
            setPixel(x, y, color);
        }
    }
    // Test drawLine
    drawLine(setPixel, (v2_t) {100, 100}, (v2_t) {0, 0}, 0xFFFFFFFF >> (SDL_GetTicks()) >> (2));
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    state.window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    state.texture = SDL_CreateTexture(state.renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    state.running = true;
    state.camera = createCamera((v3_t) {0, 0, 0}, (v3_t) {1, 0, 0});
    while (state.running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                state.running = false;
                goto end;
            }
        }

        // Movement
        const uint8_t *keys = SDL_GetKeyboardState(NULL);
        if (keys[SDL_SCANCODE_W]) {
            state.camera.position.x -= state.camera.view_dir.z * 0.1f;
            state.camera.position.z += state.camera.view_dir.x * 0.1f;
        }
        if (keys[SDL_SCANCODE_S]) {
            state.camera.position.x += state.camera.view_dir.z * 0.1f;
            state.camera.position.z -= state.camera.view_dir.x * 0.1f;
        }
        if (keys[SDL_SCANCODE_A]) {
            state.camera.position.x -= state.camera.view_dir.x * 0.1f;
            state.camera.position.z -= state.camera.view_dir.z * 0.1f;
        }
        if (keys[SDL_SCANCODE_D]) {
            state.camera.position.x += state.camera.view_dir.x * 0.1f;
            state.camera.position.z += state.camera.view_dir.z * 0.1f;
        }
        if (keys[SDL_SCANCODE_RIGHT]) {
            state.camera.view_dir = rotateX(state.camera.view_dir, -0.05f); // Rotate by -0.5 radians
        }
        if (keys[SDL_SCANCODE_LEFT]) {
            state.camera.view_dir = rotateX(state.camera.view_dir, 0.05f); // Rotate by 0.5 radians
        }
        memset(state.pixels, 0, sizeof(state.pixels)); // Clear the pixel buffer
        render();
        SDL_UpdateTexture(state.texture, NULL, state.pixels, SCREEN_WIDTH * sizeof(state.pixels[0]));
        SDL_RenderCopyEx(
            state.renderer,
            state.texture,
            NULL,
            NULL,
            0.0,
            NULL,
            SDL_FLIP_VERTICAL);
        SDL_RenderPresent(state.renderer);
    }
    end:
    SDL_DestroyTexture(state.texture);
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
    SDL_Quit();
    return 0;
}
