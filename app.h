//
// Created by vitor on 28/09/2026.
//

#ifndef IMAGE_VIEWER_APP_H
#define IMAGE_VIEWER_APP_H

#include <decoder/image/ppm_decoder.h>
#include <render/renderer.h>
#include <render/image/texture.h>
#include <window/window.h>

/// Composes every component of the viewer and owns its lifetime.
/// Uses RAII: the constructor sets SDL up and destroys it on destruction.
class App {
 public:
  /// Loads the ppm image and creates the window, renderer and texture.
  /// Throws std::runtime_error when any step fails.
  explicit App(const std::string &path);

  App(const App &) = delete;
  App &operator=(const App &) = delete;

  ~App();

  /// Runs the event loop until the window is closed.
  /// Returns 0 on success, 1 on failure.
  int run();

 private:
  image::Image image_;
  Window window_;
  render::Renderer renderer_;
  render::Texture texture_;
};

#endif  // IMAGE_VIEWER_APP_H
