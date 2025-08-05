#include <iostream>
using namespace std;
#include <string>
#include "Date.h"

#define MAX_SIZE  3

int main()
{
  cout<<endl<<"Allocating on the heap:"<<endl;
  
  Date* d1 = new Date;
  Date* d2 = new Date(2020, 8, 23);
  d1->print();
  (*d1).print();
  d2->print();
  
  

  d1->setDate(1905, 5, 5);
  cout<<"Changed date d1"<<endl;
  d1->print();
  cout<<endl<<"Allocating on the stack:"<<endl;
  Date d3;
  Date d4(2020, 8, 23);
  d3.print();
  d4.print();


  cout<<endl<<"Deleting from the heap:"<<endl;

  delete d1;
  delete d2;



  return 0;
}
