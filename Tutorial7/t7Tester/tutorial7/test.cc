#include <istream>
#include <string>

#include "defs.h"
#include "DriverList.h"

#define ARR 5

using namespace std;



int findRideTest();
int clearTest();

int main(){


    int choice = 0;
    cin >> choice;
    switch(choice){
      case 0: return findRideTest();
      case 1: return clearTest();
    }

}

// note returning 1 is an error code, returning 0 is no error code
// This is how the Python script judges if the test was successful
int findRideTest(){
  DriverList drivers;
  Driver* ds[ARR];
  ds[0] = new Driver("Elsa", 5, medium, Location(3,4));
  ds[1] = new Driver("Densel", 4, small, Location(1,1));
  ds[2] = new Driver("Carter", 2, large, Location(5,4));
  ds[3] = new Driver("Bob", 4, small, Location(2, 2));
  ds[4] = new Driver("Alice", 5, medium, Location(7, 7));
  drivers.add(ds[0]);
  drivers.add(ds[1]);
  drivers.add(ds[2]);
  drivers.add(ds[3]);
  drivers.add(ds[4]);

  Driver* d;
  if (drivers.findRide(2, large, Location(1,1), &d)){
    if (d == ds[2]){
      cout << "Correct driver found!"<<endl;
      d->print();
    }else{
      cout << "Test failed, wrong driver found! Only Carter has a large vehicle."<<endl;
      d->print();
      return 1;
    }
  }else{
    cout << "Test failed, no driver found! (Should find Carter.)"<<endl;
    return 1;
  }

  if (drivers.findRide(5, small, Location(4,4), &d)){
    if (d == ds[0]){
      cout << "Correct driver found!"<<endl;
      d->print();
    }else{
      cout << "Test failed, wrong driver found! Elsa is closest."<<endl;
      d->print();
      return 1;
    }
  }else{
    cout << "Test failed, no driver found! (Should find Elsa.)"<<endl;
    return 1;
  }

  if (drivers.findRide(4, small, Location(6,6), &d)){
    if (d == ds[4]){
      cout << "Correct driver found!"<<endl;
      d->print();
    }else{
      cout << "Test failed, wrong driver found! Alice is closest."<<endl;
      d->print();
      return 1;
    }
  }else{
    cout << "Test failed, no driver found! (Should find Alice.)"<<endl;
    return 1;
  }


  if (drivers.findRide(5, large, Location(6,6), &d)){
      cout << "Test failed, driver found but none matched the criteria."<<endl;
      d->print();
      return 1;
  }else{
    cout << "Test succeeded, no driver found! "<<endl;
  }
  return 0;

}

int clearTest(){
  DriverList drivers;
  Driver* ds[ARR];
  ds[0] = new Driver("Elsa", 5, medium, Location(3,4));
  ds[1] = new Driver("Densel", 4, small, Location(1,1));
  ds[2] = new Driver("Carter", 2, large, Location(5,4));
  ds[3] = new Driver("Bob", 4, small, Location(2, 2));
  ds[4] = new Driver("Alice", 5, medium, Location(7, 7));
  drivers.add(ds[0]);
  drivers.add(ds[1]);
  drivers.add(ds[2]);
  drivers.add(ds[3]);
  drivers.add(ds[4]);

  drivers.clear();
  cout << "test" << endl;

  ds[0] = new Driver("Elsa", 5, medium, Location(3,4));
  ds[1] = new Driver("Densel", 4, small, Location(1,1));
  drivers.add(ds[0]);
  drivers.add(ds[1]);
  drivers.print();
  drivers.clear();
  return 0;
}
