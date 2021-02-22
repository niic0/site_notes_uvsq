objets= principal.o exo_42.o  exo_43.o  exo_44.o exo_45.o exo_46.o exo_47.o

run: compile
	./principal

compile: $(objets)
	gcc -o principal $(objets)

%.o: %.c
	gcc -o $@ -c $< -Wall

clean:
	rm *.o
	rm principal
