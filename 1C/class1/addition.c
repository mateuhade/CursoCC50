#include <stdio.h>
#include <cs50.h>

int main(void) {
    //the cs 50 library provides the get_<datatype> functions that automatically cleans the buffer when needed and helps with syntax and bugs
    int x = get_int("x: ");
    int y = get_int("y: ");
    
    printf("%i\n", x + y);
}
