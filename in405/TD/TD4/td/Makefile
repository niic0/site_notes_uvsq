all: compil
	./prog

compil: main.o my_ls.o
	gcc -o prog main.o my_ls.o

main.o: main.c
	gcc -c main.c

my_ls.o: my_ls.h my_ls.c
	gcc -c my_ls.c


clean:
	rm -rf *.o
	rm -rf prog
