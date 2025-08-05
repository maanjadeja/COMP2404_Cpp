#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include <string>

#include "Customer.h"

class CustomerList{

    //friend class Student;

    //private by default
    class Node {

        public:
            Customer* data;
            Node*    next;
    };

    public:
        CustomerList();

        // Any data left in the List gets destroyed
        ~CustomerList();

        bool isEmpty() const;
        //we have unlimited size, so add always succeeds
        void add(Customer* cus);
        //return false if name not found
        bool get(const string& name, Customer** foundCustomer) const;
        //double pointer for a return parameter of a pointer
        bool remove(const string& name, Customer** removedCustomer);

        void clear();

        void print() const;  //not modify this List object

    private:
        Node* head;

};


#endif
