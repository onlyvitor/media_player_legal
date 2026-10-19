# image-viewer

![demo](https://c.tenor.com/t5XC2aARCf0AAAAC/tenor.gif)

Um vizualizador de imagens extremamente simples para me divertir :)
Tem como objetivo ser um media player geral para uso geral, isto é, tocar músicas, vídeos e mostrar imagens. Utilizar ffmpeg para decodificar arquivos mais complexos e decodificar arquivos mais simples.

## Status atual

Basicamante so consegue mostar uma cor solida :3

Reescrito em **C++ (C17 → C++17)** com programação orientada a objetos.

## Dependências

- Compilador **C++** com suporte a **C++17** (GCC ou Clang)
- **SDL3** (via pkg-config: `pkg-config --cflags sdl3`)
- **Make** e **pkg-config**

## Compilando e rodando

```sh
make run
```

Para compilar sem rodar:

```sh
make
```

Para limpar os artefatos de build:

```sh
make clean
```

## Estrutura do projeto

```
├── main.cxx           # Ponto de entrada
├── app.h/.cxx         # App: compõe o decodificador, janela, renderer e textura (RAII)
├── decoder            # Decoder
│    └──image          # Decoder de Imagens (image::Decoder, image::Image)
├── window/            # Criação e gerenciamento da janela (window::Window, SDL3)
├── render/            # Renderer (render::Renderer) e textura (render::Texture)
└── build/             # Artefatos gerados pelo Makefile
```
