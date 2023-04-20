#include <stdio.h>
#include <stdlib.h>


void reverse_bits(unsigned char* currentByte) {
    unsigned char reversed = 0;
    int n = 8;
    for(int i = 0; i < n; i++) {
        reversed |= ((*currentByte >> i) & 1) << (n-1-i);
        /**
         * Explanation:
         * first right shift the bits by i
         * we're counting FROM the RIGHTmost bit, the lsb, as being position 0
         * then, mask all the bits apart from the rightmost after the right shift
         *    rightmost bit remains unchanged this way (it's anded with 1)
         *    all other bits are set to 0
         *    so ((*currentByte >> i) & 1) would be
         *    00000001 or 00000000 if rightmost is 1 or 0 respectively.
         * left shift by 7-i
         *    this takes the isolated bit to it's reversed position
         * result |= accumulates the reversed bit in the result var
         *    OR ensures that the previously set bits in result remain unchanged
         *    and the newly reversed bit is added to its new position
         *
        */
    }
    *currentByte = reversed;
}

void reverse_bytes(unsigned char* ptr, int n) {
    // reverse every the bits in every byte
    for(int i = 0; i < n; i++) {
        reverse_bits(&ptr[i]);
    }

    // we have to go through half the bytes to swap their positions
    // with their complements
    // swapping them all would put them back in their original positions
    for(int i = 0; i < (n/2); i++) {
        int comp_i = (n-1)-i;
        // swap em
        unsigned char temp = ptr[i];
        ptr[i] = ptr[comp_i];
        ptr[comp_i] = temp;
    }
    if(n % 2 != 0) {
        // reverse the middle byte one more time
        // cancels out the double reversal
        reverse_bits(&ptr[n/2]);
    }
}

int main() {
    unsigned char buffer[] = {0x12, 0x34, 0x56, 0x78, 0x31};
    int n = sizeof(buffer) / sizeof(buffer[0]);

    printf("Original buffer: ");
    for (int i = 0; i < n; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    reverse_bytes(buffer, n);

    printf("Reversed buffer: ");
    for (int i = 0; i < n; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    return 0;
}