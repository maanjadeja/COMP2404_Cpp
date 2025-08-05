#include<iostream>
#include<string>

using namespace std;

void power(int,int,int&);

int main(){

	int num1;
	int num2;
	cout<<"Please enter two integers: ";
	cin>>num1;
	cin>>num2;


	int product=0;
  power(num1,num2,product);

	cout<<"The product of "<<num1<<" raised to "<<num2<<" is "<<product<<"!"<<endl;

	return 0;
}
