#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

string caesar_Cypher(int key, string plainText);
int isNumber(string value);

int main(int argc, string argv[]) {
    // exception if wrong number of arguments
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // exception if wrong data type of argument
    else if (!isNumber(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 2;
    }

    string plainText = get_string("Plaintext: ");
    string cipherText = caesar_Cypher(atoi(argv[1]), plainText);

    printf("Ciphertext: %s\n", cipherText);

    return 0;
}

// checks if a string contain only numbers inside it, so that it can be converted later
int isNumber(string value) {
    for (int i = 0, n = strlen(value); i < n; i++) {
        if (value[i] < '0' || value[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// encrypts input text by displacement, if text is abc and key is 1, encrypted text will be bcd, because a is the first letter of the alphabet, b is the second, c=3, etc.
// So if the key 1 is added up to 1 (a), it'll become 2 (b). If the letter encrypted goes past z, it should loop back to the start of the alphabet (z+1=a; m+17=e; y+4=b)
string caesar_Cypher(int key, string plainText) {
    for (int i = 0, n = strlen(plainText); i <= n; i++) {
        if ((plainText[i] >= 'a' && plainText[i] <= 'z')) {
            plainText[i] = ((plainText[i] - 'a' + key) % 26) + 'a';
        }
        else if ((plainText[i] >= 'A' && plainText[i] <= 'Z'))  {
            plainText[i] = ((plainText[i] - 'A' + key) % 26) + 'A';
        }
        // if character is not letter, maintain as is
        else {
            plainText[i] = plainText[i];
        }
    }
    return plainText;
}
