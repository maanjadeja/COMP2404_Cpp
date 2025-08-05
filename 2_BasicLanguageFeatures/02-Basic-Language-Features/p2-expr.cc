#include <iostream>
using namespace std;

int main()
{
  int a, b, c, d;

  a = 5;
  b = 8; 
  c = 3;

  cout << endl;
  cout << a << " " << b << " " << c << " " << d << endl;

  a + b - 3 * c;
  cout << a << " " << b << " " << c << " " << d << endl;

  cout << a + b - 3 * c << endl;

  d = a + b - 3 * c;
  cout << a << " " << b << " " << c << " " << d << endl;

  cout << 10 + (d = a + b - 3 * c) << endl;

  cout << a << " " << b << " " << c << " " << d << endl;

  cout << (a = b = c = d) << endl;

  cout << a << " " << b << " " << c << " " << d << endl;

  return 0;
}

