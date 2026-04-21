#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int ASCII_TO_POSITION = 65;

int compute_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // check winner of scrabble game
    if (score1 > score2) {
        printf("PLAYER 1 WINS!\n");
    }
    else if (score2 > score1) {
        printf("PLAYER 2 WINS!\n");
    }
    else {
        printf("DRAW!\n");
    }

    return 0;
}

int compute_score(string word)
{
    int score = 0, letterPosition;
    for (int i = 0, n = strlen(word); i < n; i++) {
        if (toupper(word[i]) >= 'A' && toupper(word[i]) <= 'Z') {
            letterPosition = toupper(word[i]) - ASCII_TO_POSITION;
            score = score + POINTS[letterPosition];
        }
    }
    return score;
}
