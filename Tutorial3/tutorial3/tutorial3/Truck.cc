
#include "Truck.h"


Truck::Truck(string nameOfTruck, string nameOfGameType, int capacityOfTruck, bool vrPresent){

  name = nameOfTruck;
  gameType = nameOfGameType;
  capacity = capacityOfTruck;
  vr = vrPresent;
  totalNumberOfReservations=0;//forgot this part

}

Truck::~Truck()
{
  //cout<<"-- dtor:  "<< id <<" "<< location <<endl;
  for(int i=0; i<totalNumberOfReservations; i++){
    delete arrayOfReservations[i];
  }
  totalNumberOfReservations=0;
}

bool Truck::isMatch(string gt, int cap, bool v){

  bool finalResultOfMatch=false;

  if((gameType == gt) && (capacity>=cap)){

    if((v==true) && (vr==true)){

      finalResultOfMatch=true;

    }
    else if(v==false){
      finalResultOfMatch=true;
    }


  }

  return finalResultOfMatch;


}

 bool Truck::lessThan(Truck& t){

   bool trucksNameComesBeforeT=false;

   if(name<t.name){
     trucksNameComesBeforeT=true;
   }

   return trucksNameComesBeforeT;

 }

bool Truck::addReservation(string customerName, Date& d, int start, int end){

  bool resultOfAddReservation=false;

  if(totalNumberOfReservations==MAX_RES){

    return resultOfAddReservation;

  }
  else{



    //newReservation(customerName, d, start, end);

    for(int i=0; i<totalNumberOfReservations; i++){


      if(arrayOfReservations[i]->overlaps(d,start,end) == true){

        return false;

      }


    }



    Reservation* newReservation = new Reservation(customerName,d,start,end);

    arrayOfReservations[totalNumberOfReservations]=newReservation;
    totalNumberOfReservations++;

    return true;




  }



}

void Truck::printReservations(){

  for(int i=0; i<totalNumberOfReservations; i++){

    arrayOfReservations[i]->print();

  }

}

void Truck::print(){


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
string Truck::getName(){
  return name;
}



//other
/*void Truck::updateReservations(Date& currentDate){

  for(int i=0; i<totalNumberOfReservations; i++){

    if(*arrayOfReservations[i]->getDateOfReservation().lessThan(currentDate)){

      remove(*arrayOfReservations[i]);

      //how can i get rid of the gaps in the array after remove?
      //yep
      //ok

      //loop through the entire arrayOfTrucks
      //find location where the reservation is not present?


    }

  }

}*/
