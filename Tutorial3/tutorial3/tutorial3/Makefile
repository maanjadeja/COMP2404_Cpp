all: test1 test2

test1: test1.cc Truck.o Reservation.o Date.o
	g++ -o test1 test1.cc Truck.o Reservation.o Date.o
	
Truck.o: Truck.h Truck.cc
	g++ -c Truck.cc

test2: test2.cc Reservation.o Date.o
	g++ -o test2 test2.cc Reservation.o Date.o

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc
	
clean:
	rm -f test1 test2 *.o
