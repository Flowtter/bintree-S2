CC := gcc

CPPFLAGS := `pkg-config --cflags sdl` -Iinclude/
CFLAGS := -Wall -Wextra -Werror -std=c99 -O3

DBGCFLAGS := $(CFLAGS)

S_DIR := src
S_DIR_TEST := test

S_FILES := $(wildcard $(S_DIR)/*.c)
S_FILES_TEST := $(wildcard $(S_DIR_TEST)/*.c)
H_FILES_TEST := $(wildcard $(S_DIR_TEST)/*.h)

all:
	$(CC) $(S_FILES) -o bintree $(DBGCFLAGS) $(CPPFLAGS)

.PHONY: all format test

test:
	$(CC) $(S_FILES) $(S_FILES_TEST) $(H_FILES_TEST) -o bintreetest $(DBGCFLAGS) $(CPPFLAGS)

format: src/*.c include/*.h test/*.c test/*.h
	@clang-format --style=file -i $^
