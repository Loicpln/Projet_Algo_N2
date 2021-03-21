modules = controleur.o affichage.o clavier.o tempo.o elements.o calcul.o initialisation.o clic.o save.o
lib = ./GfxLib/libisentlib.a
controleur = controleur.h
gestion = ./Gestion/gestion.h
moteur = ./Moteur/moteur.h
elements = ./Elements/elements.h
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

affichage.o: ./Gestion/affichage.c $(gestion) 
	gcc -Wall -c ./Gestion/affichage.c

clic.o: ./Gestion/clic.c $(gestion) 
	gcc -Wall -c ./Gestion/clic.c

clavier.o: ./Gestion/clavier.c $(gestion) 
	gcc -Wall -c ./Gestion/clavier.c

tempo.o: ./Gestion/tempo.c $(gestion) 
	gcc -Wall -c ./Gestion/tempo.c
	
elements.o: ./Elements/elements.c $(elements) 
	gcc -Wall -c ./Elements/elements.c

calcul.o: ./Moteur/calcul.c $(moteur) 
	gcc -Wall -c ./Moteur/calcul.c

initialisation.o: ./Moteur/initialisation.c $(moteur) 
	gcc -Wall -c ./Moteur/initialisation.c
	
save.o: ./Sauvegarde/save.c $(save) 
	gcc -Wall -c ./Sauvegarde/save.c
