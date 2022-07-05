CFLAGS = -Wall -Werror
#CFLAGS += -O2 -g #valgrind

all: exemplo1

exemplo%: exemplo%.c ABB.o
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
