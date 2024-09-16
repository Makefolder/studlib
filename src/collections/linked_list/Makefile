all:
	@clear
	cc -Wall -Werror -O0 -Wextra -pedantic -std=c99 -g linked_list.c -o test.a

leaks: clean all
	@leaks --atExit -- ./test.a

clean:
	@rm -rf test.a.dSYM
	@rm test.a

rebuild: clean all

.PHONY: all clean
