
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
		Truck(string nameOfTruck, string nameOfGameType, int capacityOfTruck, bool vrPresent);	//4 argument constructor for reservation with name of the truck, name of game type, capacity of the truck and bool variable for VR
		~Truck(); //Destructor to delete all dynamic memory contained in the truck



		//setters


		//getters
		string getName();				//string getName() return name of the truck
		string getGameType();		//string getGameType() returns name of the game type of the truck
		int getCapacity();			//int getCapacity() returns the total capacity of the truck
		bool getVr();						//bool getVr() returns bool value to determine if VR is present or not


		//other
		 bool isMatch(string gt, int cap, bool v);	//bool isMatch(string gt, int cap, bool v) function returns true if the truck in question has matching attributes as described by the parameters
		 bool lessThan(Truck& t);	//bool lessThan(Truck& t) function is used to check if the truck in question's name comes before t's name in alphabetical order
		 bool addReservation(string customerName, Date& d, int start, int end); //bool addReservation(string customerName, Date& d, int start, int end) function returns true if a new reservation has been successfully added with the given parameters and false if not
		 void printReservations();	//void printReservations() function prints out the truck's metadata and every reservation of that truck
		 void updateReservations(Date& currentDate); //void updateReservations(Date& currentDate) function gets rid of any reservations that occur before the given date, currentDate, in the parameters
		 void printTruck();	//void printTruck() function prints out the truck's metadata



	private:
		//functions


		//variables
		string name;																	//Variable to store the truck name
		string gameType;															//Variable to store name of game type for the truck
		int capacity;																	//Variable to store the trucks capacity
		bool vr;																			//Boolean variable to store if truck has VR, (true if present, false if not present)
		Reservation* arrayOfReservations[MAX_RES];		//Variable to store array of the reservations for the truck
		int totalNumberOfReservations;								//Variable to store the total count of reservations, gets updated with each addition and deletion of a reservation



};
#endif
