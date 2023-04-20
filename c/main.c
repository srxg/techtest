#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void print_list(struct node_t* head) {
    struct node_t* current = head;
    while (current != NULL) {
        printf("%u -> ", current->v);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node_t* head = NULL;
    struct node_t* even_head = NULL;

    // Insert some sample data into the original list
    struct node_t* new_node;
    for (unsigned i = 10; i > 0; i--) {
        new_node = (struct node_t*) malloc(sizeof(struct node_t));
        new_node->v = i;
        new_node->next = head;
        head = new_node;
    }

    printf("Original list:\n");
    print_list(head);

    even_head = even_nodes(&head);

    printf("List after removing even nodes:\n");
    print_list(head);

    printf("New list with even nodes:\n");
    print_list(even_head);

    // Free memory
    struct node_t* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    while (even_head != NULL) {
        temp = even_head;
        even_head = even_head->next;
        free(temp);
    }

    return 0;
}