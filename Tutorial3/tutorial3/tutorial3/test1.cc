#include <iostream>
#include <string>

#include "Truck.h"

using namespace std;

int  main(){

    string name = "TestTruck";
    string t, type;
    int capacity, cap;
    bool virtualReality, vr, matches;

    cin >>type>>t;
    cin >>capacity>>cap;
    cin >>boolalpha>>virtualReality>>boolalpha>>vr;
    cin >>boolalpha>>matches;

    Truck t1(name, type, capacity, virtualReality);

    bool out = t1.isMatch(t, cap, vr);

    t1.print();

     if (out != matches){
        cout<<"Error, you have isMatch ="<<boolalpha<<out<<" and it should be "<<boolalpha<<matches<<endl;
        return 1;
    }

    cout<<endl<<"isMatch test successful"<<endl;
    
    return 0;
}