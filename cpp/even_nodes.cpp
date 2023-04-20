#include <iostream>
#include <string>
#include "obj.h"

struct node_t {
        unsigned v;
        struct node_t* next;
};

struct node_t* even_nodes(struct node_t** head) {
    node_t* previous = nullptr;
    node_t* newhead = nullptr;
    node_t* newtail = nullptr;
    
    node_t* now = *head;
    
    while(now != nullptr) {
        if(now->v%2==0) {
            // newhead is null, so set it to the current node
            if (newhead == nullptr) {
                newhead = now;
            } else {
                // otherwise, set the next pointer of the newtail to the current node
                newtail->next = now;
            }

            // new end of the list is the current node
            newtail = now;

            // remove the current node from the original list (it's even)
            if (previous == nullptr) {
                // if the previous is null, the current node is the head of the original
                *head = now->next;
            } else {
                // skip the current (even) node - so update the next poitner of the previous
                // node
                previous->next = now->next;
            }
            // move to the next node
            now = now->next;
            // set the next pointer of newtail to null (it's the new node in the new list)
            newtail->next = nullptr;
        } else {
            // the current node is odd so update previous and move to the next node
            previous = now;
            now = now->next;
        }
    }
    // return the head of the new list
    return newhead;
};

// int main() {
//     Obj test = Obj();
//     Obj test2 = Obj();
//     Obj test3 = Obj();
//     test3.~Obj();
//     std::cout << std::to_string(test3.nobjs()) << std::endl;
//     return 1;   
// }