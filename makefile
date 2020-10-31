all: construction.o main.o
	gcc -o construction main.o construction.o

main.o: main.c
	gcc -c main.c

construction.o: construction.c construction.h
	gcc -c construction.c

run: 
	./construction

clear:
	rm *.o
	rm construction 