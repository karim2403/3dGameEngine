#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

const int width = 800;
const int height = 600;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("HELLO WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == NULL) {
        perror("sdl_createwindow");
        return -1;
    }
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_Event e;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}