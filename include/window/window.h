//
// Created by vitor on 26/09/2026.
//

#ifndef IMAGE_VIEWER_WINDOW_H
#define IMAGE_VIEWER_WINDOW_H

#include <SDL3/SDL.h>

namespace window {

/// Creates and owns the SDL_Window for the image viewer.
/// The window is created in the constructor and destroyed on destruction.
class Window {
 public:
  /// Creates a 640x480 "Cool Image Viewer" window.
  /// Throws std::runtime_error when SDL fails to create it.
  Window();

  Window(const Window &) = delete;
  Window &operator=(const Window &) = delete;

  ~Window();

  SDL_Window *get() const { return window_; }

 private:
  SDL_Window *window_ = nullptr;
};

}  // namespace window

#endif  // IMAGE_VIEWER_WINDOW_H
