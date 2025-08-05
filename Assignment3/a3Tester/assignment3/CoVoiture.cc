#include <iostream>
#include <string>
using namespace std;

#include "CoVoiture.h"

CoVoiture::CoVoiture(){

  // drivers = new DriverList;
  // customers = new CustomerList;

}

CoVoiture::~CoVoiture(){

  // delete drivers;
  // delete customers;


}

bool CoVoiture::addDriver(string name, int rating, Size size, Location location){
  //void add(Driver*);
  //Driver(string name, int rating, Size size, Location location);


  Driver* newDriver = new Driver(name, rating, size, location);
  drivers.add(newDriver);

  //bool get(const string& name, Driver** foundDriver);

  //DOUBT: SINCE THE ADD FUNCTION DOES NOT HAVE A BOOL RETURN TYPE, I ADDED THE TESTER BELOW
  Driver* driverChecker;

  if(drivers.get(name, &driverChecker) == false){
    cout<<"ERROR: UNABLE TO ADD A NEW DRIVER!"<<endl;
    return drivers.get(name, &driverChecker);
  }
  else{
    return drivers.get(name, &driverChecker);
  }




}

bool CoVoiture::getDriver(string name, Driver** foundDriver) const{
  //bool get(const string& name, Driver**);

  Driver* searchingDriver;

  //DOUBT: IS THIS HOW WE PASS IN foundDriver TO THE FUNCTION?

  if(drivers.get(name, &searchingDriver) == false){
    cout<<"ERROR: UNABLE TO GET DRIVER: "<<name<<endl;
    return drivers.get(name, &searchingDriver);;
  }
  else{
    *foundDriver = searchingDriver;
    return drivers.get(name, &searchingDriver);;
  }

}

bool CoVoiture::removeDriver(string name){

  //void remove(const string& name, Driver**);
  Driver* removedDriver;
  if(drivers.remove(name, &removedDriver) == false){
    cout<<"ERROR: UNABLE TO REMOVE DRIVER: "<<name<<endl;
    return false;
    // return  drivers.remove(name, &removedDriver);
  }
  else{
    return true;
    // return drivers.remove(name, &removedDriver);
  }

}

bool CoVoiture::addCustomer(string name, int rating, Location location){

  //void add(Customer* cus);
  //Customer(string name, int rating, Location location);
  Customer* newCustomer = new Customer(name, rating, location);//DOUBT: IS THIS HOW WE PASS IN location INTO THE CONSTRUCTOR
  customers.add(newCustomer); //DOUBT: IS add FUNCTION SUPPOSED TO BE VOID AS IT DOES NOT SAY SO THAT IT SHOULD BE A BOOL IN THE SPECIFICATION!

  //DOUBT: SINCE THE ADD FUNCTION DOES NOT HAVE A BOOL RETURN TYPE, I ADDED THE TESTER BELOW
  Customer* customerChecker;

  if(customers.get(name, &customerChecker) == false){
    cout<<"ERROR: CUSOMTER: "<<name<<"WAS NOT ADDED!"<<endl;
    return false;
  }
  else{
    return true;
  }


}

bool CoVoiture::getCustomer(string name, Customer **foundCustomer) const{//DOUBT: IS THIS HOW WE WOULD IMPLEMENT THIS FUNCTION?

  //bool get(const string& name, Customer** foundCustomer);
  Customer* searchingCustomer;
  bool resultOfGetCustomer = customers.get(name, &searchingCustomer);

  if(resultOfGetCustomer==false){
    cout<<"ERROR: UNABLE TO GET CUSTOMER: "<<name<<endl;
    return resultOfGetCustomer;
  }
  else{
    *foundCustomer = searchingCustomer;
    return resultOfGetCustomer;
  }

}

bool CoVoiture::removeCustomer(string name){
  //bool remove(const string& name, Customer** removedCustomer);

  Customer* removedCustomer;
  if(customers.remove(name, &removedCustomer) == false){
    cout<<"ERROR: UNABLE TO REMOVE CUSTOMER: "<<name<<endl;
    return false;
    // return customers.remove(name, &removedCustomer);
  }
  else{
    return true;
    // return customers.remove(name, &removedCustomer);
  }

}

bool CoVoiture::findRide(string name, Size size, Driver** givenDriver) const{

   Customer* foundCustomer;

   //bool get(const string& name, Customer** foundCustomer);

   bool resultOfGetCustomer = customers.get(name, &foundCustomer);

   if(resultOfGetCustomer==false){
     cout<<"ERROR: UNABLE TO GET CUSTOMER : "<<name<<" FOR FIND RIDE!"<<endl;
     return resultOfGetCustomer;
   }
   else{
     Driver* closestDriver;
     //bool findRide(int rating, Size size, Location location, Driver** d);
     bool resultOfFindRide = drivers.findRide(foundCustomer->User::getRating(), size, foundCustomer->User::getLocation(), &closestDriver);
     //bool findRide(int rating, Location, Size size, Driver** d);
     if(resultOfFindRide==false){
       cout<<"ERROR: UNABLE TO FIND RIDE FOR CUSTOMER: "<<name<<endl;
       return resultOfFindRide;
     }
     else{
       *givenDriver = closestDriver;
       return resultOfFindRide;
     }

   }


  /*find a Customer with the given name. If such a
Customer does not exist, return false. Then find the closest Driver that matches the given Size and the
rating of the Customer. If no Driver matches, return false.*/


}

void CoVoiture::printCustomers() const{
  customers.print();
}

void CoVoiture::printDrivers() const{
  drivers.print();
}
