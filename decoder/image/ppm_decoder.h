//
// Created by vitor on 28/09/2026.
//

#ifndef IMAGE_VIEWER_PPM_DECODER_H
#define IMAGE_VIEWER_PPM_DECODER_H

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

namespace image {

/// Image dimensions, width or height in pixels.
struct Dims {
  uint32_t width = 0;
  uint32_t height = 0;
};

/// One RGB pixel, one byte per channel.
struct Pixel {
  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;
};

/// A decoded PPM image: dimensions plus the pixel buffer.
/// Owns its pixels; moving transfers ownership, copying is disabled.
class Image {
 public:
  Image() = default;
  Image(Dims dims, std::vector<Pixel> pixels)
      : dims_(dims), pixels_(std::move(pixels)) {}

  const Dims &dims() const { return dims_; }
  const std::vector<Pixel> &pixels() const { return pixels_; }
  size_t pixel_count() const {
    return static_cast<size_t>(dims_.width) * static_cast<size_t>(dims_.height);
  }

 private:
  Dims dims_;
  std::vector<Pixel> pixels_;
};

/// Thrown when a PPM file is missing, malformed or unsupported.
class DecodeError : public std::runtime_error {
 public:
  explicit DecodeError(const std::string &message) : std::runtime_error(message) {}
};

/// Decodes binary PPM (P6, 8 bits per channel) files from the disk.
class Decoder {
 public:
  /// Opens the file, parses the header and reads every pixel.
  /// Throws DecodeError when something goes wrong.
  Image decode(const std::string &file);

 private:
  // Skips whitespace and '#' comments, then reads one unsigned integer.
  // Consumes the single whitespace character that follows it.
  uint32_t read_uint(std::istream &stream, const std::string &file);
};

}  // namespace image

#endif  // IMAGE_VIEWER_PPM_DECODER_H
