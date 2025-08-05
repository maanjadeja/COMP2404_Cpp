all = test.o User.o DriverList.o  Driver.o Location.o

all: $(all)
	g++ -o test $(all)

test.o: test.cc
	g++ -c test.cc

User.o: User.cc User.h
	g++ -c User.cc

DriverList.o: DriverList.h DriverList.cc
	g++ -c DriverList.cc

Driver.o: Driver.cc Driver.h User.h
	g++ -c Driver.cc

Location.o: Location.cc Location.h
	g++ -c Location.cc

clean:
	rm -f test *.o
