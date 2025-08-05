
#include "GameTrux.h"
#include "Truck.h"
#include "defs.h"

//No argument constructor that initializes any data required
GameTrux::GameTrux(){

  totalNumberOfTrucks=0;

}


//Destructor to delete all dynamic memory contained in the gameTrux
GameTrux::~GameTrux()
{
  for(int i=0; i<totalNumberOfTrucks; i++){
    delete arrayOfTrucks[i];
  }
  totalNumberOfTrucks=0;
}


//setters


//getters


//other
//bool addTruck(string name, string gameType, int capacity, bool vr) function returns true if a new truck has been successfully added with the given parameters and false if not
bool GameTrux::addTruck(string name, string gameType, int capacity, bool vr){


  if(totalNumberOfTrucks==MAX_TRUCKS){
    return false;
  }
  else{

    Truck* newTruck = new Truck(name,gameType,capacity,vr);

    int i;
    for(i=totalNumberOfTrucks-1; i>=0; i--){

      if(newTruck->lessThan(*arrayOfTrucks[i])){

        arrayOfTrucks[i+1] = arrayOfTrucks[i];

      }
      else{

        break;

      }


    }
    arrayOfTrucks[i+1] = newTruck;


    totalNumberOfTrucks++;

    return true;

  }


}


//bool deleteTruck(string name) function returns true if a truck with the given name in the parameters has been successfully deleted, and false if not
bool GameTrux::deleteTruck(string name){

  int indexOfTruckWithName=0;

  bool isFound = false;
  for(int i=0; i<totalNumberOfTrucks; i++){
    if(arrayOfTrucks[i]->getName() == name){

      delete arrayOfTrucks[i];
      indexOfTruckWithName = i;
      isFound = true;
      break;

    }

  }

  if(!isFound)  return false;
  for(int j=indexOfTruckWithName; j<totalNumberOfTrucks-1; j++){

    arrayOfTrucks[j] = arrayOfTrucks[j+1];

  }

  totalNumberOfTrucks--;
  return true;


}


//void getTruck(int index, Truck** truck) function searches for the particular truck at the given index and returns it using the truck double pointer parameter
void GameTrux::getTruck(int index, Truck** truck){

  if(index>=totalNumberOfTrucks){
    *truck=NULL;
    return;
  }
  else{

    *truck = arrayOfTrucks[index];


  }

}


//bool addReservation(string customer, string gameType, int capacity, bool vr, Date& date, int start, int end) function returns true if a truck with the given parameters has been found and has successfully added a reservation with the given parameters
bool GameTrux::addReservation(string customer, string gameType, int capacity, bool vr, Date& date, int start, int end){

  for(int i=0; i<totalNumberOfTrucks; i++){

    if(arrayOfTrucks[i]->isMatch(gameType, capacity, vr)){

      if(arrayOfTrucks[i]->addReservation(customer, date, start, end)){
        return true;
      }
      else{
        return false;
      }


    }

  }

return false;
}


//void updateReservations(Date& currentDate) function gets rid of any reservations that occur before the given date, currentDate, in the parameters
void GameTrux::updateReservations(Date& currentDate){

  for(int i=0;i<totalNumberOfTrucks;i++){
    arrayOfTrucks[i]->updateReservations(currentDate);
  }

}


//void printReservations() function prints out the truck's metadata and every reservation of that truck
void GameTrux::printReservations(){

  for(int i=0; i<totalNumberOfTrucks; i++){

    arrayOfTrucks[i]->printTruck();

    arrayOfTrucks[i]->printReservations();

  }

}


//void print() function calls print on all of the trucks
void GameTrux::print(){

  for(int i=0; i<totalNumberOfTrucks; i++){
    arrayOfTrucks[i]->printTruck();
  }


}
