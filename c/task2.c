#include <stdio.h>
#include <string.h>

char *f(int m) {
    char buf[6]; // we should be allocating heap memory here
    int x; // this doesn't seem to be used in any meaningful way

    // x hasn't been initialised and it's being used in the if
    if (m == 1 && x--) {
        // buffer overflow - doesn't account for \0
        strcpy(buf, "AAAAAA");
        // returning the address of a local variable
        // buf is only on the stack, so this is just going to point to
        // invalid memory
        return buf;
    } else if (m == 2) {
        /**
         * using malloc but we haven't included <stdlib.h> - implicit declaration
         * no check to see if the malloc was successful either
         *     simple if (msg == NULL) {//handle the error and exit} would do 
         * 
         * 100 bytes? we only need 7 here - wastes memory
        */
        char *msg = (char *) malloc(100);
        strcpy(msg, "BBBBBB");
        /*
        * could lead to memory leaks
        *   returning a pointer to memory on the heap
        *   but whoever calls the function needs to free this memory eventually
        */ 
        return msg;
    }
    // no value will be returned if none of the conditionals are met
}

int main(int argc, char **argv) {
    char *m;
    m = f(argc);
    putchar(m[0]);
    return 0;
}