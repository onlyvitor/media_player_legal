#include "render_ppm_image.h"

void render_image(SDL_Renderer *ren, ppm_decoded_t *img)
{
    uint32_t width = (int)img->dims.width;
    uint32_t height = (int)img->dims.height;
    uint8_t pixels = (int)img->pixels;

    SDL_Texture *texture = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STATIC, width, height);

    if (!texture)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateTexture %s", SDL_GetError());
    }

    // check if updated texture
    if (!SDL_UpdateTexture(texture, NULL, img->pixels, width * 3))
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());

    // set background
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);

    // render all image
    SDL_RenderTexture(ren, texture, NULL, NULL);

    SDL_RenderPresent(ren);
    SDL_DestroyTexture(texture);
}