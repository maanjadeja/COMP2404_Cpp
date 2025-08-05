
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
	friend ostream& operator<<(ostream&, const Array<V>&); //DOUBT: I ADDED THE const HERE DUE TO THE ERROR WE WERE RECEIVING IN THE VIEW CLASS, BUT ERROR STILL PERSISTS.

	public:
		//constructor
		Array();

		//destructor
		~Array();

		//other
		void add(const T&);
		T& operator[](int) const;
		T& operator[](int);

		T& get(int index) const;

		Array<T>& operator+=(const T&);
		Array<T>& operator-=(const T&);


		// void add(int);
		// int get(int index);
		int getSize() const;
		bool isFull() const;

		void clear();

	private:
		int size;
		T* elements;

};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	// cout<<" --Array dtor"<<endl;
	// for(int i=0; i<size; i++){
	// 	// if(elements[i]!=NULL){
	// 	// 	delete elements[i];
	// 	//
	// 	// }
	// 	cout<<elements[i]<<endl;
	// 	if(elements[i])	delete elements[i];
	//
	// }
	clear();
	delete [] elements;
 	//DOUBT: IN CONTROLLER.CC THEY ARE DOING PLAYLIST.clear SO THE DESTRUCTOR HERE IS CAUSING THE ERROR
	// size=0;
}

template <class T>
void Array<T>::add(const T& t){
	if (size >= MAX_ARRAY)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize() const{
	return size;
}

template <class T>
bool Array<T>::isFull() const{
	return size >= MAX_ARRAY;
}

template <class T>
T& Array<T>::get(int index) const{
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
ostream& operator<<(ostream& out, const Array<T>& array)
{
  // typename List <T>::Node* currNode = list.head;

  // while (currNode != NULL) {
  //   out<<currNode->data<<endl<<endl;
  //   currNode = currNode->next;
  // }
  // return out;
	for(int i=0; i<array.getSize(); i++){
		out<<i<<endl;
		out<<array[i]<<endl;
	}

	return out;

}

template <class T>
Array<T>& Array<T>::operator+=(const T& t){

			if(size>=MAX_ARRAY){
				// return false;
				return *this;
			}
			else{

				elements[size] = t; //DOUBT: SHOULD WE CALL THE ADD FUNCTION? EVEN THOUGH IT IS VOID?
				size++;
				// return true;
				return *this;
				// return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);

			}

}

template <class T>
Array<T>& Array<T>::operator-=(const T& t){

			if(size<=0){
				return *this;
			}
			else{

				// int indexOfRemoval=-1
				for(int i=0; i<size; i++){
					if(elements[i] == t){
						elements[i] = elements[i+1];

					}
				}
				size--;
				// return true;
				return *this;
	      // return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);

			}
}

template <class T>
void Array<T>::clear(){

	size=0;

}


#endif
