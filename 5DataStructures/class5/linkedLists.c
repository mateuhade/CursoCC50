//NOTE 1
#include <stdio.h>
#include <stdlib.h>

// Here we create a node, which is a struct which will refer to itself later, the core of a linked list, syntax in following comment
typedef struct node { 
    int number;
    // before of this we ended up having to declare the struct name before the end of the structure, that is because if we
    // create a pointer to a node before the name "node" is declared as a structure, the data type node won't exist yet.
    // And right here, we declare the pointer next as a node which is a struct that is yet to be closed.
    struct node *next;
} node;

// -----------------START READING FROM MAIN---------------------
int main(void) {
    // lets create an array of size 3
    int array1[3] = {1, 2, 3};

    // nvm i need an array of size 4, but i don't want to lose the data from the first array, and i cant just add it after
    // the old array buffer, because there might be some important data right after it that i dont want to lose
    int array2[4];
    for (int i = 0; i < sizeof(array1); i++) {
        array2[i] = array1[i];
    }
    // but there is a problem with this resizing method, the big O of this code section is O(n), which means, if we have
    // an array of a billion indices, we'll need to copy a billion indices into the new array
    array2[4] = 4;

    // To fix this problem, we are going to use Linked Lists
    // Linked lists are similar to arrays, which store various data values of a single type into a list, except that they
    // aren't contiguous, that means, the data isn't directly after the last data value inside the memory. Instead of that,
    // they take a bit more space to store a pointer to where the next data value is inside the memory, and when they reach
    // the last value, its respective pointer is 0x0, or NULL ---------REFERENCE TO NODE STRUCT-------------

    // ---------------------------------------LINKED LISTS-----------------------------------------
    // here we create pointer to a node, called list, that isn't pointing at anything
    node *list = NULL;
    // here we create a pointer to a node, called n, that is pointing to a space in memory that is the size of our node struct.
    // Reminder that the function malloc always returns a memory address
    node *n = malloc(sizeof(node));
    if (n != NULL) {
        // Here we go into the address of the pointer n and attribute the value of the member number of the node n to 1
        (*n).number = 1;
        // Since the (*n).member syntax is a bit confusing and dense, we can use the arrow operator (->)
        // Here the arrow goes into the address of the pointer n and into the member next of the node n, like the last line of code
        n->next = NULL;
    }

    // since N is just a temporary variable, we store the start of the list in the node LIST, which will point to the start of
    // the linked list
    list = n;
    // Here we do the same thing as before, creating a new node and attributing it a number and address
    node *n = malloc(sizeof(node));
    if (n != NULL) {
        n->number = 2;
        n->next = NULL;
    }
    // Although, this isn't part of the data structure we made just yet, that is becasue the first node is still not pointing anywhere
    // So we just make the first item of the list point to the next one
    list->next = n;
    
    // Same thing here, creating the third node and not pointing it anywhere
    node *n = malloc(sizeof(node));
    if (n != NULL) {
        n->number = 3;
        n->next = NULL;
    }
    // And same problem, but the syntax is just a bit different, here we go into the address of the list, then into the address inside
    // that first address, and then the address inside that second address and then attribute it to the pointer to the next item
    list->next->next = n;
    // Although, we will rarely use this syntax since we could do this better inside a loop just updating n every iteration

    // And the benefit of using a linked list is primarily that the big O of inserting in this data structure is O(1) or O of constant 
    // time, since, if we don't care if the list is organized or not, we could always just change the "list" pointer to point into the
    // new element we want to insert into the list, and then change that next pointer to point into the second element.


    return 0;
}