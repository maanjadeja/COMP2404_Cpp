#ifndef COVOITURE_H
#define COVOITURE_H

#include <iostream>
#include <string>

#include "defs.h"
#include "Location.h"
#include "Driver.h"
#include "Customer.h"
#include "DriverList.h"
#include "CustomerList.h"




using namespace std;

class CoVoiture{

    public:
      CoVoiture();
      ~CoVoiture();
      bool addDriver(string name, int rating, Size size, Location location);
      bool getDriver(string name, Driver** foundDriver) const;
      bool removeDriver(string name);
      bool addCustomer(string name, int rating, Location location);
      bool getCustomer(string name, Customer **foundCustomer) const;
      bool removeCustomer(string name);
      bool findRide(string name, Size size, Driver**givenDriver) const;
      void printCustomers() const;
      void printDrivers() const;



    protected:


    private:
      DriverList drivers;
      CustomerList customers;





};

#endif
