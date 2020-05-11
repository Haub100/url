CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wvla -Wextra -Wpedantic -Wwrite-strings -Wstack-usage=512

SOURCES=PokeURL.c
BINARY=$(patsubst %.c,%,$(SOURCES))

BIN=./bin/
SRC=./src/
RSRC:=./resource/

all: $(BIN)

$(BIN): build $(SRC)$(SOURCES)
	$(CC) $(SRC)$(SOURCES) -o $@$(BINARY) 

build:
	@mkdir -p bin

.PHONY: clean
clean:
	rm -rf $(BIN)