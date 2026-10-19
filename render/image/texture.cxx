//
// Created by vitor on 08/10/2026.
//

#include <stdexcept>

#include "texture.h"
#include "../renderer.h"

namespace render {

Texture::Texture(const Renderer &renderer, const image::Image &img) {
  const auto &dims = img.dims();

  texture_ = SDL_CreateTexture(
      renderer.get(),
      SDL_PIXELFORMAT_RGB24,
      SDL_TEXTUREACCESS_STATIC,
      static_cast<int>(dims.width),
      static_cast<int>(dims.height));

  if (texture_ == nullptr) {
    throw std::runtime_error(std::string("SDL_CreateTexture ") + SDL_GetError());
  }

  if (!SDL_UpdateTexture(texture_, nullptr, img.pixels().data(),
                         static_cast<int>(dims.width) * 3)) {
    SDL_DestroyTexture(texture_);
    texture_ = nullptr;
    throw std::runtime_error(std::string("SDL_UpdateTexture ") + SDL_GetError());
  }
}

Texture::~Texture() {
  SDL_DestroyTexture(texture_);
}

}  // namespace render
