CFLAG= -Wall -Wextra -ansi -pedantic -O2

bn: fase1.o fase2.o
	gcc -o bn fase1.o fase2.o $(CFLAG)


fase1.o: fase1.c header.h
	gcc -c fase1.c

fase2.o: fase2.c header.h
	gcc -c fase2.c
