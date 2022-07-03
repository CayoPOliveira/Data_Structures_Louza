CFLAGS= -Wall -Werror

LIB = 	\
		BinTree_TAD.o\


MAIN_FILE = ed04

all: $(MAIN_FILE)

$(MAIN_FILE): $(MAIN_FILE).c $(LIB)
	gcc $^ $(CFLAGS) -o $@

#regra genérica
%TAD.o: %TAD.c %TAD.h
	gcc $(CFLAGS) -c $<

clean:
	rm -rf *.o $(MAIN_FILE) ./out/*.o

valgrind: $(MAIN_FILE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MAIN_FILE) < in/test_0.in > out/test_0.out
valgrind1: $(MAIN_FILE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MAIN_FILE) < in/test_1.in > out/test_1.out
