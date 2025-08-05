
#include "Reservation.h"
#include "Date.h"

Reservation::Reservation(string name, Date& theDateOfTheReservation, int start, int end){

  nameOfClientMakingTheReservation = name;
  dateOfTheReservation = theDateOfTheReservation;
  startTime = start;
  endTime = end;

}


//setters
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


//other
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

bool Reservation::overlaps(Reservation& r){

  return overlaps(r.dateOfTheReservation, r.startTime, r.endTime);

}

bool Reservation::lessThan(Reservation& res){

  bool reservationIsOverlapping=false;
  bool reservationIsLessThan=false;

  reservationIsOverlapping = overlaps(res);

  if(reservationIsOverlapping==true){
    reservationIsLessThan=false;
  }
  else{
    reservationIsLessThan = this->dateOfTheReservation.lessThan(res.dateOfTheReservation);
  }

  return reservationIsLessThan;

}

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

void Reservation::print(){
	cout<<"Reservation for "<<nameOfClientMakingTheReservation<<" on ";
  dateOfTheReservation.print();
  cout<<" from "<<startTime<<":00"<<" to "<<endTime<<":00"<<endl;
}
