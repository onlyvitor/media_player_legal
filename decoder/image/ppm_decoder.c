//
// Created by vitor on 28/09/2026.
//

#include "ppm_decoder.h"

// TODO: finilize this shit
ppm_decoded_t *ppm_decode(const char *file) {
  // ppm image decoded
  char buff[16];
  ppm_decoded_t *decoded = NULL;
  ppm_decoded_t *img;
  // commentaries in the ppm file and the rgb max
  uint16_t commentary, max_rgb;
  // declare one pointer to the FILE opened
  FILE *fp = fopen(file, "r");
  // check if the file exists
  if (!fp) {
    printf("ppm_decoded_t: could not open file %s\n", file);
    return NULL;
  }
  // check if is a .ppm file
  if (buff[0] != 'P' || buff[1] != '6') {
    printf("ppm_decoded_t: not a PPM file\n");
  }
  // allocate the image for the heap
  img = (ppm_decoded_t *)malloc(sizeof(ppm_decoded_t));
  if (!img) {
    printf("ppm_decoded_t: unable to alocate the image to heap");
  }
  
  //check the commmentaries anmd remove them
  commentary = getc(fp);
  while (commentary == '#') {
    while (getc(fp) != '\n');
    commentary = getc(fp);
  }

  // read image size information
  if (fscanf(fp, "%d %d", &img->dims.width, &img->dims.height) != 2) {
    fprintf(stderr, "Invalid image size (error loading '%s')\n", file);
    exit(1);
  }

  // read rgb component
  if (fscanf(fp, "%d", &max_rgb) != 1) {
    fprintf(stderr, "Invalid rgb component (error loading '%s')\n", file);
    exit(1);
  }

  while (fgetc(fp) != '\n')
    ;
  // memory allocation for pixel data
  img->pixels = (ppm_pixel_t *)malloc(img->dims.width * img->dims.height * sizeof(ppm_pixel_t));

  if (!img) {
    fprintf(stderr, "Unable to allocate memory\n");
    exit(1);
  }

  // read pixel data from file
  if (fread(img->pixels, 3 * img->dims.width, img->dims.height, fp) != img->dims.width){
    fprintf(stderr, "Error loading image '%s'\n", file);
    exit(1);
  }

  fclose(fp);
  return img;
}
