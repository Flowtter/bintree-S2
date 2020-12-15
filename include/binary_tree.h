#ifndef BINARY_TREE
#define BINARY_TREE

#include <stdio.h>
#include <stdlib.h>

typedef struct bintree bt;
struct bintree {
    int key;
    struct bintree *left;
    struct bintree *right;
};

bt *bintree_init(int value);
void bintree_free(bt *bintree);

#endif // BINARY_TREE
