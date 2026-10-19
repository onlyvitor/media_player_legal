//
// Created by vitor on 28/09/2026.
//

#include <iostream>

#include <app.h>

int main(int argc, char **argv) {
  const std::string path = argc > 1 ? argv[1] : "assets/samoel_notisias.ppm";

  try {
    // everything is set up in one shot, App tears SDL down when it dies
    App app(path);
    return app.run();
  } catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
    return 1;
  }
}
