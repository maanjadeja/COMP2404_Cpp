objects = Criteria.o Song.o test.o 

all: test

test: $(objects)
	g++ -o test $(objects)

test.o: test.cc Criteria.h Song.h
	g++ -c test.cc

Criteria.o: Criteria.h Criteria.cc
	g++ -c Criteria.cc

Song.o: Song.cc Song.h
	g++ -c Song.cc


clean:
	rm -f test *.o
