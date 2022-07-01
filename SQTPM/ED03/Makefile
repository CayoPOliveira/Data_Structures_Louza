CFLAGS= -Wall -Werror

LIB = 	\
		ABBTAD.o\


MAIN_FILE = ed03

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
valgrind2: $(MAIN_FILE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MAIN_FILE) < in/test_2.in > out/test_2.out
valgrind3: $(MAIN_FILE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MAIN_FILE) < in/test_3.in > out/test_3.out