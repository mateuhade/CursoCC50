// NOTE 5

// Hash functions
// We won't implement any code for this, but imagine we have a list of names and we want to search for a specific name,
// in that case we might want to search by alphabetical order, so we would create an array of A-Z indices so that we can
// just get the indice of the first letter of that name and instantly find it in that list, but once there are two people
// with the same first letter of the name, we will run into a problem, so in that case we might create an array of 26
// letters inside every indice so that we go from Aa to Zz, and if the same problem happens we just do the same again and
// again, and a Hash table is just that, an array of linked lists Although, even though with that approach we might reach 
// O(1) or big O of linear time, which is the best possible time, we obviously consume a lot of space.


// Tries
// A trie, short for retrieval, is a tree of linked lists. Let's imagine the same list of names, at the root of our trie, 
// we have an array A-Z which we will iterate from, if the name we're searching for is Harry, then we will go to list[H],
// and in that position we will have a pointer to another list from A-Z, so we will go to list[H]->list[A]->list[R]...
// until we find the name we are searching, giving us a O(1) determined only by the length of the name, being even better
// than a hash table. Although, we have a worse space problem