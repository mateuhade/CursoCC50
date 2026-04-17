#include <stdio.h>
#include <cs50.h>

int change(int total);

int main(void) {
    int totalMoneyChange = get_int("Total change: ");

    int test[4] = {0, 0, 0, 0};
    int quarters = 0;
    int currentChange = 0;
    while (currentChange + 25 <= totalMoneyChange) {
        currentChange += 25;
        test[0]++;
    }

    int dimes = 0;
    while (currentChange + 10 <= totalMoneyChange) {
        currentChange += 10;
        test[1]++;
    }

    int nickels = 0;
    while (currentChange + 5 <= totalMoneyChange) {
        currentChange += 5;
        test[2]++;
    }

    int cents = 0;
    while (currentChange + 1 <= totalMoneyChange) {
        currentChange += 1;
        test[3]++;
    }

    printf("quarters: %d\n", test[0]);
    printf("dimes: %d\n", test[1]);
    printf("nickels: %d\n", test[2]);
    printf("cents: %d\n", test[3]);


}

