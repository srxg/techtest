#ifndef NODE
#define NODE

struct node_t {
    unsigned v;
    struct node_t* next;
};

struct node_t* even_nodes(struct node_t** head);

#endif