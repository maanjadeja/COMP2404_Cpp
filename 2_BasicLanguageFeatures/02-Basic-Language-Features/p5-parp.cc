#include <iostream>
#include <limits>
using namespace std;

void doubleNum(int, int&);  //input parameter, output parameter
void doubleNum(int, int*);  //input parameter, output parameter
void getInput(int&); //pass by reference using a reference - input/output parameter
void getInput(int*); //pass by reference using a pointer   - input/output parameter
bool checkNum(int);  //pass by value 

void version1();
void version2();
void version3();

int main()
{ 
  version1();
  version2();
  
}

void version1(){
  bool inputOk = false;
  int  num, result;

  while (!inputOk) {
    cout << "Please enter a number between 0 and 100: ";
    cin >> num;
    inputOk = checkNum(num);
  }

  doubleNum(num, result); 
  cout << "Result: " << result << endl;
}

void version2(){
  int  num, result;

  getInput(num);

  doubleNum(num, result);
  cout<<"Result:  " << result << endl;
}

void version3(){
  int  *num, *result;

  num = new int;
  result = new int;

  getInput(num);

  doubleNum(*num, result);
  cout<<"Result:  " << result << endl;
}

/* Parameter n is an input parameter */
/* Parameter res is an output parameter */
void doubleNum(int n, int& res)
{
  res = n * 2;
}

void doubleNum(int n, int* res)
{
  *res = n * 2;
}

/* Parameter n is an input parameter */
bool checkNum(int n)
{
  return ( n >= 0 && n <= 100 );
}

void getInput(int& n)
{
  cout << "Please enter a number between 0 and 100:  ";
  cin >> n;
  while (n < 0 || n > 100 || cin.fail()){
    //reset the error bit
    cin.clear();
    //since we have failed to read the bad data, we want to skip over
    //everything until we see a newline character
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Please enter a number between 0 and 100:  ";
    cin >> n;
    }
}

void getInput(int* n)
{
  cout << "Please enter a number between 0 and 100:  ";
  cin >> *n;
  while (*n < 0 || *n > 100 || cin.fail()){
    //reset the error bit
    cin.clear();
    //since we have failed to read the bad data, we want to skip over
    //everything until we see a newline character
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Please enter a number between 0 and 100:  ";
    cin >> *n;
    }
}