//
// Created by vitor on 26/09/2026.
//

#include "window.h"

//create a window
int window_run(void) {
    //check if the SDL is loaded
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_Init %s", SDL_GetError());
        return 1;
    }
    //create a window
    SDL_Window *window = SDL_CreateWindow(
        "Cool Image Viewer",
        640,
        480,
        0);
    //check if the window is created
    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    //initialize the renderizer
    SDL_Renderer *ren = render_init(window);
    if (ren == NULL) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    //Initialize a eventloop
    while (running) {
        //create an event,
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            //if the close button window is pressed, the eventloop stop
            if (event.type == SDL_EVENT_QUIT ||
                event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
                running = false;
            }
        }
        render_draw_solid_color_in_window(ren, 255, 0, 0);
        //keeps the loop from burning the cpu while idle
        SDL_Delay(16);
    }

    render_shutdown(ren);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
