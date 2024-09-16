CC=cc
CFLAGS=-g -Wall -Werror -Wextra -pedantic -std=c99
COLLECTIONS=./src/collections
ALGORITHMS=./src/algs

all:
	$(CC) $(CFLAGS) ./src/linked_list.c -o ./build/lib/linked_list.a

clean:
	@rm -rf ./build/lib/*
	@rm -rf ./build/include/*

debug:
	@$(CC) $(CFLAGS) -fsanitize=address $(COLLECTIONS)/linked_list/linked_list.c -o ./build/lib/linked_list.a
	@./build/lib/linked_list.a

.PHONY: all clean
