#ifndef LINKEDLIST
#define LINKEDLIST

#include "Node.h"

class LinkedList{
    // private member that can only be accessed within the class
    private:
        // address of the first node in the linked list
        Node* head;
    
    // public methods
    public:
        // default constructor-> creates an empty list
        LinkedList();

        // constructor -> creates a linked list that contains
        // elements from provided array
        LinkedList(int* array, int len);

        // deconstructor -> deletes all nodes from the list
        ~LinkedList();

        // method to insert an element in the list
        // it inserts the new number at the provided pos if
        // the number is greater than 1
        // otherwise it inserts it at the start
        void insertPosition(int pos, int newNum);

        // method to remove the the node at a given position
        // returns true or false, basedon the success of the deletion
        bool deletePosition(int pos);

        // method to return the value at a node
        int get(int pos);

        // method to search for the first occurence of a provided value
        int search(int target);

        // method to print the list
        // prints in the format [1 2 3 4]
        void printList();
};

#endif