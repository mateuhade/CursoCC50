#include <stdio.h>
#include <string.h>
//#include <cs50.h>

int main(void) {
    int n = 50;
    // by using the operator "&" we can refer to the address where the variable n is stored, and by using the template %p we can print out
    // not the variable n, but its address in hexadecimal.
    printf("%p\n", &n);

    // by using the operator "*" we can refer to the variable that is stored in "&n", in this case, printing the value of n
    printf("%d\n", *&n);
    // %p is the template for a pointer, which is a type of variable that stores the address of another variable

    // here we declare a pointer that stores the address of the int n, it is important to say that p is not an int, it's an int star, essentially
    // an address pointer.
    int *p = &n;
    printf("%p\n", p);
    printf("%p\n", *p); // because pointers are in hex when we print out an int using the pointer template we will get the int in its hexadecimal form
    printf("%i\n", *p);

    // given that a string is just an array of characters, when we call a pointer to a string, it only points to the address of the first character of
    // it, that is because every string ends with a NULL character, so the compiler will read all of the subsequent adddresses starting at the first
    // character of a string until it finds that NULL character.
    //string s = "Hi!";
    //printf("%p\n", s);     // prints out the address to the first character of the string
    //printf("%p\n", &s[0]);
    //printf("%p\n", &s[1]); // prints out the address to the second character of the string

    // so like this, we can understand that strings at a very low level are not strings, and also not precisely arrays of characters, but pointers
    // to an array of characters
    char *s = "HI!";   
    printf("\n%s\n", s); // and this is how we print a string using just a pointer to the first character of the string

    printf("%c\n", *s);
    printf("%c\n", *(s+1)); // so by understanding that a string is just a pointer value, we can do math to tht pointer to get to the next byte of
    printf("%c\n", *(s+2)); // that string like this

    return 0;
}