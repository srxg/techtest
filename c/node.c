#include<stdlib.h>
#include "node.h"

// removes all nodes with even values from the indicated list. Returns these evens in a list
struct node_t* even_nodes(struct node_t** head) {
    struct node_t* previous = NULL; // the node which comes before currentnode in the original list
    struct node_t* newhead = NULL;
    struct node_t* newtail = NULL;

    struct node_t* currentnode = *head;

    while(currentnode != NULL) {
        // remove current from the original if it holds an even value
        if(currentnode->v % 2 == 0) {
            // if the new list hasn't yet started
            // set it's head to the current (even) node
            if(newhead == NULL) newhead = currentnode;
            // otherwise just add the current node to the end of the new list
            else newtail->next = currentnode;
            // so the new tail is the current even node
            newtail = currentnode;
            
            // now remove it from the old list
            // if the current node is the head of the list,
            // set the head of the original list
            // to the next node in the original list 
            if(previous == NULL) *head = currentnode->next;
            // otherwise, make the previous node point to the node after the current node
            else previous->next = currentnode->next;

            // now move to the next node in the original list
            currentnode = currentnode->next;
            // the new node in our list should point to nothing as being the next node
            newtail->next = NULL;
        } else {
            // it's odd, so just move to the next node
            // without removing the current node from the original list (or adding to the newlist)
            previous = currentnode;
            currentnode = currentnode->next;
        }
        
    }
    return newhead;
}