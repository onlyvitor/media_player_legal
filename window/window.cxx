//
// Created by vitor on 26/09/2026.
//

#include <stdexcept>

#include "window/window.h"

namespace window {

Window::Window() {
  window_ = SDL_CreateWindow("Cool Image Viewer", 640, 480, 0);
  if (window_ == nullptr) {
    throw std::runtime_error(
        std::string("Could not create window: ") + SDL_GetError());
  }
}

Window::~Window() {
  SDL_DestroyWindow(window_);
}

}  // namespace window
