#include <iostream>
using namespace std;

int x = 10;

int main ()
{
  int x = 8, size = 5, i = 0;

  while (i <= size) {
    int x = i;
//    x = i;
    ++i;
  }

  cout << x << endl;

  // we can access file scope this way - more on this later
  cout << ::x << endl;

  return 0;
}

