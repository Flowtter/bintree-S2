#ifndef BINARY_TREE
#define BINARY_TREE

#include <stdio.h>
#include <stdlib.h>

typedef struct bintree btree;
struct bintree {
    int key;
    struct bintree *left;
    struct bintree *right;
};

btree *bintree_init(int value);
void bintree_free(btree *bintree);
size_t size(btree *bintree);
int height(btree *bintree);

#endif // BINARY_TREE
