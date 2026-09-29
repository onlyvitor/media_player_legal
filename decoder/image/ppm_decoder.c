//
// Created by vitor on 28/09/2026.
//

#include "ppm_decoder.h"

// TODO: finilize this shit
ppm_decoded_t *ppm_decode(const char *file)
{
    // ppm image decoded
    char buff[16];
    ppm_decoded_t *decoded = NULL;
    // commentaries in the ppm file and the rgb max
    uint16_t commentary, max_rgb;
    // declare one pointer to the FILE opened
    FILE *fp = fopen(file, "r");
    // check if the file exists
    if (!fp)
    {
        printf("ppm_decoded_t: could not open file %s\n", file);
        return NULL;
    }
    // read the image format is correct
    if (!fgets(buff, sizeof(buff), fp))
    {
        perror(file);
        return NULL;
    }
}
