# image-viewer

![demo](https://c.tenor.com/t5XC2aARCf0AAAAC/tenor.gif)

Um visualizador de imagens escrito em C com SDL3 — e um projeto que **almeja** se tornar um media player completo de imagens, vídeos e músicas.

## Visão

O objetivo a longo prazo é evoluir de um simples visualizador de imagens para um media player completo:

- **Imagens** — visualização, zoom, rotação e navegação entre arquivos (foco atual)
- **Vídeos** — playback de vídeos com controles básicos (planejado)
- **Músicas** — playback de áudio com playlist e controles de mídia (planejado)

## Status atual

- [x] Abertura de janela com SDL3
- [x] Renderização de cor sólida
- [ ] Exibição de imagens
- [ ] Player de vídeos
- [ ] Player de músicas

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
├── window/          # Criação e gerenciamento da janela (SDL3)
├── render/          # Renderer (SDL_Renderer) e desenho
└── build/           # Artefatos gerados pelo Makefile
```
