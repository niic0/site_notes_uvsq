visu: stat.pdf
	evince stat.pdf &


stat.pdf: tri_bulle stat.gplt test_tri_bulle.data
	gnuplot stat.gplt

test_tri_bulle.data: tri_bulle
	./tri_bulle

# Le tri fision

tri_fusion: tri_fusion.c tabint.o
	gcc -Wall -o tri_fusion tri_fusion.c tabint.o

# Le tri à bulles

tri_bulle: tri_bulle.o tabint.o
	gcc -Wall -o tri_bulle tri_bulle.o tabint.o

tri_bulle.o: tri_bulle.c tabint.h stat.h
	gcc -Wall -c tri_bulle.c


# La bibliothèque de manipulation de tableaux
tabint.o: tabint.c tabint.h
	gcc -Wall -c tabint.c

clean:
	rm -f tabint.o
	rm -f tri_bulle.o tri_bulle
	rm -f stat.pdf
	rm -f test_tri_bulle.data
	ls -l


ZIPNAME=IN301-303_TD_TRI_INT
zip:
	rm -rf ${ZIPNAME}
	mkdir ${ZIPNAME}
	cp *.c ${ZIPNAME}
	cp *.h ${ZIPNAME}
	cp Makefile ${ZIPNAME}
	cp *.gplt ${ZIPNAME}
	zip -r $(ZIPNAME).zip $(ZIPNAME)
##	rm -rf ${ZIPNAME}
	ls -l ${ZIPNAME}*

run:
	time ./tri_bulle 1000
	time ./tri_fusion 1000
	time ./tri_bulle 10000
	time ./tri_fusion 10000
	time ./tri_bulle 20000
	time ./tri_fusion 20000
