#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {

    long creditCard = get_long("type the fucker: ");

    int length;
    if (creditCard > pow(10, 15)) {
        length = 16;
    }
    else if (creditCard > pow(10, 14)) {
        length = 15;
    }
    else if (creditCard > pow(10, 12) && creditCard < pow(10, 13)) {
        length = 13;
        printf
    }
    else {
        printf("invalid number");
        return 0;
    }

    for (i = )
    long test1 = pow(10, 2);
    long test2 = pow(10, 1);
    printf("%ld", 12345678901234 % test1 / test2);
}
