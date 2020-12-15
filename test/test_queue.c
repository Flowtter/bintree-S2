#include "queue.h"
#include "binary_tree.h"

#define UNUSED(x) (void)(x)

void create_queue_test() {
    printf("CREATE QUEUE TEST\n");
    queue *q = queue_init();
    int mon_int = 2;
    enqueue(q, &mon_int);
    int mon_second = 3;
    enqueue(q, &mon_second);
    int mon_third = 4;
    enqueue(q, &mon_third);
    queue_print(q);
    free(q);
}

void create_queue_bintree_test() {
    printf("CREATE QUEUE BINTREE TEST\n");
    queue *q = queue_init();
    btree *bintree = bintree_init(2);
    enqueue(q, bintree);
    btree *bintree_second = bintree_init(3);
    enqueue(q, bintree_second);
    btree *bintree_third = bintree_init(4);
    enqueue(q, bintree_third);
    queue_print(q);
    free(q);
}

void dequeue_test() {
    printf("DEQUEUE TEST\n");
    queue *q = queue_init();
    int mon_int = 2;
    enqueue(q, &mon_int);
    int mon_second = 3;
    enqueue(q, &mon_second);
    int mon_third = 4;
    enqueue(q, &mon_third);
    printf("BEFORE\n");
    queue_print(q);
    queue *elm = dequeue(q);
    printf("AFTER\n");
    queue_print(elm);
    free(q);
}

void queue_is_empty_test() {
    printf("QUEUE IS EMPTY TEST\n");
    queue *q = queue_init();
    printf("%zu\n", is_empty(q));
    int mon_int = 2;
    enqueue(q, &mon_int);
    printf("%zu\n", is_empty(q));
    UNUSED(dequeue(q));
    printf("%zu\n", is_empty(q));
}
