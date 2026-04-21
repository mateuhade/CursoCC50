#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include <math.h>
#include <string.h>



int main(void) {
    long creditCard = get_long("Type the credit card number: ");

    // checks if the card is valid via it's length
    bool isCardValid = true;
    int length = 0;
    if (creditCard >= pow(10, 15) && creditCard < pow(10, 16)) {
        length = 16;
    }
    else if (creditCard >= pow(10, 14) && creditCard < pow(10, 15) ) {
        length = 15;
    }
    else if (creditCard >= pow(10, 12) && creditCard < pow(10, 13)) {
        length = 13;
    }
    else {
        isCardValid = false;
    }

    // checks first digits to determine the card type later
    int firstDigit = creditCard / (long)pow(10, length-1);
    int firstTwoDigits = creditCard / (long)pow(10, length-2);

    // checks card type and validity via size and first digits
    string cardType = "";
    if (isCardValid && length == 16 && firstTwoDigits > 50 && firstTwoDigits < 56) {
        cardType = "MASTERCARD";
    }
    else if (isCardValid && length == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37)) {
        cardType = "AMERICANEXPRESS";
    }
    else if (isCardValid && (length == 13 || length == 16) && firstDigit == 4) {
        cardType = "VISA";
    }
    else {
        isCardValid = false;
    }

    // Checks if card is valid via math
    if (isCardValid) {
        int oddDigit;
        int sumEvenDigits = 0;
        int multDigits = 0;
        for (int i = 1; i < length+1; i++) {
            if (i % 2 != 0) {
                oddDigit = (int)(creditCard / (long)pow(10, length-i) % 10);
                if (oddDigit * 2 > 10) {
                    multDigits = multDigits + (oddDigit * 2 / 10) + (oddDigit * 2 % 10);
                }
                else {
                    multDigits = multDigits + (oddDigit * 2);
                }
            }
            else {
                sumEvenDigits = sumEvenDigits + (int)(creditCard / (long)pow(10, length-i) % 10);
            }
        }

        if ((multDigits + sumEvenDigits) % 10 != 0) {
            isCardValid = false;
        }
    }

    if (isCardValid) {
        printf("%s\n", cardType);
    }
    else {
        printf("INVALID\n");
    }


    return 0;
}
