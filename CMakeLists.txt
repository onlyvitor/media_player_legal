cmake_minimum_required(VERSION 3.20)
project(image_viewer C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG)

add_executable(image_viewer
        main.c
        window/window.c
        window/window.h
        render/render.c
        render/render.h
        render/image/render_ppm_image.c
        render/image/render_ppm_image.h
        decoder/image/ppm_decoder.c
        decoder/image/ppm_decoder.h
)

target_link_libraries(image_viewer PRIVATE SDL3::SDL3)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(image_viewer PRIVATE -Wall -Wextra)
endif()
