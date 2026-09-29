cmake_minimum_required(VERSION 4.3)
project(image_viewer C)

set(CMAKE_C_STANDARD 17)

add_executable(image_viewer main.c
        window/window.c
        window/window.h
        render/render.c
        render/render.h
        decoder/image/ppm_decoder.c
        decoder/image/ppm_decoder.h
)
