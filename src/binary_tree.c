#include "binary_tree.h"
#include "queue.h"

int max(int a, int b) {
    return a > b ? a : b;
}

btree *bintree_init(int value) {
    btree *tree = malloc(sizeof(tree));
    tree->key = value;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void bintree_free(btree *bintree) {
    if (bintree->left)
        bintree_free(bintree->left);
    if (bintree->right)
        bintree_free(bintree->right);
    free(bintree);
}

size_t size(btree *bintree) {
    size_t counter = 0;
    queue *q = queue_init();
    enqueue(q, bintree);
    while (!is_empty(q)) {
        ++counter;
        queue *node = dequeue(q);
        if (((btree *) (node->self))->left)
            enqueue(q, (((btree *) (node->self))->left));
        if (((btree *) (node->self))->right)
            enqueue(q, (((btree *) (node->self))->right));
    }
    return counter;
}

int height(btree *bintree) {
    if (!bintree)
        return -1;
    return 1 + max(height(bintree->left), height(bintree->right));
}

void breadth_first_search(btree *bintree) {
    queue *q = queue_init();
    enqueue(q, bintree);
    enqueue(q, NULL);
    printf("[");
    while (!is_empty(q)) {
        queue *node = dequeue(q);
        if (node->self) {
            printf("%d ", ((btree *) (node->self))->key);
            if (((btree *) (node->self))->left)
                enqueue(q, (((btree *) (node->self))->left));
            if (((btree *) (node->self))->right)
                enqueue(q, (((btree *) (node->self))->right));
        } else {
            if (is_empty(q))
                break;
            else {
                printf("] [");
                enqueue(q, NULL);
            }
        }
    }
    printf("]\n");
}
