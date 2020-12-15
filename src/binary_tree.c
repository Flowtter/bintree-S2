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

// size_t size(bt *bintree) {
//    size_t counter = 0;
//    //queue q;
//
//    return counter;
//}

// int main() {
//    //bt init = {.key = 0, .left = NULL, .right = NULL};
//    //init.left = &(bt){.key = 1, .left = NULL, .right = NULL};
//    //init.right = &(bt){.key = 2, .left = NULL, .right = NULL};
//    return 0;
//}