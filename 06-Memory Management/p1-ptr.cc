#include <iostream>
using namespace std;

int main()
{
  char c = 'H';
  int  i = 42;

  int* iptr;
  char* cptr;

  cout << "sizes: char: " << sizeof(c) << " int: " << sizeof(i) << " int*: " 
       << sizeof(iptr) << " char*: "<<sizeof(cptr)<< endl<<endl;

  iptr = &i;
  cout<< "Executing iptr = &i; "<<endl<<endl;
  cout << "Integer addresses: &i: " << &i << " &iptr: " << &iptr << endl<<endl;
  cout << "Integer values:    i: " <<  i << " iptr: " <<  iptr << endl<<endl;

  cout << "two ways to i: i: " << i << " *iptr: " << *iptr << endl<<endl;

  *iptr = 99;
  cout << "new value for i: i: " << i << " *iptr: " << *iptr << endl<<endl;

  int** dp = &iptr;
  int*** tp = &dp;
  int**** qp = &tp;

  cout<<"qp: "<<****qp<<endl;

  return 0;

   
}
