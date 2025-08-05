#include <iostream>
#include <string>
#include <sstream>

#include "defs.h"
#include "Driver.h"
#include "Customer.h"

#define ARR 5

using namespace std;

const string names[5] = {"Abe","Bae","Cedric","Deb","Elise"};
const string numbers[5] = {"000","111","222","333","444"};

int customerIdTest();
int driverIdTest();
int driverMatchTest();

int main(){

  
    int choice = 0;
    cin >> choice;
    switch(choice){
      case 0: return customerIdTest();
      case 1: return driverIdTest(); 
      case 2: return driverMatchTest(); 
    }

    return 1;
}

// make some customers and check their id number
int customerIdTest(){
    int nums[ARR] = {4,0,1,3,2};
    string strs[ARR] = {"C5","C1","C2","C4", "C3"}; 
    Customer* customers[ARR];
    for (int i = 0; i < ARR; ++i){
      customers[i] = new Customer(names[i]);
    }

    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    

    //reset stringstream
    for (int i = 0; i < ARR; ++i){
        //move std::cout to an ostringstream
        std::cout.rdbuf( strCout.rdbuf() );
        customers[nums[i]]->print();
        //replace the old std::cout
        std::cout.rdbuf( oldCoutStreamBuf );
        //grab the output and write it to the console
        string output = strCout.str();
        std::cout << output;
        //reset the stream
        strCout.str(std::string());
        //search the output
        if (output.find(strs[i])){
          cout << strs[i]<<" found, success!"<<endl;
        }else{
          cout << strs[i]<<" not found, test failed!"<<endl;
          return 1;
        }
    }

    return 0;
}

// make some drivers and check their id number
int driverIdTest(){
    int nums[ARR] = {4,0,1,3,2};
    string strs[ARR] = {"D5","D1","D2","D4", "D3"}; 
    Driver* drivers[ARR];
    for (int i = 0; i < ARR; ++i){
      drivers[i] = new Driver(names[i]);
    }

    //capture the output and put in a stringstream
    streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    ostringstream strCout;
    

    //reset stringstream
    for (int i = 0; i < ARR; ++i){
        //move std::cout to an ostringstream
        std::cout.rdbuf( strCout.rdbuf() );
        drivers[nums[i]]->print();
        //replace the old std::cout
        std::cout.rdbuf( oldCoutStreamBuf );
        //grab the output and write it to the console
        string output = strCout.str();
        std::cout << output;
        //reset the stream
        strCout.str(std::string());
        //search the output
        if (output.find(strs[i])){
          cout << strs[i]<<" found, success!"<<endl;
        }else{
          cout << strs[i]<<" not found, test failed!"<<endl;
          return 1;
        }
    }

    return 0;
}

int driverMatchTest(){
  Driver* ds[ARR];
  ds[0] = new Driver("Elsa", 5, medium, Location(3,4));
  ds[1] = new Driver("Densel", 4, small, Location(1,1));
  ds[2] = new Driver("Carter", 2, large, Location(5,4));
  ds[3] = new Driver("Bob", 4, small, Location(2, 2));
  ds[4] = new Driver("Alice", 5, medium, Location(7, 7));

  cout<<"Testing match (5, medium) to (5 medium)..."<<endl;
  if (ds[0]->match(5, medium)){
    cout<<"Match successful, test passed!"<<endl;
  }else{
    cout<<"Match not successful, test failed!"<<endl;
    return 1;
  }

  cout<<"Testing match (3, medium) to (5 medium)..."<<endl;
  if (ds[0]->match(3, medium)){
    cout<<"Match successful, test passed!"<<endl;
  }else{
    cout<<"Match not successful, test failed!"<<endl;
    return 1;
  }

  cout<<"Testing match (2, medium) to (5 medium)..."<<endl;
  if (ds[0]->match(2, medium)){
    cout<<"Match successful, test failed!"<<endl;
    return 1;
  }else{
    cout<<"Match not successful, test passed!"<<endl;
  }

  cout<<"Testing match (2, large) to (2 large)..."<<endl;
  if (ds[2]->match(2, large)){
    cout<<"Match successful, test passed!"<<endl;
  }else{
    cout<<"Match not successful, test failed!"<<endl;
    return 1;
  }

  cout<<"Testing match (5, large) to (2 large)..."<<endl;
  if (ds[2]->match(5, large)){
    cout<<"Match successful, test failed!"<<endl;
    return 1;
  }else{
    cout<<"Match not successful, test passed!"<<endl;
  }

  cout<<"Testing match (2, small) to (2 large)..."<<endl;
  if (ds[2]->match(2, small)){
    cout<<"Match successful, test passed!"<<endl;
  }else{
    cout<<"Match not successful, test failed!"<<endl;
    return 1;
  }

  cout<<"Testing match (3, medium) to (4, small)..."<<endl;
  if (ds[3]->match(3, medium)){
    cout<<"Match successful, test failed!"<<endl;
    return 1;
  }else{
    cout<<"Match not successful, test passed!"<<endl;
  }

  cout<<"Testing match (5, large) to (5, medium)..."<<endl;
  if (ds[4]->match(5, large)){
    cout<<"Match successful, test failed!"<<endl;
    return 1;
  }else{
    cout<<"Match not successful, test passed!"<<endl;
  }



  // all tests passed
  return 0;
}






