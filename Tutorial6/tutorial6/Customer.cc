
#include "Customer.h"

/*
const char code = "C";
int nextId;

*/

const char Customer::code = 'C'; //Static variables are initialized with the class, therefore, they are not present in the constructor
int Customer::nextId = 0;


Customer::Customer(string name, int rating, Location location): User(this->code, this->nextId++, name, rating, location){ //DOUBT: WHAT DEFAULT VALUES DO YOU WANT FOR THIS DEFAULT CONSTRUCTOR?, YOU CAN DO THIS, MOHAMMED SAID!


}


/*Customer::Customer(string name, int rating, Location location): User(this->code, this->nextId, name, rating, location){ //should we send the parameters like this?
  /*
  User(char idChar, int idInt, string name, int rating, Location newLocation); here do we just set idInt to 0

  Chicken::Chicken(string name, int age, float ls, int ec, string s): Animal(name, age, ls), eggCount(ec), size(s){
	cout<<" --Chicken ctor: "<<getName()<<endl;
	lifespan = ls;
}

}*/

void Customer::print() const{

  User::print();

}
