# image-viewer

![demo](https://c.tenor.com/t5XC2aARCf0AAAAC/tenor.gif)

Um vizualizador de imagens extremamente simples para me divertir :)
Tem como objetivo ser um media player geral para uso geral, isto é, tocar músicas, vídeos e mostrar imagens. Utilizar ffmpeg para decodificar arquivos mais complexos e decodificar arquivos mais simples.

## Status atual

Basicamante so consegue mostar uma cor solida :3

## Dependências

- Compilador C com suporte a **C17** (GCC ou Clang)
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
├── main.c           # Ponto de entrada
├── decoder          # Decoder
├    └──image        # Decoder de Imagens
├── window/          # Criação e gerenciamento da janela (SDL3)
├── render/          # Renderer (SDL_Renderer) e desenho
└── build/           # Artefatos gerados pelo Makefile
```
