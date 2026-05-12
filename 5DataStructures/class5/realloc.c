//NOTE 2
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // here we do the same thing the [] array notation does, we create a contiguous chunk of memory that
    // has space for 3 integers
    int *list = malloc(3 * sizeof(int));
    if (list == NULL) {
        free(list);
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // so now let's suppose we need another space of memory to store another number into this list
    // int *tmp = malloc(4 * sizeof(int));
    // Sure, we could use the malloc function and copy every single item from list with the wrong size to
    // the list with the right size, but we could also just use the realloc function
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL) {
        free(tmp);
        return 2;
    }
    tmp[3] = 4;

    free(list);
    list = tmp;


    free(list);
}