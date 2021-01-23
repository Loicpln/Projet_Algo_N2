modules = controleur.o affichage.o souris.o clavier.o tempo.o redim.o calcul.o
lib = lib.h
controleur = controleur.h
gestion = ./Gestion/gestion.h
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

affichage.o: ./Gestion/affichage.c $(gestion) 
	gcc -Wall -c ./Gestion/affichage.c

souris.o: ./Gestion/souris.c $(gestion) 
	gcc -Wall -c ./Gestion/souris.c

clavier.o: ./Gestion/clavier.c $(gestion) 
	gcc -Wall -c ./Gestion/clavier.c

tempo.o: ./Gestion/tempo.c $(gestion) 
	gcc -Wall -c ./Gestion/tempo.c

redim.o: ./Gestion/redim.c $(gestion) 
	gcc -Wall -c ./Gestion/redim.c
	
calcul.o: ./Moteur/calcul.c $(moteur) 
	gcc -Wall -c ./Moteur/calcul.c
