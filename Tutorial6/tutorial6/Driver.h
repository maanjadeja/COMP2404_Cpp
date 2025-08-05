#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>

#include "defs.h"
#include "User.h"

using namespace std;

class Driver: public User{

    public:
      Driver(string name="", int rating=0, Size size=small, Location location=NULL);
      //Driver(string name, int rating, Size size, Location location);
      bool match(int givenRating, Size givenSize);
      int getDistance(Location givenLocation);
      void print() const;


    protected:


    private:
      Size size;
      static const char code;
      static int nextId;





};

#endif
