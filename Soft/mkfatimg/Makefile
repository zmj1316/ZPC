all: main.o ff.o diskio.o
	gcc main.o ff.o diskio.o 
main.o: main.c
	gcc -c main.c
ff.o: ff.c ff.h ffconf.h
	gcc -c ff.c ff.h ffconf.h
diskio.o: diskio.c diskio.h
	gcc -c diskio.c 

