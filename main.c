#include <SDL2/SDL.h>
#include <stdio.h>

const int width = 800;
const int height = 600;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("HELLO WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == NULL) {
        perror("sdl_createwindow");
        return -1;
    }
    SDL_Event windowEvent;

    while (1) {
        if (SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_WINDOWEVENT_CLOSE) {
                break;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}