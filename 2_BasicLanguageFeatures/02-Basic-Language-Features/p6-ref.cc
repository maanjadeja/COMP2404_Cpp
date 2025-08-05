#include <iostream>
using namespace std;

int main()
{ 
  int n1, n2;

//  int& r1;
  int& r2 = n2;

  n1 = 7;
  n2 = 99;

  cout << endl;
  cout << "n1 = " << n1 << "; n2 = " << n2 << "; r2 = " << r2 << endl;

  r2 = 10;
  cout << "n1 = " << n1 << "; n2 = " << n2 << "; r2 = " << r2 << endl;

  r2 = n1;
  cout << "n1 = " << n1 << "; n2 = " << n2 << "; r2 = " << r2 << endl;

  return 0;
}

