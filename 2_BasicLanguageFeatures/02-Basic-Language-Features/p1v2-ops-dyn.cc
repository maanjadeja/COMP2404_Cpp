

#include <iostream>
using namespace std;

int main()
{
  int *x, *y, *z;

  x = new int;
  y = new int;
  z = new int;

  *x = 4;
  *y = *x;
  *z = *y + 2 * *x - 3;

  cout << endl;
  cout << *x << " " << *y << " " << *z << endl;

  if (*x == *y)
    cout << "equal" << endl;
  else
    cout << "not equal" << endl;

  cout << ( (*y == *z) ? "equal" : "not equal" ) << endl;

  *x = *y = 7;
  *z -= *x;
  *y *= *z;
  cout << *x << " " << *y << " " << *z << endl;

  cout << endl;
  cout << "prefix:  " << ++*x << endl;
  cout << "postfix: " << *x++ << endl;
  cout << "next:    " << *x << endl;

  delete x;
  delete y;
  delete z;

  return 0;
}

