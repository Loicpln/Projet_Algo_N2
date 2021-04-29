run: main
	rm *.o
	@./main

main: main.o sous_traitance.o ./tpGfx/libisentlib.a
	gcc -Wall main.o sous_traitance.o -o main ./tpGfx/libisentlib.a -lm -lglut -lGL -lX11

main.o: main.c 
	gcc -g -Wall -c main.c

sous_traitance.o: sous_traitance.c 
	gcc -g -Wall -c sous_traitance.c
