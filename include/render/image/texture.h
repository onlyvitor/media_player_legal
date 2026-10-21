//
// Created by vitor on 08/10/2026.
//

#ifndef RENDER_IMAGE_TEXTURE_H
#define RENDER_IMAGE_TEXTURE_H

#include <SDL3/SDL.h>

namespace image {
class Image;
}

namespace render {

class Renderer;

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

#endif  // RENDER_IMAGE_TEXTURE_H
