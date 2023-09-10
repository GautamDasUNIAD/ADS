#ifndef NODE
#define NODE

class Node{
    // THe linked list class is a friend of the node
    // so that it can access the private information
    friend class LinkedList;

    // private variables so that they can't be accessed
    // outside of the class
    private:
        // constructor 
        Node();
        // variable to hold the value/information at a node
        int data;
        // variable to hold the address of the next node
        Node* link;
        
};



#endif