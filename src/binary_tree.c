#include "binary_tree.h"
#include "queue.h"

bt *bintree_init(int value) {
    bt *tree = malloc(sizeof(tree));
    tree->key = value;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void bintree_free(bt *bintree) {
    if (bintree->left)
        bintree_free(bintree->left);
    if (bintree->right)
        bintree_free(bintree->right);
    free(bintree);
}