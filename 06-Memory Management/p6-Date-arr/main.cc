#include <iostream>
using namespace std;
#include <string>
#include "Date.h"

#define MAX_SIZE  2

//statically allocated array of objects
void staticObjects();
//dynamically allocated array of objects
void dynamicObjects();
//statically allocated array of pointers
void staticPointers();
//dynamically allocated array of pointers
void dynamicPointers();

int main()
{
  int x = 0;
  int y = x;
  int& z = x;
  z = 10;
  int* w = &y;
  cout <<w<<", "<< x <<", "<< y <<", "<< z;
  
  //staticObjects();
  // staticPointers();
  
  // dynamicObjects();
  // dynamicPointers();

  cout << endl << "End of program" << endl;
  return 0;
}

//statically allocated array of objects
void staticObjects(){
  cout << endl << "Statically allocated array[3] of Date objects..." << endl;
  Date arr1[MAX_SIZE];

  cout << endl << "Printing array..." << endl;

  Date* arr2 = arr1;

  for (int i = 0; i < MAX_SIZE; ++i){
    arr2[i].print();
  }

  arr1[0].setDate(1933, 3, 3);
  arr1[1].setDate(1944, 4, 4);
  arr1[0].print();
  arr1[1].print();
}

//dynamically allocated array of objects
void dynamicObjects(){
  Date* arr3 = new Date;
  cout<<"Pointers are used for dynamically allocated arrays of objects, or dynamically allocated objects"<<endl;
  delete arr3;

  cout << endl << "Dynamically allocated array of Date objects..." << endl;
  
  arr3 = new Date[MAX_SIZE];

  arr3[0].setDate(1977, 7, 7);
  arr3[1].setDate(1988, 8, 8);
  arr3[0].print();
  arr3[1].print();
  
  cout << "deallocating arr3" << endl;
  delete [] arr3;
}


//statically allocated array of pointers
void staticPointers(){
  cout << endl << "Statically allocated array of Date object pointers..." << endl;
  Date* arr2[MAX_SIZE];

  // cout << endl << "Printing pointers pointing to garbage - this will be a segmentation fault" << endl;
  // for (int i = 0; i < MAX_SIZE; ++i){
  //   arr2[i]->print();
  // }

  Date* d1 = new Date(1955, 5, 5);
  Date ** d = arr2;
  arr2[0] = d1;
  arr2[1] = new Date(1966, 6, 6);
  
  cout << endl << "Printing pointers to objects on the heap" << endl;
  for (int i = 0; i < MAX_SIZE; ++i){
    d[i]->print();
  }

  cout << "deallocating arr2 elements" << endl;
  delete arr2[0];
  delete arr2[1];
}

//dynamically allocated array of pointers
void dynamicPointers(){
  cout << endl << "Dynamically allocated array of Date object pointers..." << endl;
  Date** arr4;
  arr4 = new Date*[MAX_SIZE];
  Date* d2 = new Date(1999, 9, 9);

  arr4[0] = d2;
  arr4[1] = new Date(2010, 10, 10);
  arr4[0]->print();
  arr4[1]->print();

  cout << "deallocating arr4 and its elements" << endl;
  delete arr4[0];
  delete arr4[1];
  delete [] arr4;
}
