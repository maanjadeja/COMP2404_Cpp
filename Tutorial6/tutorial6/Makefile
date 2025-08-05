objects = Driver.o User.o Customer.o Location.o

all: test
	
test: test.cc $(objects)
	g++ -o test test.cc $(objects)
	
Driver.o:	Driver.h Driver.cc
	g++ -c Driver.cc

User.o:	User.h User.cc
	g++ -c User.cc

Customer.o:	Customer.h Customer.cc
	g++ -c Customer.cc

Location.o:	Location.h Location.cc
	g++ -c Location.cc
	
clean:
	rm -f test *.o
