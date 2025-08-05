
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {

	template <class V>
	friend ostream& operator<<(ostream&, Array<V>&);

	public:
		//constructor
		Array();

		//destructor
		~Array();

		//other
		void add(const T&);
		T& operator[](int) const;
		T& operator[](int);

		T& get(int index);

		Array<T>& operator+=(const T&);
		Array<T>& operator-=(const T&);


		// void add(int);
		// int get(int index);
		int getSize();
		bool isFull();

		void clear();

	private:
		int size;
		T* elements;

};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
void Array<T>::add(const T& t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize(){
	return size;
}

template <class T>
bool Array<T>::isFull(){
	return size >= MAX_ARR;
}

template <class T>
T& Array<T>::get(int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
T& Array<T>::operator[](int index) const{

	if(index<0 || index>=size){
		cerr<<"ERROR: INDEX OUT OF BOUNDS!"<<endl;
		exit(1);
	}
	else{
		return elements[index];
	}

}

template <class T>
T& Array<T>::operator[](int index){

	return elements[index];

}

template <class T>
ostream& operator<<(ostream& out, Array<T>& array)
{
  // typename List <T>::Node* currNode = list.head;

  // while (currNode != NULL) {
  //   out<<currNode->data<<endl<<endl;
  //   currNode = currNode->next;
  // }
  // return out;
	for(int i=0; i<array.getSize(); i++){
		out<<array[i]<<endl;
	}
	return out;

}

template <class T>
Array<T>& Array<T>::operator+=(const T& t){

			if(size>=MAX_ARR){
				return *this;
			}
			else{

				elements[size] = t; //DOUBT: SHOULD WE CALL THE ADD FUNCTION? EVEN THOUGH IT IS VOID?
				size++;
				return *this;
				// return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);

			}

}

template <class T>
Array<T>& Array<T>::operator-=(const T& t){

			if(size==0){
				return *this;
			}
			else{
				int indexOfRemoval=-1;
				// int indexOfRemoval=-1
				for(int i=0; i<size; i++){
					if(elements[i] == t){
						indexOfRemoval=i;
						// elements[i] = elements[i+1];
					}
				}
				if(indexOfRemoval!=-1){

					for(int i=indexOfRemoval; i<size; i++){
						elements[i] = elements[i+1];
					}
					size--;
					return *this;

				}


	      // return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);

			}
}

template <class T>
void Array<T>::clear(){

	// for(int i=size-1; i>0; i--){
	// 	elements-=elements[i];
	// 	// elements[i-1]=elements[i];
	// }
	// delete [] elements;

	size=0;



}


#endif
