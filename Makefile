# Compilador e flags
CC      := gcc
CFLAGS  := -Wall -Wextra -std=c17 $(shell pkg-config --cflags sdl3)
LDFLAGS := $(shell pkg-config --libs sdl3)

# Alvos e objetos
BUILD_DIR := build
TARGET    := $(BUILD_DIR)/image-viewer

SRCS := main.c window/window.c render/render.c
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

# Regra principal
all: $(TARGET)

# Linka os objetos no executavel final
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

# Compila cada .c para build/<caminho>/<nome>.o
# mkdir -p garante que build/window/ exista antes do GCC escrever o .o/.d
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Limpa tudo que foi gerado
clean:
	rm -rf $(BUILD_DIR)

# Compila (se preciso) e roda
run: all
	./$(TARGET)

.PHONY: all clean run

# Dependencias automaticas (headers que cada .o inclui)
-include $(DEPS)