modules = controleur.o affichage.o souris.o clavier.o tempo.o redim.o calcul.o
lib = ./GfxLib/libisentlib.a ./Fmod/libfmod.a
controleur = controleur.h
gestion = ./Gestion/gestion.h
moteur = ./Moteur/moteur.h
extentions = -lm -lglut -lGL -lX11 -lSDL_mixer
#Fmod: -I/usr/include -L/usr/lib -lfmod

run: main
	rm *.o
	@./main

clear: 
	rm *.o

main: main.o $(modules) 
	gcc -Wall main.o $(modules) -o main $(lib) $(extentions)

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
