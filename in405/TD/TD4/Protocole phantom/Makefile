CC=gcc
PROG=phantom
SRC=main.c api.c internals.c
OBJETS=main.o api.o internals.o

run: compil
	./phantom . dossiertest

compil: $(OBJETS)
	gcc -o$(PROG) $(OBJETS)

%.o: %.c
	gcc -o $@ -c $< -Wall -g

clean:
	rm *.o
	rm a.out
