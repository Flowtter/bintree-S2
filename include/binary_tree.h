#ifndef BINARY_TREE
#define BINARY_TREE

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
void breadth_first_search(btree *bintree);
size_t equality(btree *bintree1, btree *bintree2);
size_t is_sub_tree(btree *bintree1, btree *bintree2);
size_t is_degenerate(btree *bintree1);
size_t is_perfect(btree *bintree1);

#endif // BINARY_TREE
