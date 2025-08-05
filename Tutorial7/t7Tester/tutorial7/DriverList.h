#ifndef DRIVERLIST_H
#define DRIVERLIST_H
#include <string>

#include "Driver.h"

class DriverList{

    //friend class Student;

    //private by default
    class Node {

        public:
            Driver* data;
            Node*    next;
    };

    public:
        DriverList();

        // Any data left in the List gets destroyed
        ~DriverList();

        bool isEmpty();
        //we have unlimited size, so add always succeeds
        void add(Driver* newDriver);
        //return false if name not found
        bool get(const string& name, Driver** foundDriver);
        //double pointer for a return parameter of a pointer
        bool remove(const string& name, Driver** removedDriver);

        bool findRide(int rating, Size size, Location location, Driver** d);

        void clear();

        void print() const;  //not modify this List object

    private:
        Node* head;

};


#endif
