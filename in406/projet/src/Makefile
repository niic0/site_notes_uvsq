objets = eval.o token.o verif.o arbre_token.o affichage.o

test:  compil
	./eval \(1=\>\( NON \(1+0\).1\)\)
	./eval 1+0.1+ NON1
	./eval 1+0.\(1=\>0\)\<=\>\( 1+ 0\)
	./eval 0.NON1\<=\>1+NON1
	./eval 1=\>\(1.1\)

run: compil
	./eval \(1=\>\( NON \(1+0\).1\)\)

compil: $(objets)
	gcc $(objets) -Wall -o eval

profile: compil
	valgrind ./eval 1=\>\(1.1\)

%.o: %.c
	gcc -c $< -Wall -g

clean:
	rm *.o
	rm eval
