modules = controleur.o $(gestion) $(moteur) $(elements)
elements = elements.o 
gestion = affichage.o clavier.o clic.o tempo.o
moteur = initialisation.o gestionSelect.o gestionClic.o gestionUsers.o calcul.o
lib = ./GfxLib/libisentlib.a
controleur = controleur.h
lGestion = ./Gestion/gestion.h
lMoteur = ./Moteur/moteur.h
lElements = ./Elements/elements.h
save = ./Sauvegarde/save.h
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

main.o: main.c
	gcc -Wall -c main.c

controleur.o: controleur.c $(controleur) 
	gcc -Wall -c controleur.c

elements.o: ./Elements/elements.c $(lElements) 
	gcc -Wall -c ./Elements/elements.c

affichage.o: ./Gestion/affichage.c $(lGestion) 
	gcc -Wall -c ./Gestion/affichage.c

clic.o: ./Gestion/clic.c $(lGestion) 
	gcc -Wall -c ./Gestion/clic.c

clavier.o: ./Gestion/clavier.c $(lGestion) 
	gcc -Wall -c ./Gestion/clavier.c

tempo.o: ./Gestion/tempo.c $(lGestion) 
	gcc -Wall -c ./Gestion/tempo.c

initialisation.o: ./Moteur/initialisation.c $(lMoteur) 
	gcc -Wall -c ./Moteur/initialisation.c

gestionSelect.o: ./Moteur/gestionSelect.c $(lMoteur) 
	gcc -Wall -c ./Moteur/gestionSelect.c

gestionClic.o: ./Moteur/gestionClic.c $(lMoteur) 
	gcc -Wall -c ./Moteur/gestionClic.c

gestionUsers.o: ./Moteur/gestionUsers.c $(lMoteur) 
	gcc -Wall -c ./Moteur/gestionUsers.c

calcul.o: ./Moteur/calcul.c $(lMoteur) 
	gcc -Wall -c ./Moteur/calcul.c
