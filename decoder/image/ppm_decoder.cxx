//
// Created by vitor on 28/09/2026.
//

#include <cctype>
#include <cstdint>
#include <fstream>
#include <new>
#include <string>
#include <utility>

#include "decoder/image/ppm_decoder.h"

namespace image {

uint32_t Decoder::read_uint(std::istream &stream, const std::string &file) {
  int c;
  uint32_t parsed = 0;
  for (;;) {
    c = stream.get();
    if (c == std::char_traits<char>::eof()) {
      throw DecodeError("invalid image size (error loading '" + file + "')");
    }
    if (c == '#') {
      while ((c = stream.get()) != std::char_traits<char>::eof() && c != '\n') {
      }
      continue;
    }
    if (!isspace(static_cast<unsigned char>(c))) {
      break;
    }
  }
  if (!isdigit(static_cast<unsigned char>(c))) {
    throw DecodeError("invalid image size (error loading '" + file + "')");
  }
  do {
    if (parsed > (UINT32_MAX - 9u) / 10u) {
      throw DecodeError("value too large (error loading '" + file + "')");
    }
    parsed = parsed * 10u + static_cast<uint32_t>(c - '0');
    c = stream.get();
  } while (c != std::char_traits<char>::eof() &&
           isdigit(static_cast<unsigned char>(c)));
  if (c != std::char_traits<char>::eof() &&
      !isspace(static_cast<unsigned char>(c))) {
    throw DecodeError("invalid image size (error loading '" + file + "')");
  }
  return parsed;
}

Image Decoder::decode(const std::string &file) {
  // "rb" keeps binary pixel data intact; std::ios::binary does the same here
  std::ifstream fp(file, std::ios::binary);
  // check if the file exists
  if (!fp) {
    throw DecodeError("could not open file " + file);
  }
  // ppm magic number ("P6")
  char magic[2];
  // check if is a .ppm file
  if (!fp.read(magic, sizeof(magic)) || magic[0] != 'P' || magic[1] != '6') {
    throw DecodeError("not a PPM file");
  }

  // width, height and the rgb max value from the header
  // (comments are skipped inside read_uint)
  const uint32_t width = read_uint(fp, file);
  const uint32_t height = read_uint(fp, file);
  if (width == 0 || height == 0) {
    throw DecodeError("empty image dimensions " + std::to_string(width) + "x" +
                      std::to_string(height) + " (error loading '" + file + "')");
  }

  // each component is stored in one byte, so maxval must fit in 8 bits
  const uint32_t max_rgb = read_uint(fp, file);
  if (max_rgb == 0 || max_rgb > 255) {
    throw DecodeError("unsupported maxval " + std::to_string(max_rgb) +
                      ", only 8-bit ppm is supported (error loading '" + file +
                      "')");
  }

  std::vector<Pixel> pixels;
  try {
    pixels.resize(static_cast<size_t>(width) * static_cast<size_t>(height));
  } catch (const std::bad_alloc &) {
    throw DecodeError("image too large to allocate " + std::to_string(width) +
                      "x" + std::to_string(height) + " (error loading '" + file +
                      "')");
  }

  // read pixel data from file
  if (!fp.read(reinterpret_cast<char *>(pixels.data()),
               static_cast<std::streamsize>(pixels.size() * sizeof(Pixel)))) {
    throw DecodeError("error loading image '" + file + "'");
  }

  return Image(Dims{width, height}, std::move(pixels));
}

}  // namespace image
