NAME=intel8080
CC=clang
SRCFILES=src/main.c src/cpu.c

$(NAME): $(SRCFILES)
	$(CC) $^ -o $@

.PHONY clean:
	rm $(NAME)
