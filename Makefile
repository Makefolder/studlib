CC=cc
CFLAGS=-g -O0 -Wall -Werror -Wextra -pedantic -std=c99
LIBNAME=studlib
LIBFILE=lib$(LIBNAME).a

HEADERS=$(shell find src -name '*.h')
SRCS=$(shell find src -name '*.c')
OBJS=$(SRCS:src/%.c=build/obj/%.o)

all: $(LIBFILE)

$(LIBFILE): $(OBJS)
	@echo "Assembling library..."
	ar rcs ./build/lib/$@ $(OBJS)
	cp -r $(HEADERS) ./build/include/

build/obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $< to $@"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf ./build/lib/*
	@rm -rf ./build/include/*
	@rm -rf ./build/obj/*

rebuild: clean all

.PHONY: all clean
