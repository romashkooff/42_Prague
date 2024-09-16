# Compiler options.
CC = gcc
CFLAGS = -O2 -Wall -Wextra -Wsign-conversion -pedantic -std=c89

# Source files.
SRC_FILES = $(wildcard *.c)

# Object files.
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))

# Dependency files.
DEP_FILES = $(patsubst %.c,%.d,$(SRC_FILES))

# Name of the resulting binary file.
BIN = a.out

# Targets.
all: $(BIN)

$(BIN): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP_FILES)

.PHONY: run
run: all
	./$(BIN)

.PHONY: clean
clean:
	rm -rf $(BIN) $(OBJ_FILES) $(DEP_FILES)

.PHONY: rebuild
rebuild: clean all
