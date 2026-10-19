cmake_minimum_required(VERSION 3.20)
project(image_viewer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL3 REQUIRED CONFIG)

add_executable(image_viewer
        main.cxx
        window/window.cxx
        window/window.h
        render/renderer.cxx
        render/renderer.h
        render/image/texture.cxx
        render/image/texture.h
        decoder/image/ppm_decoder.cxx
        decoder/image/ppm_decoder.h
)

target_link_libraries(image_viewer PRIVATE SDL3::SDL3)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(image_viewer PRIVATE -Wall -Wextra)
endif()
