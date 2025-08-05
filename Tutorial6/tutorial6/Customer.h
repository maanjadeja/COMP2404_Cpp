#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "defs.h"

#include "User.h"


using namespace std;

class Customer: public User{

    public:
      Customer(string name=" ", int rating=0, Location location=NULL);
      //Customer(string name, int rating, Location location);
      void print() const;


    protected:


    private:
      static const char code;
      static int nextId;


};

#endif
