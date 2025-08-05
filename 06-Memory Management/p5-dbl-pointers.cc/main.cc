#include <iostream>
using namespace std;
#include <string>
#include "Date.h"
#include "Calendar.h"

int main()
{
  cout << "Making a Calendar and adding Dates..."<<endl;
  Calendar arr;
  // add some Dates
  arr.addDate(2022, 2, 25);
  arr.addDate(1999, 12, 31);
  arr.addDate(2022, 1, 29);

  cout<<"Retrieving and printing Dates: "<<endl;
  
  // Getting Dates using a double pointer
  // return parameter. 
  // We pass the address of the pointer
  // as an argument.
  

  arr.print();

  arr.removeDate(2022,1,29);

  arr.print();
  // Date* dptr;

  // arr.getDate(0, &dptr);
  // dptr->print();

  // arr.getDate(1, &dptr);
  // dptr->print();

  // arr.getDate(2, &dptr);
  // dptr->print();


  return 0;
}
