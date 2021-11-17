#ifndef LIST_H
#define LIST_H
#include "Employee.h"

#include <iostream>
using namespace std;

class Node
{
    public:             // should change to private
        Employee *emp;
        Node *next;
    public:
        Node();                 // key = 0, next = NULL
        Node(Employee *e);   // asign key, next = NULL
        ~Node();                // delete next if next != NULL
};

class LList
{
    public:             // should change to private
        Node *head; 
    public:
        LList();                     // head = NULL
        bool isEmpty() const;        // check if head is NULL
        void insert(Employee *e); // insert new Node with key at the end
        Node* remove();              // extract the last Node from list and return it
        void print() const;          // print list from the begining
        void remove(int id);		 // remove by id
        Node* search(string name);   // search by name
        Node* search(int id);   	 // search by id
        ~LList();                    // delete head
    private:
        Node* last() const;          // return last node
};

#endif
