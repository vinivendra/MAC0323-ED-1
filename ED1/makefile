EP1: main.o Pontos.o
	gcc main.o Pontos.o -g -o ep1 -lm

main.o: main.c
	gcc -c main.c -g -ansi -pedantic -Wall

Pontos.o: Pontos.c
	gcc -c Pontos.c -g -ansi -pedantic -Wall

clean:
	rm -f *.o
