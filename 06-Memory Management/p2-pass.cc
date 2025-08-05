#include <iostream>
#include <limits>
using namespace std;

void getInput(int&);
void doubleNum(int, int&);
void doubleNum(int, int*);

int main()
{ 
  bool inputOk = false;
  int  num, result1, result2;

  int& num2 = num;

  getInput(num);

  doubleNum(num, result1);
  doubleNum(num, &result2);
  cout<<"Result 1:  " << result1 << endl;
  cout<<"Result 2:  " << result2 << endl;

  return 0;
}

void doubleNum(int n, int* res)
{
  cout << "doubleNum() pass by reference by pointer" << endl;
  *res = n * 2;
}

void doubleNum(int n, int& res)
{
  cout << "doubleNum() pass by reference by reference" << endl;
  res = n * 2;
}

void getInput(int& n)
{
  cout << "Please enter a number between 0 and 100:  ";
  cin >> n;
  while (n < 0 || n > 100 || cin.fail()){
    
    // If cin.fail() was triggered, an error bit
    // was flipped. Reset the error bit with clear().
    cin.clear();

    /*
    * Re: cin.ignore()
    * Since the data was bad, the input was left in the buffer.
    * Next time we call cin, we will get the same input as before
    * (and the same error). To empty the cin buffer, we ignore 
    * everything until we see a newline character. The 'limits'
    * library allows us to ignore as many characters as necessary.
    * 
    * Note, if we read in two variables at once (cin >> a >> b;), 
    * this process would not work if the variables were separated 
    * by a newline character, since that would still leave the
    * second input. 
    * 
    * You do not need to do this type of error checking on 
    * assignments, but you can if you like.
    */

    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

    cout << "Please enter a number between 0 and 100:  ";
    cin >> n;
  }
}

