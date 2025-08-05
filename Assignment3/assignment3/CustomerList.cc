#include <iostream>
#include <string>
using namespace std;

#include "CustomerList.h"

CustomerList::CustomerList(): head(NULL){}


CustomerList::~CustomerList(){
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode!=NULL){
        nextNode = currNode->next;
        //delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }

}

bool CustomerList::isEmpty() const{
  Node* currNode = head;
  if(currNode==NULL){
    return true;
  }
  else{
    return false;
  }

}


//add in sorted order by name
void CustomerList::add(Customer* cus){
    Node* newNode = new Node();
    newNode->data = cus;
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

bool CustomerList::remove(const string& name, Customer** removedCustomer){
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
        *removedCustomer = NULL;
        return false;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *removedCustomer = currNode->data;
    delete currNode;
    return true;
}

bool CustomerList::get(const string& name, Customer** foundCustomer) const{ //should the parameters be consts? as in the spec it does not say so
    Node * currNode;

    currNode = head;

    while (currNode!=NULL){
        if (currNode->data->User::getName() == name){ //DOUBT: IS THIS HOW WE DO THE NAME COMPARISON? OR IS IS SUPPOSED TO BE LIKE: *(currNode->data).User::getName() == name?
           break;
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *foundCustomer = NULL;
        return false;
    }
    //currNode is not NULL
    *foundCustomer = currNode->data;
    return true;
}

void CustomerList::clear(){

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


void CustomerList::print() const{
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
