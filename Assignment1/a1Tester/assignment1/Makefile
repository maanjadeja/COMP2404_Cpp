all: a1

a1: Date.o Reservation.o GameTrux.o Truck.o main.cc
	g++ -o a1 main.cc Date.o Reservation.o GameTrux.o Truck.o

Date.o: Date.h Date.cc
		g++ -c Date.cc

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc

Truck.o: Truck.h Truck.cc
		g++ -c Truck.cc

GameTrux.o: GameTrux.h GameTrux.cc
	g++ -c GameTrux.cc


clean:
	rm -f a1 Date.o Reservation.o  Truck.o GameTrux.o
