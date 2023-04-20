#include <iostream>
#include <string>
#include "node.h"

// should remove all nodes with even values from the indicated list, put them in a new list
// which is returned
struct node_t* even_nodes(struct node_t** head) {
    node_t* previous = nullptr;
    node_t* newhead = nullptr;
    node_t* newtail = nullptr;
    
    node_t* current = *head;
    
    while(current != nullptr) {
        // remove current from the original if it holds an even value
        if(current->v % 2 ==0) {
            // if the new list is empty, set it's head to the current (even) node
            if (newhead == nullptr) newhead = current;
            // otherwise just add the current node to the end of the new list
            else newtail->next = current; 

            // so the new tail is the current even node
            newtail = current;

            // now remove it from the old list
            // if the current node is the head of the list,
            // set the head of the original list
            // to the next node in the original list 
            if (previous == nullptr) *head = current->next;
            // otherwise, make the previous node point to the node after the current node
            else previous->next = current->next;

            // now move to the next node in the original list
            current = current->next;
            // the new node in our list should point to nothing as being the next node
            newtail->next = nullptr;
        } else {
            // it's odd, so just move to the next node
            // without removing the current node from the original list (or adding to the newlist)
            previous = current;
            current = current->next;
        }
    }
    // return the head of the new list
    return newhead;
};