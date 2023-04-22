#include <stdlib.h>
/*
* Reverses the order of bits in a given byte.
*/
void reverse_bits(unsigned char* currentByte) {
    unsigned char reversed = 0;
    const int n = 8;
    for(int i = 0; i < n; i++) {
        // n-1-i^th bit gets isolated from everything to its right (0 indexed)
        //         a b c d e f g h
        // suppose 1 0 1 0 1 0 1 0, at the start we isolate
        // the 'h' bit by right shifting it by 0. this takes it to
        // the last position in the byte.
        // & 1 to set all other bits to the left of the last position to 0
        // (retains the value of the isolated bit only)
        unsigned char i_bit = (*currentByte >> i) & 1;
        // move the isolated bit to its reversed position
        unsigned char reversed_bit = i_bit << (n-1-i);
        // accumulate reversed bits
        reversed |= ((*currentByte >> i) & 1) << (n-1-i);
    }
    *currentByte = reversed;
}

/**
 * Reverses a given array of n bytes such that the first
 * bit of the first byte is swapped with the last bit of the last byte
 * and so forth
*/
void reverse_bytes(unsigned char* ptr, size_t n) {
    for(size_t i = 0; i < (n/2); i++) {
        size_t comp_i = n-1-i;
        unsigned char temp = ptr[i];
        ptr[i] = ptr[comp_i];
        ptr[comp_i] = temp;
    }
    for(size_t i = 0; i < n; i++) {
        reverse_bits(&ptr[i]);
    }

}