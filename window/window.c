//
// Created by vitor on 26/09/2026.
//

#include "window.h"

int programWindow() {
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "Cool text browski",
        640,
        480,
        SDL_WINDOW_OPENGL);

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Delay(10000);
    return 0;
}