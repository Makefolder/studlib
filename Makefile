CC=cc
CFLAGS=-g -Wall -Werror -Wextra -pedantic -std=c99

all:
	$(CC) $(CFLAGS) ./src/linked_list.c -o ./build/lib/linked_list.a

clean:
	@rm -rf ./build/lib/*
	@rm -rf ./build/include/*

debug:
	@$(CC) $(CFLAGS) -fsanitize=address ./src/linked_list.c -o ./build/lib/linked_list.a
	@./build/lib/linked_list.a

.PHONY: all clean
