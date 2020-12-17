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

void equality_test() {
    printf("EQUALITY TEST\n");
    btree *init = bintree_init(0);
    btree *left = bintree_init(1);
    btree *right = bintree_init(2);

    init->left  = left;
    init->right = right;

    btree *same_init = bintree_init(0);
    btree *same_left = bintree_init(1);
    btree *same_right = bintree_init(2);

    same_init->left  = same_left;
    same_init->right = same_right;

    printf("1, %zu\n", equality(init, same_init));

    btree *archi_init = bintree_init(0);
    btree *archi_left = bintree_init(1);

    archi_init->left  = archi_left;

    printf("0, %zu\n", equality(init, archi_init));

    btree *key_init = bintree_init(0);
    btree *key_left = bintree_init(3);
    btree *key_right = bintree_init(2);

    key_init->left  = key_left;
    key_init->right = key_right;
    
    printf("0, %zu\n", equality(init, key_init));

    bintree_free(init);
    bintree_free(archi_init);
    bintree_free(key_init);
}

void is_sub_tree_test() {
    printf("SUB TREE TEST\n");
    btree *init = bintree_init(0);
    btree *left = bintree_init(1);
    btree *right = bintree_init(2);

    init->left  = left;
    init->right = right;

    btree *same_init = bintree_init(0);
    btree *same_left = bintree_init(1);
    btree *same_right = bintree_init(2);

    same_init->left  = same_left;
    same_init->right = same_right;

    printf("1, %zu\n", is_sub_tree(init, same_init));

    btree *archi_init = bintree_init(2);

    printf("1, %zu\n", is_sub_tree(init, archi_init));

    btree *key_init = bintree_init(0);
    btree *key_left = bintree_init(3);
    btree *key_right = bintree_init(2);

    key_init->left  = key_left;
    key_init->right = key_right;
    
    printf("0, %zu\n", is_sub_tree(init, key_init));

    bintree_free(init);
    bintree_free(archi_init);
    bintree_free(key_init);
}

void is_degenerate_test() {
    printf("DEGENERATE TEST\n");
    btree *init = bintree_init(0);
    btree *left = bintree_init(1);
    btree *right = bintree_init(2);

    printf("1, %zu\n", is_degenerate(init));    
    init->left  = left;
    printf("1, %zu\n", is_degenerate(init)); 
    init->right = right;
    printf("0, %zu\n", is_degenerate(init));
    init->right = NULL;
    btree *leftleft = bintree_init(3);
    init->left->left = leftleft;
    printf("1, %zu\n", is_degenerate(init));
    
    bintree_free(init);
}

void is_perfect_test() {
    printf("PERFECT TEST\n");
    btree *init = bintree_init(0);
    btree *left = bintree_init(1);
    btree *right = bintree_init(2);

    printf("1, %zu\n", is_perfect(init));    
    init->left  = left;
    printf("0, %zu\n", is_perfect(init)); 
    init->right = right;
    printf("1, %zu\n", is_perfect(init));
    
    btree *leftleft = bintree_init(3);
    btree *leftright = bintree_init(4);
    btree *rightleft = bintree_init(5);
    btree *rightright = bintree_init(6);
    init->left->left = leftleft;
    printf("0, %zu\n", is_perfect(init)); 
    init->left->right = leftright;
    printf("0, %zu\n", is_perfect(init)); 
    init->right->left = rightleft;
    printf("0, %zu\n", is_perfect(init)); 
    init->right->right = rightright;
    printf("1, %zu\n", is_perfect(init)); 
    
    bintree_free(init);
}
