CFLAGS= -Wall -Werror

all: exemplo1

exemplo1: exemplo1.c lista_com_cabeca.o
	gcc $^ -o $@

exemplo2: exemplo2.c lista_com_cabeca.o
	gcc $^ -o $@

exemplo3: exemplo3.c lista_com_cabeca.o
	gcc $^ -o $@

#regra genérica
%.o: %.c %.h
	gcc $(CFLAGS) -c $<

clean:
	rm -rf *.o exemplo1 exemplo2 exemplo3
