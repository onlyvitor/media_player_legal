//
// Created by vitor on 27/09/2026.
//

#ifndef IMAGE_VIEWER_RENDER_DRAW_H
#define IMAGE_VIEWER_RENDER_DRAW_H

#include <stdint.h>
#include <SDL3/SDL.h>

SDL_Renderer *render_init(SDL_Window *window);
void render_draw_solid_color_in_window(SDL_Renderer *ren, uint8_t r, uint8_t g, uint8_t b);
void render_shutdown(SDL_Renderer *ren);

#endif //IMAGE_VIEWER_RENDER_DRAW_H
