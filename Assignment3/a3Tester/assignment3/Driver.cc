
#include "Driver.h"

/*
enum Size {small, medium, large};
const char code="D";
int nextId
*/

const char Driver::code = 'D'; //Static variables are initialized with the class, therefore, they are not present in the constructor
int Driver::nextId = 0;

Driver::Driver(string name, int rating, Size size, Location location): User(this->code, this->nextId++, name, rating, location){ //DOUBT: WHAT DEFAULT VALUES TO USE?, YOU CAN DO THIS! MOHAMMED SAID!

  this->size = size;

}

/*Driver::Driver(string name, int rating, Size size, Location location): User(this->code, this->nextId, name, rating, location){ //should we send the parameters like this?

  this->size = size;

  /*
  User(char idChar, int idInt, string name, int rating, Location newLocation); here do we just set idInt to 0

  Chicken::Chicken(string name, int age, float ls, int ec, string s): Animal(name, age, ls), eggCount(ec), size(s){
	cout<<" --Chicken ctor: "<<getName()<<endl;
	lifespan = ls;
}

}*/

bool Driver::match(int givenRating, Size givenSize) const{

  int diffInRating = abs(this->getRating() - givenRating);


  int diffInSize = this->size-givenSize;


  if(diffInSize>=0){

    if(diffInRating<=2){

      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }

}

int Driver::getDistance(Location givenLocation) const{

  //int getDistance(const Location& l);
  int distance = this->getLocation().getDistance(givenLocation);
  return distance;

}

void Driver::print() const{

  User::print();

}
