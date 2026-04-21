#include <cs50.h>
#include <stdio.h>
#include <string.h>

// usually, the code starts with int main(void), the int declaration is because, errors are commonly refered to as numbers, so if an exception occurs we can add an error
// code or message to the specific error.
// The main parameter is usually void; empty. But if it is needed, we can insert arguments into the main function to use them later, for example here for the code to
// actually run we need to insert a parameter when running it (e.g. ./string parameter)
int main(int argc, string argv[]) {
    // argc here being the quantity of parameters inserted, and argv[] being the list of parameters inserted in string format. The parameters here are ["./string", "<parameter>"].
    if (argc < 2) {
        printf("not enough arguments");
        return 1;
    }

    string s = get_string("Input: ");

    if (s[0] == 0) {
        printf("Input not defined");
        return 2;
    }

    // technically, strings are not actually a data type, instead strings are a function imported from the string.h library that are actually just an array of characters.
    // and whenever we call a string, this function iterate through all its characters searching for a null character ('\0') that indicates the end of the string
    printf("Output: ");
    for (int i = 0; s[i] != '\0'; i++) {
        // so, here we are actually printing characters exactly how we would print a string
        printf("%c", s[i]);
    }
    printf("\n\n");

    // here, the function strlen from the string.h library is used to iterate through every character in a string until it finds a null character and store that distance
    // between the start of the string and its end to determine its length.
    for (int i = strlen(s); i >= 0; i--) {
        printf("%c", s[i]);
    }

    // of course, there are many functions in many libraries that already do all of these things, but if it is ever relevant to do so, you can directly alter specific
    // characters from a string by treating it as an array
    printf("\n\n");
    for (int i = 0, n = strlen(s); i < n; i++) {
        // this, for example, is a way of changing a string from lowercase to uppercase by going to the character 32 characters before the current one according to the
        // ASCII table, this could be done by using the <ctype.h> toupper() function.
        if (s[i] >= 'a' && s[i] <= 'z') {
            printf("%c", s[i]-32);
        }
        else {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    // this is the error code usually returned when no error has ocurred at the end of the main function
    return 0;
}
// if we want to see the error code in the terminal, we can always run "echo $?" for outputting the last returned value
