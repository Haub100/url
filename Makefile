CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wvla -Wextra -Wpedantic -Wwrite-strings -Wstack-usage=512

PROGRAM=PokeURL
SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

BIN=./bin/

all: $(BIN)

$(BIN): build $(OBJECTS)
	$(CC) -o $@$(PROGRAM) $(OBJECTS)

build:
	@mkdir -p bin

.PHONY: clean
clean:
	rm -rf $(BIN) $(OBJECTS)