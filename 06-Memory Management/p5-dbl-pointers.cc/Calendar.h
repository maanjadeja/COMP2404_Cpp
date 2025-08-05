#ifndef CALENDAR_H
#define CALENDAR_H

#define MAX_ARRAY 10
#include <iostream>
#include <string>
#include "Date.h"

/*
* A very simple data structure to store and retrieve Dates.
* Later we would associate these Dates with events scheduled on that day
*/
class Calendar{

    public:
        Calendar();

        
        ~Calendar();

        /*
        * If the array is full, return false.
        * Otherwise, make a new Date with the
        * given year, month and day
        * and add it in order by lessThan
        * and return true.
        */
        bool addDate(int y, int m, int d);

        /*
        * If the index is out of bounds,
        * return false. Otherwise return the 
        * Date pointer found at the given index
        * using the double pointer return 
        * parameter, and return true via the
        * return value.
        */
        bool getDate(int index, Date**);

        /*
        * Return true if the date is found and removed,
        * otherwise return false
        */
        bool removeDate(int y, int m, int d);

        void print();

    private:
        //statically allocated array of pointers 
        Date* dates[MAX_ARRAY];
        int numDates;

};



#endif