//
// Created by vitor on 27/09/2026.
//

#include <stdexcept>

#include "renderer.h"

namespace render {

Renderer::Renderer(SDL_Window *window) {
  // create a renderer, check if it is created successfully
  renderer_ = SDL_CreateRenderer(window, nullptr);
  if (renderer_ == nullptr) {
    throw std::runtime_error(std::string("SDL_CreateRenderer ") + SDL_GetError());
  }
}

Renderer::~Renderer() {
  // destroy the renderer
  SDL_DestroyRenderer(renderer_);
}

}  // namespace render
