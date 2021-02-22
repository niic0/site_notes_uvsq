all: executable
	./executable

executable: principal.o ea.o
	gcc -o executable principal.o ea.o


principal.o: principal.c
	gcc -c principal.c

ea.o: ea.h ea.c
	gcc -c ea.c


clean:
	rm -rf *.o
	rm -rf executable
