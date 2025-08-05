#include <iostream>
#include <string>
using namespace std;

#include "DriverList.h"

DriverList::DriverList(): head(NULL){}


DriverList::~DriverList(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        //delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }

}

bool DriverList::isEmpty() const{
  Node* currNode = head;
  if(currNode==NULL){
    return true;
  }
  else{
    return false;
  }

}


//add in sorted order by name
void DriverList::add(Driver* newDriver){
    Node* newNode = new Node();
    newNode->data = newDriver;
    newNode->next = NULL;

    Node* currNode = head;
    Node* prevNode = NULL;

    while(currNode!=NULL){
        if (newNode->data->User::lessThan(*currNode->data)){//DOUBT: IS THIS HOW WE CALL THE lessThan FUNCTION FROM USER
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    //insert currNode
    if (prevNode == NULL){
        head = newNode;
    }else{
        prevNode->next = newNode;
    }
    newNode->next = currNode;

}

bool DriverList::remove(const string& name, Driver** removedDriver){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->User::getName() == name){//DOUBT: IS THIS HOW WE USE THE getName FUNCTION FROM USER? AS IN DRIVER WE JUST DID this->getName()?
           break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *removedDriver = NULL;
        return false;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *removedDriver = currNode->data;
    delete currNode;
    return true;
}

bool DriverList::get(const string& name, Driver** foundDriver) const{ //should the parameters be consts? as in the spec it does not say so
    Node * currNode;

    currNode = head;

    while (currNode!=NULL){
        if (currNode->data->User::getName() == name){ //DOUBT: IS THIS HOW WE DO THE NAME COMPARISON? OR IS IS SUPPOSED TO BE LIKE: *(currNode->data).User::getName() == name?
           break;
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *foundDriver = NULL;
        return false;
    }
    //currNode is not NULL
    *foundDriver = currNode->data;
    return true;
}

bool DriverList::findRide(int rating, Size size, Location location, Driver** d) const{

  Node * currNode;

  currNode = head;

  // int getDistance(Location givenLocation);
  int currDistance=-1;

  while(currNode!=NULL){

    if(currNode->data->match(rating,size)){

      if(currDistance==-1 || currDistance>currNode->data->getDistance(location)){

        currDistance=currNode->data->getDistance(location);
        *d = currNode->data;
        //break;
      }

    }
    currNode = currNode->next;
    // else{
    //   currNode = currNode->next;
    // }

  }

  if(currDistance==-1){
    *d = NULL;
    return false;
  }
  else{
    return true;
  }



  /*Node* finalNode;

  while (currNode!=NULL){

    //matches the given Size and rating.
    //bool match(int givenRating, Size givenSize);

    if(currNode->data->match(rating,size)){

      if(currNode->data->getDistance(location) < currDistance){

        currDistance=currNode->data->getDistance(location);

        finalNode = currNode;

      }
      else{
        currNode = currNode->next;
      }

    }
    else{
      currNode = currNode->next;
    }


  }



  if(currDistance>=0){
    *d = finalNode->data;
    return true;
  }*/

}


void DriverList::clear(){

  Node* currNode = head;
  Node* nextNode = NULL;

  while(currNode!=NULL){
      nextNode = currNode->next;
      delete currNode->data;
      delete currNode;
      currNode = nextNode;
  }
    head = NULL;


}


void DriverList::print() const{
    Node* currNode = head;
    cout<<"Print list..."<<endl;

    if (currNode == NULL){
        cout <<"List empty"<<endl;
    }

    while(currNode != NULL){

        //currNode->data->User::print();
        //chicky.Animal.print();
        currNode->data->User::print();//DOUBT: IS THIS HOW WE PRINT THE DATA, BY USING THE USER print() FUNCTION
        currNode = currNode->next;
    }
}
