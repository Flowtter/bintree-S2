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

size_t equality(btree *bintree1, btree *bintree2) {
    if (bintree1 && bintree2) {
        return bintree1->key == bintree2->key
               && equality(bintree1->left, bintree2->left)
               && equality(bintree1->right, bintree2->right);
    } else if (!bintree1 ^ !bintree2) {
        // equivalent to bintree1 != NULL ^
        return 0;
    } else {
        return 1;
    }
}

size_t is_sub_tree(btree *bintree1, btree *bintree2) {
    size_t result = equality(bintree1, bintree2);
    if (bintree1->left)
        result |= is_sub_tree(bintree1->left, bintree2);
    if (bintree1->right)
        result |= is_sub_tree(bintree1->right, bintree2);
    return result;
}

size_t is_degenerate(btree *bintree) {
    if (!bintree)
        return 1;
    if (bintree->left != NULL && bintree->right != NULL)
        return 0;
    return is_degenerate(bintree->right) && is_degenerate(bintree->left);
}

size_t is_perfect(btree *bintree) {
    queue *q = queue_init();
    enqueue(q, bintree);
    enqueue(q, NULL);
    size_t counter = 2;
    size_t index = 0;
    while (!is_empty(q)) {
        queue *elt = dequeue(q);
        if (!elt->self && is_empty(q))
            break;
        else if (!elt->self) {
            counter <<= 1;
            enqueue(q, NULL);
        } else {
            index++;
            if (((btree *) (elt->self))->left)
                enqueue(q, ((btree *) (elt->self))->left);
            if (((btree *) (elt->self))->right)
                enqueue(q, ((btree *) (elt->self))->right);
        }
    }
    return index == counter-1;
}
