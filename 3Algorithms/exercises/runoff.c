#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int MAX_CANDIDATES = 9;

typedef struct {
    bool canWin;
    string name;
    int votes[MAX_CANDIDATES];
} candidate;

int winner_runoff(int voters, candidate candidateList[], int candidates);
int vote(int voters, candidate candidateList[], int candidates);

int main(int argc, string argv[]) {
    candidate candidates[argc];

    int voters = get_int("Number of voters: ");

    for (int i = 0; i < argc-1; i++) {
        candidates[i].name = argv[i+1];
        candidates[i].canWin = true;
        for (int j = 0; j < voters; j++) {
            candidates[i].votes[j] = 0;
        }
    }

    vote(voters, candidates, argc-1);
    winner_runoff(voters, candidates, argc-1);

    return 0;
}

int recursion = 0;

int winner_runoff(int voters, candidate candidateList[], int candidates) {
    int highestVotes = 0;
    string winner;

    for (int i = 0; i < candidates; i++) {
        if (candidateList[i].votes[recursion] > highestVotes && candidateList[i].canWin) {
            highestVotes = candidateList[i].votes[recursion];
            winner = candidateList[i].name;
        }
        else if (candidateList[i].votes[recursion] < highestVotes) {
            candidateList[i].canWin = false;
        }
    }

    int amountOfWinners = 0;
    for (int i = 0; i < candidates; i++) {
        if (candidateList[i].votes[recursion] == highestVotes && candidateList[i].canWin) {
            amountOfWinners++;
        }
    }

    if (amountOfWinners == 1) {
        printf("%s\n", winner);
        return 0;
    }
    else if (recursion < candidates) {
        recursion++;
        winner_runoff(voters, candidateList, candidates);
    }
    else {
        string winners[amountOfWinners];
        int counter = 0;
        for (int i = 0; i < amountOfWinners; i++) {
            if (candidateList[i].votes[recursion] == highestVotes && candidateList[i].canWin) {
                winners[counter] = candidateList[i].name;
                counter++;
            }
        }
        for (int i = 0; i < counter; i++) {
            printf("%s ", winners[i]);
        }
        printf("\n");
    }
    return 0;
}

int vote(int voters, candidate candidateList[], int candidates) {
    string currentVote;

    for (int i = 0; i < voters; i++) {
        for (int j = 0; j < candidates; j++) {
            currentVote = get_string("Rank %d: ", j+1);
            for (int k = 0; k < candidates; k++) {
                if (strcmp(candidateList[k].name, currentVote) == 0) {
                    candidateList[k].votes[j]++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
