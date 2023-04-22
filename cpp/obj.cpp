#include<iostream>
#include "obj.h"

int Obj::count = 0; 

Obj::Obj() {
    Obj::count++;
}

Obj::~Obj() {
    Obj::count--;
}

int Obj::nobjs() {
    return Obj::count;
}