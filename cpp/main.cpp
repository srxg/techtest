#include <iostream>
#include <string>
#include "obj.h"
#include "node.h"

void print_list(struct node_t* head) {
    struct node_t* current = head;
    while (current != nullptr) {
        std::cout << current->v << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n" << std::endl;
}

int main() {
    Obj test = Obj();
    Obj test2 = Obj();
    Obj test3 = Obj();
    test3.~Obj();
    std::cout << std::to_string(test3.nobjs()) << std::endl;

    struct node_t* head = NULL;
    struct node_t* even_head = NULL;

    // Insert some sample data into the original list
    struct node_t* new_node;
    for (unsigned i = 10; i > 0; i--) {
        new_node = new node_t;
        new_node->v = i;
        new_node->next = head;
        head = new_node;
    }

    std::cout << "Original list:" << std::endl;
    print_list(head);

    even_head = even_nodes(&head);

    std::cout << "List after removing even nodes:" << std::endl;
    print_list(head);

    std::cout << "New list with even nodes:" << std::endl;
    print_list(even_head);

    // Free memory
    struct node_t* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    while (even_head != nullptr) {
        temp = even_head;
        even_head = even_head->next;
        delete temp;
    }

    return 0;
}