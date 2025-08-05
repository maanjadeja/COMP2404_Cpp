
#include "Reservation.h"
#include "Date.h"

//Reservation::Reservation(string name, Date& theDateOfTheReservation, int start, int end) funciton is a 4 argument constructor for reservation with customer name, date of reservation, start time and end time of the reservation
Reservation::Reservation(string name, Date& theDateOfTheReservation, int start, int end){

  nameOfClientMakingTheReservation = name;
  dateOfTheReservation = theDateOfTheReservation;
  startTime = start;
  endTime = end;

}


//setters
//void setTime(int start, int end) function sets the time of the reservation according to the hours of GameTrux
void Reservation::setTime(int start, int end){

  int oneHourDifferenceBetweenStartAndEnd = end-start;

  if((start<8) || (oneHourDifferenceBetweenStartAndEnd<1) || (end>22)){
    cout<<"INVALID ENTRY FOR setTime(int start, int end) FUNCTION"<<endl;
  }
  else{
    startTime=start;
    endTime=end;
  }

}


//getters
//Date getDateOfReservation() function returns the date of the reservation in question
Date Reservation::getDateOfReservation(){
  return dateOfTheReservation;
}

//other
//bool overlaps(Date& d, int start, int end) function checks if 2 reservation occur at similar times with given parameters of d, start and end
bool Reservation::overlaps(Date& d, int start, int end){

  bool overlapResult=false;

  bool checkingIfDateIsEqual = d.equals(dateOfTheReservation);

  if(checkingIfDateIsEqual==false){
    overlapResult=false;
  }
  else{
    if((endTime<=start) || (startTime>=end)){
      overlapResult=false;
    }
    else{
      overlapResult=true;
    }

  }

  return overlapResult;


}

//bool overlaps(Reservation& r) function returns true if reservations have the same date and they have at least one hour in common
bool Reservation::overlaps(Reservation& r){

  return overlaps(r.dateOfTheReservation, r.startTime, r.endTime);

}

//bool lessThan(Reservation& res) function returns false if the parameter res and this Reservation overlap, otherwise, return true if this Reservation comes before the res parameter and false otherwise.
bool Reservation::lessThan(Reservation& res){

  bool reservationIsOverlapping=false;
  bool reservationIsLessThan=false;

  reservationIsOverlapping = overlaps(res);

  if(reservationIsOverlapping==true){
    reservationIsLessThan=false;
  }
  else{
    reservationIsLessThan = lessThan(res.dateOfTheReservation, res.startTime, res.endTime);
  }

  return reservationIsLessThan;

}

//bool lessThan(Date& d, int start, int end) function operates similarily to bool lessThan(Reservation& res); function, but uses date, start and end as parameters
bool Reservation::lessThan(Date& d, int start, int end){

  bool finalResultOfLessThan=false;
  bool overlapResult=false;


  overlapResult = overlaps(d,start,end);

  if(overlapResult==true){
    finalResultOfLessThan=false;
  }
  else{
    if(d.equals(dateOfTheReservation)){

      if(this->endTime<=start){
        finalResultOfLessThan=true;
      }
      else{
        finalResultOfLessThan = false;
      }
    }
    else{
      if(this->dateOfTheReservation.lessThan(d)){

        finalResultOfLessThan=true;

      }

    }

    }


  return finalResultOfLessThan;

}

//print() function prints out details of the reservation in proper format
void Reservation::print(){
	cout<<"Reservation for "<<nameOfClientMakingTheReservation<<" on ";
  dateOfTheReservation.print();
  cout<<" from "<<startTime<<":00"<<" to "<<endTime<<":00"<<endl;
}
