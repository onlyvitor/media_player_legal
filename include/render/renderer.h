//
// Created by vitor on 27/09/2026.
//

#ifndef IMAGE_VIEWER_RENDER_DRAW_H
#define IMAGE_VIEWER_RENDER_DRAW_H

#include <SDL3/SDL.h>

namespace render {

class Texture;

/// Owns an SDL_Renderer for one SDL_Window.
/// The renderer is created in the constructor and destroyed on destruction.
class Renderer {
 public:
  /// Creates a renderer for the given window.
  /// Throws std::runtime_error when SDL fails to create it.
  explicit Renderer(SDL_Window *window);

  Renderer(const Renderer &) = delete;
  Renderer &operator=(const Renderer &) = delete;

  ~Renderer();

  /// Clears the screen, draws the texture stretched over the whole
  /// window and presents the frame to the screen.
  void draw(const Texture &texture);

  SDL_Renderer *get() const { return renderer_; }

 private:
  SDL_Renderer *renderer_ = nullptr;
};

}  // namespace render

#endif  // IMAGE_VIEWER_RENDER_DRAW_H
