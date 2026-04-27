#include <stdio.h>

int main(void) {
    int x;
    printf("x: ");
    // instead of using get_int from the cs50 library we can use scanf to read an integer and store it in the memory address of x
    scanf("%i", &x);
    printf("x: %i\n", x);

    // here we cannot simply use the address of a string to write a string, because that could result in us overwriting something important
    // and scanf as a safety mechanism won't do that
    //char *s; 
    // so to fix that, we can allocate a space of memory to the variable we are attributing a value to, either by using malloc or by 
    // creating an array, which is just that, a sequential space of memory
    char s[10];
    printf("s: ");
    // reminder that a string is already just a memory address, so we don't need to find its address in this scanf by using the "&"
    scanf("%s", s);
    printf("%s", s);

    // another important definition of memory is a buffer, which is just a chunk of memory that we can use as we see fit, so when we go past
    // the limit of an array, we get what is called a buffer overflow. Also, when we are "resetting a buffer" after using scanf to read
    // strings, we are essentially deallocating or freeing that chunk of memory so that it can be used later.
}