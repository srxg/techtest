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
    // Test case 1
    std::cout << "Number of objects created: " << Obj::count << std::endl;

    {
        Obj obj1;
        Obj obj2 = obj1;
        Obj obj3;
        obj3 = obj1;
        obj1 = obj3;
        std::cout << "Number of objects created: " << obj1.nobjs() << std::endl;
    }

    std::cout << "Number of objects created: " << Obj::count << std::endl;

    // Test case 2
    {
        Obj obj1;
        Obj obj2 = obj1;
        Obj obj3;
        obj3 = obj1;
        obj1 = obj3;
        std::cout << "Number of objects created: " << obj1.nobjs() << std::endl;

        {
            Obj obj4;
            std::cout << "Number of objects created: " << obj1.nobjs() << std::endl;
        }

        std::cout << "Number of objects created: " << obj1.nobjs() << std::endl;
    }

    std::cout << "Number of objects created: " << Obj::count << std::endl;

    // Test case 3
    Obj* obj_ptr = new Obj();
    std::cout << "Number of objects created: " << obj_ptr->nobjs() << std::endl;
    delete obj_ptr;

    std::cout << "Number of objects created: " << Obj::count << std::endl;

    return 0;
}