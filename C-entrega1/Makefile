CFLAGS=gcc -Wall -Wextra -Werror -ansi -pedantic

all: invertir multiplicar mainEc2g

invertir: invertir.c
	$(CFLAGS) -o invertir invertir.c

multiplicar: multiplicar.c
	$(CFLAGS) -o multiplicar multiplicar.c

mainEc2g: mainEc2g.o ec2g.o
	$(CFLAGS) -o mainEc2g mainEc2g.o ec2g.o -lm

mainEc2g.o: mainEc2g.c ec2g.h
	$(CFLAGS) -c mainEc2g.c

ec2g.o: ec2g.c ec2g.h
	$(CFLAGS) -c ec2g.c
