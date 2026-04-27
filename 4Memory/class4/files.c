//#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // here we create a variable of the type FILE, which is a standard C type that stores an actual file and we open the file by using
    // the function fopen() which takes in two arguments: the name of the file; and how it will be open: "a" is for append, which means
    // we will write something at the end of the text of the file; "r" is for read, which means we will just look at its contents; and
    // "w", which is to overwrite all of the contents of the file.
    FILE *file = fopen("phonebook.txt", "a");
    if (file == NULL){
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // here we basically printf some data inside a file by using "fprintf"
    fprintf(file, "%s, %s\n", name, number);

    // here we close the file to avoid memory leaks
    fclose(file);
}
