// NOTE 3
#include <stdio.h>
#include <stdlib.h>

// Just like in NOTE 1, we create this temporary struct name for the pointer inside teh struct
typedef struct node {
    int number;
    struct node *next;
} node;

int main(void) {
    node *list = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL) {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    n = mallof(sizeof(node));
    if (n == NULL) {
        free(list->next);
        free(list);
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // Here we create a pointer to the start of the linked list (list, which points to the first item on the list) and
    // then we update the value of this pointer every time to point to the next item in the list and keep doing that
    // as long as the pointer inside the node that tmp is pointing at is not NULL
    for (node *tmp = list; tmp != NULL; tmp = tmp->next) {
        printf("%i ", tmp->number);
    }

    while (list != NULL) {
        // Here we create a pointer to the second item in the list
        node *tmp = list->next;
        // Here we free the first item in the list
        free(list);
        // and then we make that first "list" pointer point also to the second item in the list, which is now the first.
        list = tmp;
        // and this is looped, freeing the first item and making the first item the next one that isn't free yet until
        // there is no pointer anymore, and in that case we exit the while loop;
    }

    // last thing, like in the while loop, if we want to insert a number somewhere in a linked list, we must first make
    // the pointer point to the node after the one that we want to insert, and only then point the previous node to the
    // current node
    // node *newNode->next = list;
    // list = newNode;
    // that is because if we first point the list to the new node, we won't be able to find the second node again via the
    // ->next notation, by definition, orphaning it.
    return 0;
}