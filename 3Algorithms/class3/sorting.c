#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    int list[8] = {8, 5, 3, 4, 7, 6, 1, 2};

    // linear sorting or selection sorting
    // there's definitively a better way to write this
    for (int i = 0, change, index, smallest; i < 8; i++) {
        smallest = list[i];
        index = 0;
        for (int j = i+1; j < 8; j++) {
            if (list[j] < smallest) {
                smallest = list[j];
                index = j;
            }
        }
        change = list[i];
        list[i] = smallest;
        // this is dumb
        if (index != 0) {
            list[index] = change;
        }
    }

    int list2[8] = {8, 5, 3, 4, 7, 6, 1, 2};

    // bubble sorting
    for (int i = 0, change, index, smallest, changesMade; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            changesMade = 0;
            if (list2[j] > list2[j+1]) {
                change = list2[j];
                list2[j] = list2[j+1];
                list2[j+1] = change;
                changesMade++;
            }
            if (changesMade == 0) {
                return 0;
            }
        }
    }

        for (int i = 0; i < 8; i++) {
        printf("%d ", list[i]);
    }
}
