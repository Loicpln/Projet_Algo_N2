run: main
	rm *.o
	@./main

main: main.o menu.o jeu.o regles.o ./GfxLib/libisentlib.a
	gcc -Wall main.o menu.o jeu.o regles.o -o main ./GfxLib/libisentlib.a -lm -lglut -lGL -lX11
	
main.o: main.c 
	gcc -Wall -c main.c

menu.o: menu.c menu.h
	gcc -Wall -c menu.c
	
jeu.o: ./Jeu/jeu.c ./Jeu/jeu.h
	gcc -Wall -c ./Jeu/jeu.c

regles.o: ./Regles/regles.c ./Regles/regles.h
	gcc -Wall -c ./Regles/regles.c
	