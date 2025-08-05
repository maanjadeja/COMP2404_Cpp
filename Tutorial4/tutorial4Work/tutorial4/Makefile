all: test

test: Song.o StackArrays.o HeapArrays.o test.cc
	g++ -o test test.cc Song.o StackArrays.o HeapArrays.o

Song.o: Song.h Song.cc
		g++ -c Song.cc

StackArrays.o: StackArrays.h StackArrays.cc
	g++ -c StackArrays.cc

HeapArrays.o: HeapArrays.h HeapArrays.cc
		g++ -c HeapArrays.cc

clean:
	rm -f test *.o
