all: foo

foo: foo.cc foo2.o
	g++ -o foo foo.cc foo2.o

foo2: foo2.cc
	g++ -c foo2.cc

clean:
	rm -f foo *.o