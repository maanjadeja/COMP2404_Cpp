#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

int main()
{
  cout << endl;

  Date d1;
  d1.print();
  cout << endl;

  Date d2(2020,8, 31);
  d2.print();
  cout << endl;
/*
  Date d3(2020, 8);
  d3.print();
  cout << endl;

  Date d4(2020);
  d4.print();
  cout << endl;
*/

  return 0;
}
