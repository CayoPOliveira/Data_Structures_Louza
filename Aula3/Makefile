CFLAGS= -Wall -Werror
all: exemplo1

exemplo1: exemplo1.c lista_circular.o
	gcc $^ -o $@

exemplo2: exemplo2.c lista_duplamente_ligada.o
	gcc $^ -o $@

#regra genérica
%.o: %.c %.h
	gcc $(CFLAGS) -c $<

clean:
	rm -rf *.o exemplo1 exemplo2

valgrind1: exemplo1
	valgrind --leak-check=yes ./exemplo1

valgrind2: exemplo2
	valgrind --leak-check=yes ./exemplo2