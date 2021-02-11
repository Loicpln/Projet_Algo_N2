modules = controleur.o affichage.o clavier.o tempo.o redim.o calcul.o clic.o
lib = ./GfxLib/libisentlib.a
controleur = controleur.h
gestion = ./Gestion/gestion.h
moteur = ./Moteur/moteur.h
extentions = -lm -lglut -lGL -lX11  
#Fmod: -I/usr/include -L/usr/lib -lfmod
#SDL: -lSDL -lSDL_mixer
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

clic.o: ./Gestion/clic.c $(gestion) 
	gcc -Wall -c ./Gestion/clic.c

clavier.o: ./Gestion/clavier.c $(gestion) 
	gcc -Wall -c ./Gestion/clavier.c

tempo.o: ./Gestion/tempo.c $(gestion) 
	gcc -Wall -c ./Gestion/tempo.c

redim.o: ./Gestion/redim.c $(gestion) 
	gcc -Wall -c ./Gestion/redim.c
	
calcul.o: ./Moteur/calcul.c $(moteur) 
	gcc -Wall -c ./Moteur/calcul.c
