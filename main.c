#include "window/window.h"
#include "decoder/image/ppm_decoder.h"

int main(void)
{
    ppm_decoded_t *img = ppm_decode("assets/samoel_notisias.ppm");

    if (img == NULL)
    {
        return 1;
    }

    size_t pixel_count = (size_t)img->dims.width * (size_t)img->dims.height;
    printf("dimensions : %ux%u\n", (unsigned)img->dims.width, (unsigned)img->dims.height);
    printf("pixels     : %zu\n", pixel_count);
    printf("first pixel: (%u, %u, %u)\n",
           img->pixels[0].r, img->pixels[0].g, img->pixels[0].b);

    free(img->pixels);
    free(img);
    return window_run();
}
