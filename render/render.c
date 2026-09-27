//
// Created by vitor on 27/09/2026.
//

#include "render.h"

SDL_Renderer *render_init(SDL_Window *window) {
    SDL_Renderer *ren = SDL_CreateRenderer(window, NULL);
    if (ren == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateRenderer %s", SDL_GetError());
    }
    return ren;
}

void render_draw_solid_color_in_window(SDL_Renderer *ren, uint8_t const r, uint8_t const g, uint8_t const b) {
    SDL_SetRenderDrawColor(ren, r, g, b, 255);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
}

void render_shutdown(SDL_Renderer *ren) {
    SDL_DestroyRenderer(ren);
}
