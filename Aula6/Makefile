CFLAGS = -Wall -Werror

all: exemplo1

exemplo1: exemplo1.c ArvoreBinaria.o
	gcc $^ -o $@


#regra genérica
%.o: %.c %.h
	gcc $(CFLAGS) -c $<

clean:
	rm -rf *.o exemplo1

valgrind1: exemplo1
	valgrind --leak-check=yes ./exemplo1

