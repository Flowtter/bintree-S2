#include "binary_tree.h"
#include "queue.h"

void size_test() {
    printf("SIZE TEST\n");
    btree *init = bintree_init(0);
    printf("1, %zu\n", size(init));
    btree *left = bintree_init(1);
    init->left = left;
    printf("2, %zu\n", size(init));
    btree *right = bintree_init(2);
    init->right = right;
    printf("3, %zu\n", size(init));
    bintree_free(init);
}
