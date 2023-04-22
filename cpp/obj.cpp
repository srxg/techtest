#include<iostream>
#include "obj.h"

int Obj::count = 0; 

Obj::Obj() {
    Obj::count++;
}

Obj::Obj(const Obj& other_obj) {
    (void)other_obj; // will suppress unused variable warning
    Obj::count++;
}

Obj& Obj::operator=(const Obj& other_obj) {
    if(this != &other_obj) {
        // Copy contents
    }
    // Only increment if a new object is created
    if (this == nullptr) {
        Obj::count++;
    }
    return *this;
}

Obj& Obj::operator=(Obj&& other_obj) noexcept {
    if(this != &other_obj) {
        // Move contents
    }
    // Only increment if a new object is created
    if(this == nullptr) {
        Obj::count++;
    }
    return *this;
}

Obj::Obj(Obj&& other_obj) noexcept {
    (void)other_obj; // will suppress unused variable warning
    Obj::count++;
}

Obj::~Obj() {
    Obj::count--;
}

int Obj::nobjs() {
    return Obj::count;
}