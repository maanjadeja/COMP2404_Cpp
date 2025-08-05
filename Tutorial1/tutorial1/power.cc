#include<iostream>
#include<string>

using namespace std;

/*void power(int, int, int&);


 int main(){

   int number=0;

   power(2,3,number);

   cout<<number<<endl;

   return 0;


 }*/

 void power(int a, int b, int& c){

   int value=1;

   for(int i=0; i<b; i++){

     value = value*a;

   }

   c = value;


 }
