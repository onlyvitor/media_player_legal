//
// Created by vitor on 28/09/2026.
//

#ifndef IMAGE_VIEWER_PPM_DECODER_H
#define IMAGE_VIEWER_PPM_DECODER_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct image {
    uint16_t width;
    uint16_t height;
} image_t;

typedef struct ppm_pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} ppm_pixel_t;

struct ppm_decoded {
    image_t dims;
    ppm_pixel_t pixel;
};

#endif //IMAGE_VIEWER_PPM_DECODER_H
