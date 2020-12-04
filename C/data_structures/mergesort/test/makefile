all: main

main: main.o array.o mergesort.o
	gcc main.o array.o mergesort.o -o main

main.o: main.c
	gcc -o main.o -c main.c

array.o: array.c array.h
	gcc -o array.o -c array.c

mergesort.o: mergesort.c mergesort.h
	gcc -o mergesort.o -c mergesort.c

clean:
	rm *.o main *.txt
