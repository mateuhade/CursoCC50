#include <cs50.h>
#include <stdio.h>
#include <string.h>

float average(int length, int array[]);
// creates a constant, which is a name that contains a value that cannot be altered. It is usually used to store values that will not be changed to make the
// program more readable, for example: const float PI = 3.14159; const int DAYS_IN_WEEK = 7; EULER = 2.71828. By convention, constants are assigned with
// all capital letters
const int TOTAL = 3;

int main(void) {
    // creates an "array" of size "TOTAL", which is a list of values of a constant size and a certain type (int, float, char, etc.) that cannot be changed
    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i++) {
        scores[i] = get_float("Score %d:", i+1);
    }

    // when passing an array as a parameter we dont need to use the brackets [] to pass it
    printf("Average: %f\n", average(TOTAL, scores));
}

// creates a function that will read two values that will be represented as a length and an array of any size and will return a float value
float average(int length, int array[]) {
    // goes through every value of an array and sums all of its values
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum = sum + array[i];
    }
    return (float)sum / length;
}
