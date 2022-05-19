CFLAGS= -Wall -Werror

LIB = 	\
		ListaLigadaTAD.o\

MAIN_FILE = ed01

all: $(MAIN_FILE)

$(MAIN_FILE): $(MAIN_FILE).c $(LIB)
	gcc $^ -o $@

#regra genérica
%.o: %.c %.h
	gcc $(CFLAGS) -c $<

clean:
	rm -rf *.o $(MAIN_FILE) *.out

valgrind: $(MAIN_FILE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MAIN_FILE) < in/ed01_test_0.in > out/ed01_test_0.out
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MAIN_FILE) < in/ed01_test_1.in > out/ed01_test_1.out
