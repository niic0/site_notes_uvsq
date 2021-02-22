run: compile
	./principal

compile: principal.o exo_42.o
	gcc principal.o exo_42.o -o principal

principal.o: principal.c
	gcc -c principal.c -Wall

exo_39.o: exo_39.c
	gcc -c exo_39.c -Wall

exo_40.o: exo_41.c
	gcc -c exo_41.c -Wall

exo_42.o: exo_42.c
	gcc -c exo_42.c -Wall


clean:
	rm *f
