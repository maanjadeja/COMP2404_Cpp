
#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"
#include "Reservation.h"
#include "defs.h"

using namespace std;

class Truck {

	public:
		//constructor
		Truck(string nameOfTruck, string nameOfGameType, int capacityOfTruck, bool vrPresent);
		~Truck();



		//setters


		//getters
		string getName();
		string getGameType();
		int getCapacity();
		bool getVr();


		//other
		 bool isMatch(string gt, int cap, bool v);
		 bool lessThan(Truck& t);
		 bool addReservation(string customerName, Date& d, int start, int end);
		 void printReservations();
		 void updateReservations(Date& currentDate);
		 void print();


	private:
		//functions


		//variables
		string name;
		string gameType;
		int capacity;
		bool vr;
		Reservation* arrayOfReservations[MAX_RES];
		int totalNumberOfReservations;


};
#endif
