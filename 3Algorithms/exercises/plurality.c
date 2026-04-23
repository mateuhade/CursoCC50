#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    string name;
    int votes;
} candidate;

bool vote(string currentVote, int numberOfCandidates, candidate candidateList[]);
int print_winner(int candidates, candidate candidateList[]);

int main(int argc, string argv[]) {
    candidate candidates[argc];

    for (int i = 0; i < argc-1; i++) {
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
    }

    int voters = get_int("Number of voters: ");
    for (int i = 0; i < voters; i++) {
        vote(get_string("Vote: "), argc-1, candidates);
    }

    print_winner(argc-1, candidates);

    return 0;
}

bool vote(string currentVote, int numberOfCandidates, candidate candidateList[]) {
    for (int i = 0; i < numberOfCandidates; i++) {
        if (strcmp(candidateList[i].name, currentVote) == 0) {
            candidateList[i].votes++;
            return true;
        }
    }
    return false;
}

int print_winner(int candidates, candidate candidateList[]) {
    string winner;
    int numberOfWinners = 1, mostVotes = 0;
    for (int i = 0; i < candidates; i++) {
        if (candidateList[i].votes > mostVotes) {
            mostVotes = candidateList[i].votes;
            winner = candidateList[i].name;
        }
        else if (candidateList[i].votes == mostVotes) {
            numberOfWinners++;
        }
    }

    if (numberOfWinners == 1) {
        printf("%s\n", winner);
        return 0;
    }

    for (int i = 0; i < candidates; i++) {
        if (candidateList[i].votes == mostVotes) {
            printf("%s\n", candidateList[i].name);
        }
    }

    return 0;
}
