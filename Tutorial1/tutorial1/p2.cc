#include<iostream>
#include<string>

using namespace std;

int main(){

	int num1;
	int num2;
	cout<<"Please enter two integers: ";
	cin>>num1;
	cin>>num2;

	int product=num1*num2;

	cout<<"The product of "<<num1<<" and "<<num2<<" is "<<product<<"!"<<endl;

	return 0;
}
