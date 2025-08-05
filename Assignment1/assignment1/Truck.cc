
#include "Truck.h"

//4 argument constructor for reservation with name of the truck, name of game type, capacity of the truck and bool variable for VR
Truck::Truck(string nameOfTruck, string nameOfGameType, int capacityOfTruck, bool vrPresent){

  name = nameOfTruck;
  gameType = nameOfGameType;
  capacity = capacityOfTruck;
  vr = vrPresent;
  totalNumberOfReservations=0;


}


//Destructor to delete all dynamic memory contained in the truck
Truck::~Truck()
{
  for(int i=0; i<totalNumberOfReservations; i++){
    delete arrayOfReservations[i];
  }
  totalNumberOfReservations=0;
}


//bool isMatch(string gt, int cap, bool v) function returns true if the truck in question has matching attributes as described by the parameters
bool Truck::isMatch(string gt, int cap, bool v){

  bool finalResultOfMatch=false;

  if((gameType == gt) && (capacity>=cap)){

    if((v==true)){

      finalResultOfMatch=vr;

    }
    else{
      finalResultOfMatch=true;
    }

  }

  return finalResultOfMatch;


}


//bool lessThan(Truck& t) function is used to check if the truck in question's name comes before t's name in alphabetical order
 bool Truck::lessThan(Truck& t){

   bool trucksNameComesBeforeT=false;

   if(name<t.name){
     trucksNameComesBeforeT=true;
   }

   return trucksNameComesBeforeT;

 }


//bool addReservation(string customerName, Date& d, int start, int end) function returns true if a new reservation has been successfully added with the given parameters and false if not
bool Truck::addReservation(string customerName, Date& d, int start, int end){

  bool resultOfAddReservation=false;

  if(totalNumberOfReservations==MAX_RES){

    return resultOfAddReservation;

  }
  else{

    for(int i=0; i<totalNumberOfReservations; i++){

      if(arrayOfReservations[i]->overlaps(d,start,end) == true){

        return false;

      }


    }



    Reservation* newReservation = new Reservation(customerName,d,start,end);

    int j;
    for(j=totalNumberOfReservations-1; j>=0; j--){

      if(newReservation->lessThan(*arrayOfReservations[j])){
        arrayOfReservations[j+1] = arrayOfReservations[j];
      }
      else{
        break;
      }

    }
    arrayOfReservations[j+1] = newReservation;

    totalNumberOfReservations++;

    return true;
  }



}


//void printReservations() function prints out the truck's metadata and every reservation of that truck
void Truck::printReservations(){


  cout<<"Truck Name: "<<name<<endl;
  cout<<"Truck Gametype: "<<gameType<<endl;
  cout<<"Truck Capacity: "<<capacity<<endl;

  if(vr==true){
    cout<<"Truck VR is present"<<endl;
  }
  else{
    cout<<"Truck VR is not present"<<endl;
  }

  cout<<endl;



  for(int i=0; i<totalNumberOfReservations; i++){

    arrayOfReservations[i]->print();

  }

}


//void printTruck() function prints out the truck's metadata
void Truck::printTruck(){


  cout<<"Truck Name: "<<name<<endl;
  cout<<"Truck GameType: "<<gameType<<endl;
  cout<<"Truck Capacity: "<<capacity<<endl;

  if(vr==true){

    cout<<"Truck Vr: PRESENT"<<endl;

  }
  else{

    cout<<"Truck Vr: NOT PRESENT"<<endl;

  }


}



//setters


//getters
//string getName() return name of the truck
string Truck::getName(){
  return name;
}



//other
//void updateReservations(Date& currentDate) function gets rid of any reservations that occur before the given date, currentDate, in the parameters
void Truck::updateReservations(Date& currentDate){

  int totalSizeOfReservationRemovalArray=0;

  for(int i=0; i<totalNumberOfReservations; i++){

    if(arrayOfReservations[i]->getDateOfReservation().lessThan(currentDate)){

      totalSizeOfReservationRemovalArray++;

    }


  }

  for(int i=0;i<totalSizeOfReservationRemovalArray;i++){
    delete arrayOfReservations[i];
  }


  totalNumberOfReservations -= totalSizeOfReservationRemovalArray;

  for(int i=0;i<totalNumberOfReservations;i++){
    arrayOfReservations[i] = arrayOfReservations[totalSizeOfReservationRemovalArray+i];
  }



}
