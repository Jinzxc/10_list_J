all: main.o linked_night.o
	gcc -o main main.o linked_night.o

main.o: main.c linked_night.h
	gcc -c main.c

night.o: linked_night.c linked_night.h
	gcc -c night.c

run:
	./main

clean:
	rm *.o