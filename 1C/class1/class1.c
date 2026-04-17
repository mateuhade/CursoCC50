#include <stdio.h>
#include <cs50.h>

// there are a few IDE's that don't compile your code automatically, to do that, you just need to type in the terminal "make <file name>" (while in the file directory)
// and then do ./<file name> to execute the file
int main(void) {
    string test = get_string("What is your name? ");
    printf("Hello, %s\n", test);

}
