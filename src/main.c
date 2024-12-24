#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <typedef.h>
#include <cmaths.h>

// TODO: Move the math functions to a separate file
// TODO: Move the typedefs to a separate file
// TODO: Move the rendering functions to a separate file

struct {
    SDL_Window *window; // canvas
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    uint32_t pixels[SCREEN_WIDTH * SCREEN_HEIGHT]; // viewport
    v3_t camera; // camera pos in 3D space (x, y, z) only x and y are needed for 2D
    v3_t view_dir; // for basic raytracing (apparently needed)
    bool running;
} state;

// 8bit max is 255
uint32_t color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return (a << 24) | (r << 16) | (g << 8) | b;
}

// Sets the pixel at the given x and y coordinates to the given color
void setPixel(uint32_t x, uint32_t y, uint32_t color) {
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }
    state.pixels[y * SCREEN_WIDTH + x] = color;
}

// render function
void render() {
    for (uint32_t y = 0; y < SCREEN_HEIGHT; y++) {
        for (uint32_t x = 0; x < SCREEN_WIDTH; x++) {
            setPixel(x, y, 0x22FF00FF);
        }
    }
    setPixel(100, 100, color(255, 255, 255, 255)); // Test pixel
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    state.window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    state.texture = SDL_CreateTexture(state.renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    state.running = true;
    while (state.running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                state.running = false;
            }
        }
        memset(state.pixels, 0, sizeof(state.pixels)); // sets all pixels aloc mem to white (0x00000000)
        render();

        SDL_UpdateTexture(state.texture, NULL, state.pixels, SCREEN_WIDTH * 4);
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
