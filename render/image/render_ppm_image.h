#ifndef RENDER_PPM_IMAGE
#define RENDER_PPM_IMAGE

#include <stdio.h>
#include <stdlib.h>
#include "../../decoder/image/ppm_decoder.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

void render_image(SDL_Renderer *ren, ppm_decoded_t *img);

#endif
