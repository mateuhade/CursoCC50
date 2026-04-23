#include <cs50.h>
#include <stdio.h>
#include <string.h>

// here we create a type of variable called person that contains two variables inside it, this is named data structures
typedef struct {
    string name;
    string number;
} person;

int main(void) {
   // an array can be attributed by attributing it to a list of values inside curly braces, like as following
 // string names[] = {"Mateus", "Raphael"};
   // when a variable is attributed at the same time it is declared, that is called an initialization of a variable
 // string numbers[] = {"+55(62)99382-0546", "+55(62)99364-0178"};

    // here we create an array of variables of the type person, just like we would create an array of a string or an integer
    person people[2];
    // here we go into the first variable of the array people, and by using the .<variable> we access the variable determined at the definition of the type person
    people[0].name = "Mateus";
    people[0].number = "+55(62)99382-0546";

    people[1].name = "Raphael";
    people[1].number = "+55(62)99364-0178";

    for (int i = 0; i < 2; i++) {
        // strcmp is an string.h function that compares two strings and returns 0 when both strings are the same, a negative number when the first string comes
        // before the second ASCIIbetically (alphabetically but using ascii), or a positive number when the first comes after the second
        if (strcmp(people[i].name, "Raphael") == 0) {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
