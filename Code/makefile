modules = controleur.o affichage.o souris.o
lib = lib.h

run: main
	rm *.o
	@./main

main: main.o $(modules) ./GfxLib/libisentlib.a
	gcc -Wall main.o $(modules) -o main ./GfxLib/libisentlib.a -lm -lglut -lGL -lX11

main.o: main.c $(lib)
	gcc -Wall -c main.c

controleur.o: controleur.c controleur.h $(lib)
	gcc -Wall -c controleur.c

affichage.o: ./Affichage/affichage.c ./Affichage/gestion.h $(lib)
	gcc -Wall -c ./Affichage/affichage.c

souris.o: ./Affichage/souris.c ./Affichage/gestion.h $(lib)
	gcc -Wall -c ./Affichage/souris.c
	