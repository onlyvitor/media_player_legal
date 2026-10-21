# Compilador e flags
CXX      := g++
CXXFLAGS := -Wall -Wextra -std=c++20 -Iinclude $(shell pkg-config --cflags sdl3)
LDFLAGS  := $(shell pkg-config --libs sdl3)

# Alvos e objetos
BUILD_DIR := build
TARGET    := $(BUILD_DIR)/image-viewer

SRCS := main.cxx app.cxx window/window.cxx render/renderer.cxx render/image/texture.cxx decoder/image/ppm_decoder.cxx
OBJS := $(SRCS:%.cxx=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

# Regra principal
all: $(TARGET)

# Linka os objetos no executavel final
$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

# Compila cada .cxx para build/<caminho>/<nome>.o
# mkdir -p garante que build/window/ exista antes do G++ escrever o .o/.d
$(BUILD_DIR)/%.o: %.cxx
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Limpa tudo que foi gerado
clean:
	rm -rf $(BUILD_DIR)

# Compila (se preciso) e roda
run: all
	./$(TARGET)

.PHONY: all clean run

# Dependencias automaticas (headers que cada .o inclui)
-include $(DEPS)
