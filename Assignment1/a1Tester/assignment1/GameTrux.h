
#ifndef GAMETRUX_H
#define GAMETRUX_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"
#include "Truck.h"
#include "defs.h"


using namespace std;

class GameTrux {

	public:
		//constructor
		GameTrux();		//No argument constructor that initializes any data required
		~GameTrux();	//Destructor to delete all dynamic memory contained in the gameTrux




		//setters


		//getters


		//other
		bool addTruck(string name, string gameType, int capacity, bool vr);	//bool addTruck(string name, string gameType, int capacity, bool vr) function returns true if a new truck has been successfully added with the given parameters and false if not
		bool deleteTruck(string name);	//bool deleteTruck(string name) function returns true if a truck with the given name in the parameters has been successfully deleted, and false if not
		void getTruck(int index, Truck** truck);	//void getTruck(int index, Truck** truck) function searches for the particular truck at the given index and returns it using the truck double pointer parameter
		bool addReservation(string customer, string gameType, int capacity, bool vr, Date& date, int start, int end);	//bool addReservation(string customer, string gameType, int capacity, bool vr, Date& date, int start, int end) function returns true if a truck with the given parameters has been found and has successfully added a reservation with the given parameters
		void updateReservations(Date& currentDate);	//void updateReservations(Date& currentDate) function gets rid of any reservations that occur before the given date, currentDate, in the parameters
		void printReservations();	//void printReservations() function prints out the truck's metadata and every reservation of that truck
		void print();	//void print() function calls print on all of the trucks


	private:
		//functions


		//variables
		Truck* arrayOfTrucks[MAX_TRUCKS];	//Variable to store array of the trucks for gameTrux
		int totalNumberOfTrucks;					//Variable to store the total count of trucks, gets updated with each addition and deletion of a truck



};
#endif
