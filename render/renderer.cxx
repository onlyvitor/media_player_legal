//
// Created by vitor on 27/09/2026.
//

#include <stdexcept>
#include <string>

#include "render/renderer.h"
#include "render/image/texture.h"

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

void Renderer::draw(const Texture &texture) {
  // fill and present the frame
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
  SDL_RenderClear(renderer_);
  if (texture.get() != nullptr) {
    SDL_RenderTexture(renderer_, texture.get(), nullptr, nullptr);
  }
  SDL_RenderPresent(renderer_);
}

}  // namespace render
