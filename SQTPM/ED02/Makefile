CFLAGS= -Wall -Werror

LIB = 	\
		LLCircularTAD.o\
		FilaTAD.o\


MAIN_FILE = ed02

all: $(MAIN_FILE)

$(MAIN_FILE): $(MAIN_FILE).c $(LIB)
	gcc $^ $(CFLAGS) -o $@

#regra genérica
%TAD.o: %TAD.c %TAD.h
	gcc $(CFLAGS) -c $<

clean:
	rm -rf *.o $(MAIN_FILE) ./out/*.o

valgrind: $(MAIN_FILE)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MAIN_FILE) < in/$(MAIN_FILE)_test_0.in > out/$(MAIN_FILE)_test_0.out
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(MAIN_FILE) < in/$(MAIN_FILE)_test_1.in > out/$(MAIN_FILE)_test_1.out
