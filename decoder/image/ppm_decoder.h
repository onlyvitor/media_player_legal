//
// Created by vitor on 28/09/2026.
//

#ifndef IMAGE_VIEWER_PPM_DECODER_H
#define IMAGE_VIEWER_PPM_DECODER_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct image
{
    uint32_t width;
    uint32_t height;
} image_t;

typedef struct ppm_pixel
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} ppm_pixel_t;

typedef struct ppm_decoded
{
    image_t dims;
    ppm_pixel_t *pixels;
} ppm_decoded_t;

ppm_decoded_t *ppm_decode(const char *file);

#endif // IMAGE_VIEWER_PPM_DECODER_H
