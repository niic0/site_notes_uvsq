objets = main.o token.o

run: compil
	./a.out 1+0=>1. 0

compil: $(objets)
	gcc $(objets) -Wall

profile: compil
	rm -rf callgrind*
	valgrind valgrind --tool=callgrind ./a.out -f temps.txt
	kcachegrind callgrind*

%.o: %.c
	gcc -c $< -Wall -g

clean:
	rm *.o
	rm a.out
