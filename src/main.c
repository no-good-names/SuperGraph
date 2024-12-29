#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <typedef.h>
#include <cmaths.h>
#include <renderer.h>

struct {
    SDL_Window *window; // canvas
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    uint32_t pixels[SCREEN_WIDTH * SCREEN_HEIGHT]; // viewport
    v3_t camera; // camera pos in 3D space (x, y, z)
    v3_t view_dir; // for basic raytracing
    bool running;
} state;

// temp global
// Test Spheres
Sphere_t s[4] = {
    {.center = {0.0f, -1.0f, 3.0f}, .radius = 1, RGB(0xFF, 0x00, 0xFF) },
    {.center = {-1.0f, 0.0f, 4.0f}, .radius = 1, RGB(0xFF, 0x00, 0x00) },
    {.center = {-0.3f, 0.0f, 5.0f}, .radius = 1, RGB(0x00, 0x00, 0xFF) },
    {.center = {-0.3f, 1.0f, 6.0f}, .radius = 1, RGB(0x00, 0xFF, 0xFF) }
};


// Sets the pixel at the given x and y coordinates to the given color
void setPixel(int32_t x, int32_t y, const uint32_t color) {
    x += SCREEN_WIDTH/2;
    y += SCREEN_HEIGHT/2;
    // Check if x or y is out of bounds
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }
    state.pixels[(y * SCREEN_WIDTH) + x] = color;
}

// render function
void render() {
    for (int y = -SCREEN_HEIGHT/2; y < SCREEN_HEIGHT / 2; y++) {
        for (int x = -SCREEN_WIDTH/2; x < SCREEN_WIDTH/2; x++) {
            // TODO: do something for show
            state.view_dir = CanvasToViewport(x, y);
            uint32_t color = TraceRay(state.camera, state.view_dir, 0, INFINITY, s, 4);
            setPixel(x, y, color);
        }
    }
    drawLine(setPixel, (v2_t) {0, 0}, (v2_t) {100, 100}, 0xFFFFFFFF << (SDL_GetTicks()));
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    state.window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    state.texture = SDL_CreateTexture(state.renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    state.running = true;
    state.camera = (v3_t) {0, 0, 0};
    state.view_dir = (v3_t) {0, 0, 0};
    fprintf(stderr, "The line is here on purpose\n");
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
            state.camera.z += 0.1f;
        }
        if (keys[SDL_SCANCODE_S]) {
            state.camera.z -= 0.1f;
        }
        if (keys[SDL_SCANCODE_A]) {
            state.camera.x -= 0.1f;
        }
        if (keys[SDL_SCANCODE_D]) {
            state.camera.x += 0.1f;
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
