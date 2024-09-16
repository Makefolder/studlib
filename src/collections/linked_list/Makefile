all:
	clear
	cc -Wall -Werror -Wextra -pedantic -std=c99 -g -fsanitize=address linked_list.c -o test.out
	@echo ""
	@./test.out
	@echo ""

clean:
	rm -rf test.out.dSYM
	rm test.out

rebuild: clean all

.PHONY: all clean
