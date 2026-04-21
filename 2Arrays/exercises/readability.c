#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

double textGrader(string text);

int main(void) {
    string text = get_string("Text: ");
    int textGrade = (textGrader(text) + 0.5);

    if (textGrade <= 0) {
        printf("Before Grade 1\n");
    }
    else if (textGrade >= 16) {
        printf("Grade 16+\n");
    }
    else {
        printf("Grade %d\n", textGrade);
    }

}

double textGrader(string text) {

    int wordCounter = 1, letterCounter = 0, sentenceCounter = 0;
    for (int i = 0, n = strlen(text); i < n; i++) {
        char upperLetter = toupper(text[i]);
        if (upperLetter == ' ') {
            wordCounter++;
        }
        else if (upperLetter >= 'A' && upperLetter <= 'Z') {
            letterCounter++;
        }
        else if (upperLetter == '.' || upperLetter == '!' || upperLetter == '?') {
            sentenceCounter++;
        }
    }

    float averageLetters = (float) letterCounter / wordCounter * 100.0;
    float averageSentences = (float) sentenceCounter / wordCounter * 100.0;

    double index = 0.0588 * averageLetters - 0.296 * averageSentences - 15.8;
    return index;
}
