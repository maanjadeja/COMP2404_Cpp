#include <iostream>
using namespace std;

void memLeak();
void memLeak2(int* i1);

int main()
{ 
  int* p1 = NULL;

  //memLeak();
  memLeak2(p1);
 
  delete p1;
  return 0;
}

void memLeak(){
  int* i1 = new int(87);
  cout<<"i1: "<<*i1<<endl;
  cout<<"Returning from memLeak"<<endl;
}

void memLeak2(int* i1){
  i1 = new int(87);
  cout<<"i1: "<<*i1<<endl;
  cout<<"Returning from memLeak2"<<endl;
}
