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

void height_test() {
    printf("HEIGHT TEST\n");
    printf("-1, %d\n", height(NULL));
    btree *init = bintree_init(0);
    printf("0, %d\n", height(init));
    btree *left = bintree_init(1);
    init->left = left;
    printf("1, %d\n", height(init));
    btree *right = bintree_init(2);
    init->right = right;
    printf("1, %d\n", height(init));
    btree *rightright = bintree_init(4);
    init->right->right = rightright;
    printf("2, %d\n", height(init));
    bintree_free(init);
}

void breadth_first_search_test() {
    printf("BREADTH FIRST SEARCH TEST\n");
    btree *init = bintree_init(0);
    btree *left = bintree_init(1);
    btree *right = bintree_init(2);
    btree *leftleft = bintree_init(3);
    btree *leftright = bintree_init(4);
    btree *rightleft = bintree_init(5);
    btree *rightright = bintree_init(6);
    init->left = left;
    init->right = right;
    init->left->left = leftleft;
    init->left->right = leftright;
    init->right->left = rightleft;
    init->right->right = rightright;

    breadth_first_search(init);
    
    bintree_free(init);
}
