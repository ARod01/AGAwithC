CC = gcc
OBJECTS = functions.o
aga : main.o $(OBJECTS)
	$(CC) -o AGAwithC main.o $(OBJECTS) -lm
main.o : main.c librery.h
	$(CC) -c main.c
functions.o : functions.c librery.h
	$(CC) -c functions.c