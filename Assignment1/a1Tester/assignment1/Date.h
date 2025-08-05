
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "defs.h"


class Date {

	public:
		//constructor
		Date();
		Date(int year, int month, int day);
		Date(const Date&);

		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);

		//getters
		int getDay();
		int getMonth();
		int getYear();
		string getMonthName();

		//other
		void print();
		bool equals(Date& d);	//bool equals(Date& d) returns true if date in question and d are equal, and false if not
		bool lessThan(Date& d);	//bool lessThan(Date& d) returns true if date in question comes before d, and false if not

	private:
		//functions
		int getMaxDay();

		//variables
		int day;
		int month;
		int year;

};
#endif
