// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    node *tmp = table[index];
    while (tmp != NULL) {
        if (strcasecmp(word, tmp->word) == 0) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{   
    unsigned int hashedWord = toupper(word[0]) - 'A';
    return hashedWord;
}

// Loads dictionary into memory, returning true if successful, else false
int numberOfWords = 0;
bool isLoaded;
bool load(const char *dictionary)
{  
    FILE *file = fopen(dictionary, "r");
    if (file == NULL) {
        isLoaded = false;
        return isLoaded;
    }

    char currentWord[LENGTH+1];
    unsigned int letterIndex;
    while (fscanf(file, "%s", currentWord) != EOF) {
        numberOfWords++;
        node *newNode = malloc(sizeof(node));
        
        if (newNode == NULL) {
            isLoaded = false;
            return isLoaded;
        }
        
        newNode->next = NULL;
        strcpy(newNode->word, currentWord);

        letterIndex = hash(currentWord);

        newNode->next = table[letterIndex];
        table[letterIndex] = newNode;
    }

    fclose(file);
    isLoaded = true;
    return isLoaded;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (isLoaded) {
        return numberOfWords;
    }
    else {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{   
    for (int i = 0; i < N; i++) {
        node *tmp1 = table[i];
        while (tmp1 != NULL) {
            node *tmp2 = tmp1->next;
            free(tmp1);
            tmp1 = tmp2;
        }
    }
    return true;
}
