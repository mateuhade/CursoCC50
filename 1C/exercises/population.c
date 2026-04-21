#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    int startSize;
    do {
        startSize = get_int("Initial population size: ");
    } while (startSize < 9);

    int finalSize;
    do {
        finalSize = get_int("Final population size: ");
    } while (finalSize < startSize);

    int currentSize = startSize;
    int populationGained, populationLost;
    int yearCounter = 0;
    while (currentSize < finalSize) {
        populationGained = currentSize / 3;
        populationLost = currentSize / 4;
        currentSize = currentSize + populationGained - populationLost;
        yearCounter++;
    }

    printf("\nYears needed until final population: %d\n", yearCounter);
}
