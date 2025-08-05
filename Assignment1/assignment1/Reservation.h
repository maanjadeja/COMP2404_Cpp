
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
		Reservation(string name, Date& theDateOfTheReservation, int start, int end); //4 argument constructor for reservation with customer name, date of reservation, start time and end time of the reservation
		Reservation(const Reservation&);

		//setters
		void setTime(int start, int end); //void setTime(int start, int end) function sets the time of the reservation according to the hours of GameTrux

		//getters
		int getClientName();
		Date getDateOfReservation(); //Date getDateOfReservation() function returns the date of the reservation in question
		int getStartTimeOfReservation();
		int getEndTimeOfReservation();

		//other
		void print(); //print() function prints out details of the reservation in proper format
		bool overlaps(Date& d, int start, int end); //bool overlaps(Date& d, int start, int end) function checks if 2 reservation occur at similar times with given parameters of d, start and end
		bool overlaps(Reservation& r); //bool overlaps(Reservation& r) function returns true if reservations have the same date and they have at least one hour in common
		bool lessThan(Reservation& res); //bool lessThan(Reservation& res) function returns false if the parameter res and this Reservation overlap, otherwise, return true if this Reservation comes before the res parameter and false otherwise.
		bool lessThan(Date& d, int start, int end); //bool lessThan(Date& d, int start, int end) function operates similarily to bool lessThan(Reservation& res); function, but uses date, start and end as parameters


	private:
		//functions


		//variables
		string nameOfClientMakingTheReservation;	//variable to store the customer name
		Date dateOfTheReservation;								//variable to store the date of the reservation
		int startTime;														//variable to store the start time of the reservation
		int endTime;															//variable to store the end time of the reservation

};
#endif
