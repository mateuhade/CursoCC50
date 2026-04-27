#include <stdio.h>

void swap(int *a, int *b);

// memory is divided between 4 portions, a small part of the memory stores the machine code; another small part of the memory is the global memory
// which stores all of the global variables and contants declared in the code; a big part of the memory stores heap memory, which stores the allocated
// memory, usually managed by the malloc functions and some others which automatically use malloc; and another big part of the memory, that is shared
// with the heap memory, is the stack memory, which stores local variables or parameters from functions. This can couse problems eventually because
// we can end up running out of memory when using a heap portion of memory and instead overwriting a bit of stack memory or vice-versa.
int main(void) {
    int x = 1;
    int y = 2;

    printf("x is %i; y is %i\n", x, y);
    // here, instead of making a function that returns a list of variables or changes the value of a global variable, we actually change directly
    // the value of a heap of memory by giving its address.
    swap(&x, &y);
    printf("x is %i; y is %i", x, y);
    
    return 0;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
