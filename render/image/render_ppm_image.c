#include "render_ppm_image.h"

SDL_Texture *render_image_create(SDL_Renderer *ren, const ppm_decoded_t *img)
{
    if (img == NULL || img->pixels == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "render_image_create: no image to upload");
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTexture(
        ren,
        SDL_PIXELFORMAT_RGB24,
        SDL_TEXTUREACCESS_STATIC,
        (int)img->dims.width,
        (int)img->dims.height);

    if (texture == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_CreateTexture %s", SDL_GetError());
        return NULL;
    }

    if (!SDL_UpdateTexture(texture, NULL, img->pixels, (int)img->dims.width * 3))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_UpdateTexture %s", SDL_GetError());
        SDL_DestroyTexture(texture);
        return NULL;
    }

    return texture;
}

void render_image(SDL_Renderer *ren, SDL_Texture *texture)
{
    if (texture == NULL)
    {
        return;
    }

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
    SDL_RenderTexture(ren, texture, NULL, NULL);
    SDL_RenderPresent(ren);
}

void render_image_destroy(SDL_Texture *texture)
{
    SDL_DestroyTexture(texture);
}
