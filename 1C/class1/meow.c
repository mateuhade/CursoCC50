#include <stdio.h>
#include <cs50.h>

// this is a prototype, that means, when the main code tries to execute a function that does not exist yet, it will generate a bug. So to solve that, we use prototypes to
// tell the compiler that the funtion that needs to be executed does exist and it just needs to read further
void meow(int repeat);
int ntimes(void);


int main(void) {

    // when getting a value from a function, we also need to declare the variable in which the return of the function will be stored in
    int n = ntimes();

    // because of the prototype, when this function is called, the compiler will skip to the end of the main function and try to find the meow() function, when it does
    // it will come back to execute the rest of the code
    meow(n);

    return 0;
}

// this function is declared as void because it does not return any value
void meow(int repeat) {
    for (int i = 0; i < repeat; i++) {
        printf("Meow\n");
    }
}

// this function is declared as int because it returns an integer value
int ntimes(void) {
    int n;
    do {
        n = get_int("How many times do you want this to repeat? ");
    }
    while (n < 1);

    return n;
}
