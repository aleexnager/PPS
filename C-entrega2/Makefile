CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -ansi

all: maxmin main matrizdinamica

maxmin: maxmin.c
	$(CC) $(CFLAGS) -o maxmin maxmin.c

main: main.o parser.o
	$(CC) $(CFLAGS) -o main main.o parser.o

main.o: main.c parser.h
	$(CC) $(CFLAGS) -c main.c

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

matrizdinamica: matrizdinamica.c
	$(CC) $(CFLAGS) -o matrizdinamica matrizdinamica.c