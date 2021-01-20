modules = controleur.o affichage.o souris.o clavier.o tempo.o redim.o
lib = lib.h
controleur = controleur.h
gestion = ./Affichage/gestion.h
moteur = ./Moteur/moteur.h

run: main
	rm *.o
	@./main

main: main.o $(modules) ./GfxLib/libisentlib.a
	gcc -Wall main.o $(modules) -o main ./GfxLib/libisentlib.a -lm -lglut -lGL -lX11

main.o: main.c $(controleur)
	gcc -Wall -c main.c

controleur.o: controleur.c $(controleur) 
	gcc -Wall -c controleur.c

affichage.o: ./Affichage/affichage.c $(gestion) 
	gcc -Wall -c ./Affichage/affichage.c

souris.o: ./Affichage/souris.c $(gestion) 
	gcc -Wall -c ./Affichage/souris.c

clavier.o: ./Affichage/clavier.c $(gestion) 
	gcc -Wall -c ./Affichage/clavier.c

tempo.o: ./Moteur/tempo.c $(moteur) 
	gcc -Wall -c ./Moteur/tempo.c

redim.o: ./Moteur/redim.c $(moteur) 
	gcc -Wall -c ./Moteur/redim.c
