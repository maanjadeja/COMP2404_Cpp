#include <iostream>
using namespace std;

int main()
{ 
  int* p1;

  p1  = new int;
  *p1 = 56;
  cout << *p1 << endl;

  int* p2 = new int(87);
  cout << *p2 << endl;
  cout << endl;
 
  delete p1;
  delete p2;

  int* p3 = new int[4];

  for (int i=0; i<4; ++i)
    p3[i] = i * 2;

  for (int i=0; i<4; ++i)
    cout << p3[i] << " ";

  cout << endl;

  delete [] p3;


  return 0;
}
