
#include "User.h"

/*
string getId();
string getName();
int getRating();
Location getLocation();
bool setRating();
void setLocation(Location newLocation);
void setLocation(int x, int y);*/

/*
string id;
string name;
int rating;
Location currLocation;
*/
User::User(char idChar, int idInt, string name, int rating, Location newLocation){

   string userID = idChar + std::to_string(idInt);//DOUBT: IS THIS HOW I AM SUPPOSED TO CONCAT INTEGER TO STRING?
   this->id = userID;
   this->name = name;
   this->rating = rating;
   this->currLocation = newLocation;

}

string User::getId() const{
  return this->id;
}

string User::getName() const{
  return this->name;
}

int User::getRating() const{
  return this->rating;
}

Location User::getLocation() const{
  return this->currLocation;
}

void User::setRating(int newRating){
  this->rating = newRating;
}

void User::setLocation(Location newLocation){
  this->currLocation = newLocation;
}

void User::setLocation(int x, int y){

  //Location::void setLocation(int x, int y);
  this->currLocation.setLocation(x,y);

}

bool User::lessThan(User user){
  if(this->name < user.name){
    return true;
  }
  else{
    return false;
  }
}


void User::print() const{
  /*
  string id;
  string name;
  int rating;
  Location currLocation;
  */
  cout<<"ID: "<<this->id<<endl;
  cout<<"Name: "<<this->name<<endl;
  cout<<"Rating: "<<this->rating<<endl;
  this->currLocation.print();
  cout<<endl;



}
