//
// Created by vitor on 28/09/2026.
//

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "app.h"

App::App(const std::string &path)
    : image_(image::Decoder().decode(path)),
      window_(),
      renderer_(window_.get()),
      texture_(renderer_, image_) {
  // check if SDL is loaded, it must outlive renderer_ and window_
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    throw std::runtime_error(std::string("SDL_Init ") + SDL_GetError());
  }
}

App::~App() {
  // members are destroyed first by their own destructors, then undo SDL_Init
  SDL_Quit();
}

int App::run() {
  const auto &dims = image_.dims();
  printf("dimensions : %ux%u\n", static_cast<unsigned>(dims.width),
         static_cast<unsigned>(dims.height));
  printf("pixels     : %zu\n", image_.pixel_count());
  const image::Pixel &first = image_.pixels()[0];
  printf("first pixel: (%u, %u, %u)\n", first.r, first.g, first.b);

  bool running = true;

  // event loop
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      // if the close button of the window is pressed, the loop stops
      if (event.type == SDL_EVENT_QUIT ||
          event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
        running = false;
      }
    }

    renderer_.draw(texture_);

    // keeps the loop from burning the cpu while idle
    SDL_Delay(16);
  }

  return 0;
}
