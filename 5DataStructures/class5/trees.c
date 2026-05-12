//NOTE 4
#include <stdio.h>
#include <stdbool.h>
// Here we'll start studying trees, so refer to NOTE 3 and before for linked lists

// Here are the nodes used in a tree data structure, graphically they are similar to family trees, branching
// off in two directions at every item. This is specifically a binary search tree, which means, the pointer
// to the right will always point to a number greater than the current number, and the pointer to the left
// will  point to a number lesser than the current number. Achieving, when searching, a O(log(n)).
typedef struct node {
    int number;
    // the nodes in which 
    struct node *left;
    struct node *right;
} node;

int main(void) {


    return 0;
}

// here we create a search funtion which will search for an "int number" in a tree, if it does not exist, it'll
// return false, and if it does, it'll return true.
bool search(node *root, int number) {
    if (root == NULL) {
        return false;
    }
    // recursion being sick and extremely confusing as always
    else if (number < root->number) {
        return search(root->left, number);
    }
    else if (number > root->number) {
        return search(root->right, number);
    }
    else if (number == root->number) {
        return true;
    }
    else {
        return false;
    }


}