// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

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
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{   
    unsigned int hashedWord = toupper(word[0]) - 'A';
    return hashedWord;
}

// Loads dictionary into memory, returning true if successful, else false
int numberOfWords;
bool load(const char *dictionary)
{   
    for (int i = 0; i < N; i++) {
        table[i]->next = NULL;
    }

    FILE *file = fopen(dictionary, "r");
    if (file == NULL) {
        return false;
    }

    char *currentWord;
    unsigned int letterIndex;
    while (fscanf(file, "%s", currentWord) != EOF) {
        numberOfWords++;
        node *newNode = malloc(sizeof(node));
        
        if (newNode == NULL) {
            return false;
        }
        
        newNode->next = NULL;
        strcpy(newNode->word, currentWord);

        letterIndex = hash(currentWord);

        // se tiver uma palavra onde queremos colocar
        if (table[letterIndex]->next == NULL) {
            table[letterIndex]->next = newNode;
        }
        else {
            newNode->next = table[letterIndex]->next;
            table[letterIndex]->next = newNode;
        }
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
