CC=gcc
saper: main.o ruchy.o generator_min.o struktury.o wypisywanie.o tabela.o
	$(CC) main.o ruchy.o generator_min.o struktury.o wypisywanie.o tabela.o -o saper

main.o: ruchy.o generator_min.o struktury.o wypisywanie.o tabela.o main.c

	$(CC) -c main.c

generator_min.o: generator_min.c generator_min.h struktury.o
	$(CC) -c generator_min.c

ruchy.o: ruchy.c ruchy.h struktury.o generator_min.o wypisywanie.o 
	$(CC) -c ruchy.c

wypisywanie.o: wypisywanie.c wypisywanie.h struktury.o
	$(CC) -c wypisywanie.c

struktury.o: struktury.c struktury.h
	$(CC) -c struktury.c

tabela.o: tabela.c tabela.h
	$(CC) -c tabela.c

clean:
	rm *.o saper
