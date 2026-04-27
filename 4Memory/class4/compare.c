// #include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char *s = "hi!";
    //char t[50];
    //scanf("%s", t);

    // the result of this operation will always be different, that is because a string is just a pointer to an adress in the computer memory,
    // so we are not actually comparing two strings, we are comparing two adresses
    //if (s == t) {  
    //    printf("Same\n");
    //}
    //else {
    //    printf("Different\n");
    //}

    // in the same way, this function of toupper() will not only change the first letter of the string r, but also the string s, because
    // when initializing the variable r, we are giving it the same address as the variable s, and in turn, the same value
    //char *r = s;
    //r[0] = toupper(r[0]);
    //printf("%c\n", r);
    //printf("%c\n", s);

    // so to fix this, we need to create a new allocation in memory to store the new value of g that will be the same as the value of s
    char *g = malloc(strlen(s)+1); // the function malloc does exactly that, it allocates a new space in memory for a variable of n bytes
    for (int i = 0, n = strlen(s); i <= n; i++) {
        g[i] = s[i];
    }
    g[0] = toupper(g[0]);
    printf("s: %s\n", s);
    printf("g: %s\n", g);
    // when we use malloc we allocate a part of the computer memory for something, so it is up to the programmer to give that memory back
    free(g); // to the computer after it's finished using it by using the function free()
}