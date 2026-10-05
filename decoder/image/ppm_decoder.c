//
// Created by vitor on 28/09/2026.
//

#include <ctype.h>

#include "ppm_decoder.h"

// skips whitespace and '#' comments, reads one unsigned integer and
// consumes the single whitespace character that follows it
static int ppm_read_uint(FILE *fp, unsigned int *value) {
  int c;
  unsigned int parsed = 0;
  for (;;) {
    c = fgetc(fp);
    if (c == EOF) {
      return 0;
    }
    if (c == '#') {
      while ((c = fgetc(fp)) != EOF && c != '\n')
        ;
      continue;
    }
    if (!isspace((unsigned char)c)) {
      break;
    }
  }
  if (!isdigit((unsigned char)c)) {
    return 0;
  }
  do {
    if (parsed > (UINT32_MAX - 9u) / 10u) {
      return 0;
    }
    parsed = parsed * 10u + (unsigned int)(c - '0');
    c = fgetc(fp);
  } while (c != EOF && isdigit((unsigned char)c));
  if (c != EOF && !isspace((unsigned char)c)) {
    return 0;
  }
  *value = parsed;
  return 1;
}

ppm_decoded_t *ppm_decode(const char *file) {
  // ppm magic number ("P6")
  char magic[2];
  ppm_decoded_t *img;
  // width, height and the rgb max value from the header
  unsigned int width, height, max_rgb;
  // declare one pointer to the FILE opened ("rb" keeps binary pixel data intact)
  FILE *fp = fopen(file, "rb");
  // check if the file exists
  if (!fp) {
    fprintf(stderr, "ppm_decode: could not open file %s\n", file);
    return NULL;
  }
  // check if is a .ppm file
  if (fread(magic, sizeof(magic), 1, fp) != 1 || magic[0] != 'P' || magic[1] != '6') {
    fprintf(stderr, "ppm_decode: not a PPM file\n");
    fclose(fp);
    return NULL;
  }
  // allocate the image for the heap
  img = (ppm_decoded_t *)malloc(sizeof(ppm_decoded_t));
  if (!img) {
    fprintf(stderr, "ppm_decode: unable to allocate the image to heap\n");
    fclose(fp);
    return NULL;
  }

  // read image size information (comments are skipped inside ppm_read_uint)
  if (!ppm_read_uint(fp, &width) || !ppm_read_uint(fp, &height)) {
    fprintf(stderr, "ppm_decode: invalid image size (error loading '%s')\n", file);
    free(img);
    fclose(fp);
    return NULL;
  }
  if (width == 0 || height == 0) {
    fprintf(stderr, "ppm_decode: empty image dimensions %ux%u (error loading '%s')\n", width, height, file);
    free(img);
    fclose(fp);
    return NULL;
  }
  img->dims.width = width;
  img->dims.height = height;

  // read rgb component; ppm_read_uint consumes the single whitespace
  // that separates the header from the binary pixel data
  if (!ppm_read_uint(fp, &max_rgb)) {
    fprintf(stderr, "ppm_decode: invalid rgb component (error loading '%s')\n", file);
    free(img);
    fclose(fp);
    return NULL;
  }
  // each component is stored in one byte, so maxval must fit in 8 bits
  if (max_rgb == 0 || max_rgb > 255) {
    fprintf(stderr, "ppm_decode: unsupported maxval %u, only 8-bit ppm is supported (error loading '%s')\n", max_rgb, file);
    free(img);
    fclose(fp);
    return NULL;
  }
  // memory allocation for pixel data (guard against size_t overflow)
  if (width > SIZE_MAX / sizeof(ppm_pixel_t) / height) {
    fprintf(stderr, "ppm_decode: image too large to allocate %ux%u (error loading '%s')\n", width, height, file);
    free(img);
    fclose(fp);
    return NULL;
  }
  size_t pixel_count = (size_t)width * (size_t)height;
  img->pixels = (ppm_pixel_t *)malloc(pixel_count * sizeof(ppm_pixel_t));

  if (!img->pixels) {
    fprintf(stderr, "ppm_decode: unable to allocate memory\n");
    free(img);
    fclose(fp);
    return NULL;
  }

  // read pixel data from file
  if (fread(img->pixels, sizeof(ppm_pixel_t), pixel_count, fp) != pixel_count) {
    fprintf(stderr, "ppm_decode: error loading image '%s'\n", file);
    free(img->pixels);
    free(img);
    fclose(fp);
    return NULL;
  }

  fclose(fp);
  return img;
}
