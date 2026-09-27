//
// Created by vitor on 27/09/2026.
//

#include "render.h"
#include <SDL3/SDL_log.h>

static SDL_Renderer *renderer = NULL;

void render_init(SDL_Window *window, uint8_t const r, uint8_t const g, uint8_t const b) {
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateRenderer %s", SDL_GetError());
    }
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
