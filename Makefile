CC      = gcc
CFLAGS  = -Wall -Wextra -std=c17
LDFLAGS =

BUILD_DIR = build
TARGET    = $(BUILD_DIR)/image-viewer

SRCS = $(wildcard *.c src/*.c window/*.c)
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)

run:
	./$(TARGET)

.PHONY: all clean