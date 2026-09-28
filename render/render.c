//
// Created by vitor on 27/09/2026.
//

#include "render.h"

//initialize the renderer for load something in the window
SDL_Renderer *render_init(SDL_Window *window) {
    //create a renderer
    SDL_Renderer *ren = SDL_CreateRenderer(window, NULL);
    //check if the renderer is created successfully
    if (ren == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateRenderer %s", SDL_GetError());
    }
    //return the renderer for be used for other components
    return ren;
}

//create a window with a solid color
void render_draw_solid_color_in_window(SDL_Renderer *ren, uint8_t const r, uint8_t const g, uint8_t const b) {
    //define the properties
    SDL_SetRenderDrawColor(ren, r, g, b, 255);
    //load the renderer
    SDL_RenderClear(ren);
    //show the color
    SDL_RenderPresent(ren);
}

//destroy the renderer
void render_shutdown(SDL_Renderer *ren) {
    SDL_DestroyRenderer(ren);
}
