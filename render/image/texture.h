//
// Created by vitor on 08/10/2026.
//

#ifndef RENDER_PPM_IMAGE
#define RENDER_PPM_IMAGE

#include <SDL3/SDL.h>

#include "../../decoder/image/ppm_decoder.h"

namespace render {

/// Owns a static SDL_Texture holding the decoded PPM pixels.
/// The texture is uploaded once in the constructor and reused every frame.
class Texture {
 public:
  /// Uploads the image pixels to the gpu as a RGB24 static texture.
  /// Throws std::runtime_error when creation or upload fails.
  Texture(const Renderer &renderer, const image::Image &img);

  Texture(const Texture &) = delete;
  Texture &operator=(const Texture &) = delete;

  ~Texture();

  SDL_Texture *get() const { return texture_; }

 private:
  SDL_Texture *texture_ = nullptr;
};

}  // namespace render

#endif  // RENDER_PPM_IMAGE
