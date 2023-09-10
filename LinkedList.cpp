#include "LinkedList.h"
#include <iostream>
#include <limits>

// default constructor
LinkedList::LinkedList(){
    // set the head to null pointer
    head = nullptr;
}

// constructor to make a list with provided values
LinkedList::LinkedList(int* array, int len){
    // variable to hold the address of the previous node
    Node* prev_node;
    
    // loop through all elements in the list
    for (int i = 0; i < len; i++){
        // create a node object for each element
        Node* element = new Node;
        
        // if it is the first element
        if (i==0){
            // set the value of head to the address 
            // of the current node element
            head = element;
        } else{
            // get the prevois node using the address
            // set the value of the link (address of the next node)
            // to the address of the current node
            prev_node->link = element;
        }

        // set the value of the element
        element->data = array[i];

        // set the link to a null pointer
        // if it is not the last one, it will be updatd
        // in the next iteration
        element->link = nullptr;

        // set the prev_node to the address of the current node
        prev_node = element;
    }
}

// deconstructor
LinkedList::~LinkedList(){
    // traverse through the entire list
    // at each node, delete the previous node

    // address of the previous_node
    Node* prev_node;

    // current node
    Node* current_node = head;
    // looping through the list
    while (current_node != nullptr){
        // if this is the first node
        if (current_node == head){
            // set the head to nullptr
            head = nullptr;
            
        }else{
            // delete the previous node
            delete prev_node;
            
        }
        // set address of previous node the the current one
        prev_node = current_node;
        // get address of next node
        current_node = current_node->link;
    }
    // delete last node, becuase within while loop we only deleted previous nodes
    // so the last node to have been deleted was the second last one
    delete current_node;
}

// method to add a new node at a given position
void LinkedList::insertPosition(int pos, int newNum){
    // if pos is less then or equal to 1, add new node at the start
    if (pos <= 1){
        // create a new node
        Node* new_node = new Node;

        // set the data of the node
        new_node->data = newNum;

        // set the link of the node so that it has
        // the address of the previously first node
        new_node->link = head;

        // set the head to point to this new_node
        head = new_node;
    }

    // variable to hold the current index
    int index = 1;

    // loop through the list
    Node* current_node = head;
    // variable to hold the previous node
    Node* prev_node;

    while(current_node != nullptr){
        // if we have reached the required position
        if (index == pos){
            // create a new node
            Node* new_node = new Node;

            // set the data of the node
            new_node->data = newNum;

            // set the link of the node as the address
            // of the next node 
            // (which is currently being pointed to by the previous node)
            new_node->link = prev_node->link;

            // set the link of the previous node to the
            // new ones address
            prev_node->link = new_node;

            // break the loop
            break;
        }else{
            // change the previous node to be the current one
            prev_node = current_node;
            // change the current node to be the next one
            current_node = current_node->link;
        }

        // increment the index
        index++;
    }
    // if the current node is a null ptr
    // the required index wasn't found
    if (current_node == nullptr){
        // create a new node
        Node* new_node = new Node;

        // set the data of the node
        new_node->data = newNum;

        // set the link of the node as nullptr
        new_node->link = nullptr;

        // set the link of the node before the new one
        // to the address of the current one
        prev_node->link = new_node;
    }
};

// method to remove the the node at a given position
// returns true or false, basedon the success of the deletion
bool LinkedList::deletePosition(int pos){
    // if the pos is 1, delete the first node
    if(pos == 1){
        // get the link of the current first node
        Node* link = head->link; // this points to the second node

        // delete the first node
        delete head;

        // set the head to the address of the second node
        head = link;

        // since deletion occurred successfuly
        return true;
    }

    // variable to hold the index
    int index = 1;
    // loop through the list
    Node* current_node = head;
    // variable to hold the previous node
    Node* prev_node;
    
    while(current_node != nullptr){
        // if we have reached the required pos
        if (index == pos){
            // set the link of the preivous node as the link of the current one
            prev_node->link = current_node->link;

            // delete the current node
            delete current_node;
            
            // return true, as the deletion occurred successfully
            return true;
        } else{
            // change the previous node to be the current one
            prev_node = current_node;
            // change the current node to be the next one
            current_node = current_node->link;
        }
        // increment the index
        index++;
    }

    // if the provided position was within bounds
    // the deletion would have occured, since the code
    // has reached this point it hasn't. Therefore,
    // return false
    return false;
    
};

// method to return the value at a node
int LinkedList::get(int pos){
    // variable to hold the index
    int index = 1;
    // loop through the list
    Node* current_node = head;
    while(current_node != nullptr){
        // if we have reached the required pos
        if (index == pos){
            // return the data at that node
            return current_node->data;
        } else{
            // change the current node to be the next one
            current_node = current_node->link;
        }
        // increment the index
        index++;
    }
    // position is out of bounds
    return std::numeric_limits < int >::max();
};

int LinkedList::search(int target){
    // variable to hold the index
    int index = 1;
    // loop through the list
    Node* current_node = head;
    while(current_node != nullptr){
        // if the current node's data is the taget
        if (current_node->data == target){
            // return the data at that node
            return index;
        } else{
            // change the current node to be the next one
            current_node = current_node->link;
        }
        // increment the index
        index++;
    }
    // target not found
    return -1;
}

// method to print the linked list
void LinkedList::printList(){
    // variable to hold address of the current node
    Node* current_node = head;

    // if there are any values in the list
    // print the bracket
    if (current_node != nullptr){
        std::cout << "[";
    }
    
    // run a for loop to keep printing, until the current_node
    // is a nullptr
    while (current_node != nullptr){

        // print the value at the node
        std::cout << current_node->data;
        // set the current node to the next one
        current_node = current_node->link;

        // if the current node is now a nullptr
        // print the bracket
        if (current_node == nullptr){
            std::cout << ']' << std::endl;
        } else {
            // there is stil more values
            std::cout << ' ';
        }
    }
}
