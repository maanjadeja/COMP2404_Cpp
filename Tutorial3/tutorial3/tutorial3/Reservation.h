
#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"
#include "defs.h"


using namespace std;

class Reservation {

	public:
		//constructor
		Reservation();
		Reservation(string name, Date& theDateOfTheReservation, int start, int end);
		Reservation(const Reservation&);

		//setters
		void setTime(int start, int end);

		//getters
		int getClientName();
		int getDateOfReservation();
		int getStartTimeOfReservation();
		int getEndTimeOfReservation();

		//other
		void print();
		bool overlaps(Date& d, int start, int end);
		bool overlaps(Reservation& r);
		bool lessThan(Reservation& res);
		bool lessThan(Date& d, int start, int end);


	private:
		//functions


		//variables
		string nameOfClientMakingTheReservation;
		Date dateOfTheReservation;
		int startTime;
		int endTime;

};
#endif
