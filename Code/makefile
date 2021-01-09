run: main
	rm *.o
	@./main

main: main.o fonction.o ./GfxLib/libisentlib.a
	gcc -Wall main.o fonction.o -o main ./GfxLib/libisentlib.a -lm -lglut -lGL -lX11
	
main.o: main.c 
	gcc -Wall -c main.c
	
fonction.o: fonction.c 
	gcc -Wall -c fonction.c