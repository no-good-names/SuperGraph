#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <typedef.h>
#include <cmaths.h>

struct {
    SDL_Window *window; // canvas
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    uint32_t pixels[SCREEN_WIDTH * SCREEN_HEIGHT]; // viewport
    v3_t camera; // camera pos in 3D space (x, y, z)
    v3_t view_dir; // for basic raytracing
    bool running;
} state;

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

v3_t CanvasToViewport(const int32_t x, const int32_t y) {
    // Depth z = 1 for now
    return (v3_t) {x*VIEWPORT_WIDTH/SCREEN_WIDTH, y*VIEWPORT_HEIGHT/SCREEN_HEIGHT, 1};
}

// render function
void render() {
    for (int y = -SCREEN_HEIGHT/2; y < SCREEN_HEIGHT / 2; y++) {
        for (int x = -SCREEN_WIDTH/2; x < SCREEN_WIDTH/2; x++ ) {
            if (x<=0 && y<=0) {
                setPixel(x, y, 0xFFFF0000); // red
            }
            if (x>=0 && y>=0) {
                setPixel(x, y, 0xFF00FF00); // green
            }
            if (x<=0 && y>=0) {
                setPixel(x, y, 0xFF0000FF); // blue
            }
            if ((x*x) + (y*y) - pow(100, 2) <= 0) {
                setPixel(x, y, ARGB(0xFF, 0xFF, 0xFF, 0xFF)); // white
            }
        }
    }
}

void print_ray(v3_t origin, v3_t dir, float step) {
    printf("x: %f, y: %f, z: %f\n", rayeq(origin, dir, step).x, rayeq(origin, dir, step).y, rayeq(origin, dir, step).z);
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    state.window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    state.texture = SDL_CreateTexture(state.renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    state.running = true;
    float step = 0.0f;
    while (state.running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                state.running = false;
            }
        }
        memset(state.pixels, 0, sizeof(state.pixels)); // sets all pixels aloc mem to white (0x00000000)
        step += 0.01f;
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
    SDL_DestroyTexture(state.texture);
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
    SDL_Quit();
    return 0;
}
