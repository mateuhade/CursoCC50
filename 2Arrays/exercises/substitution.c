#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string substitution_cipher(string key, string simpleText);


int main(int argc, string argv[]) {
    // exception if wrong number of arguments is typed
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // exception if wrong number of characters in argument
    else if (strlen(argv[1]) != 26) {
        printf("Key must contain 26 letters\n");
        return 2;
    }
    // exception if wrong type of characters in argument
    for (int i = 0; i < 26; i++) {
        if (!isalpha(argv[1][i])) {
            printf("Key must contain only letters\n");
            return 3;
        }
    }
    // exception if repeated characters in argument
    for (int i = 0, letterCounter[25], letterPosition; i < 26; i++) {
        letterPosition = tolower(argv[1][i]) - 'a';
        letterCounter[letterPosition]++;
        if (letterCounter[x] > 1) {
            printf("Key must contain all different letters\n");
            return 4;
        }
    }

    string simpleText = get_string("Simple text: ");
    printf("Ciphered text: %s\n", substitution_cipher(argv[1], simpleText));

    return 0;
}

// cipher input text by substitution, changing every letter a for the first letter in the main argument, every letter b for the second letter in the argument...
string substitution_cipher(string key, string simpleText) {
    for (int i = 0, n = strlen(simpleText), letterPosition; i < n; i++) {
        if ((simpleText[i] >= 'a' && simpleText[i] <= 'z')) {
            letterPosition = simpleText[i] - 'a';
            simpleText[i] = tolower(key[letterPosition]);
        }
        else if ((simpleText[i] >= 'A' && simpleText[i] <= 'Z')) {
            letterPosition = simpleText[i] - 'A';
            simpleText[i] = toupper(key[letterPosition]);
        }
        // if character is not letter, maintain as is
        else {
            simpleText[i] = simpleText[i];
        }
    }

    return simpleText;
}
