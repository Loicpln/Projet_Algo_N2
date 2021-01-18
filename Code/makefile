run: main
	rm *.o
	@./main

main: main.o controleur.o affichage.o souris.o ./GfxLib/libisentlib.a
	gcc -Wall main.o controleur.o affichage.o souris.o -o main ./GfxLib/libisentlib.a -lm -lglut -lGL -lX11
	
main.o: main.c 
	gcc -Wall -c main.c

controleur.o: controleur.c controleur.h
	gcc -Wall -c controleur.c

affichage.o: ./Affichage/affichage.c ./Affichage/gestion.h
	gcc -Wall -c ./Affichage/affichage.c

souris.o: ./Affichage/souris.c ./Affichage/gestion.h
	gcc -Wall -c ./Affichage/souris.c
	