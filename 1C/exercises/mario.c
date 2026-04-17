#include <stdio.h>
#include <cs50.h>

void pyramid(int height);


int main(void) {

    int pyramidHeight;
    do {
        pyramidHeight = get_int("How tall should your pyramid be? ");
    }
    while (pyramidHeight > 8 || pyramidHeight < 1);

    pyramid(pyramidHeight);


    return 0;
}


void pyramid(int height) {

    // prints stairs/pyramid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height-(i+1); j++) {
            printf(" ");
        }

        for (int j = 0; j <= i; j++) {
            printf("#");
        }

        printf("  ");
        for (int j = 0; j <= i; j++)  {
            printf("#");
        }
        printf("\n");
    }
}
