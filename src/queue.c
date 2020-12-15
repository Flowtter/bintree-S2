#include "queue.h"

queue* queue_init() {
    queue *queue = malloc(sizeof(queue));
    queue->self = NULL;
    queue->next = NULL;
    return queue;
}

size_t is_empty(queue *q) {
    return q->next ? 0 : 1;
}

void enqueue(queue *q, void *elt) {
    queue *elt_to_enqueue = queue_init();
    elt_to_enqueue->self = elt;
    elt_to_enqueue->next = NULL;

    if (!q->next) {
        q->next = elt_to_enqueue;
        return;
    }

    while (q->next) {
        q = q->next;
    }
    q->next = elt_to_enqueue;
}

queue* dequeue(queue *q) {
    queue *elt = q->next;
    q->next = q->next->next;
    return elt;
}

void queue_print(queue *q) {
    printf("[");
    q = q->next;
    while (q) {
        printf("%p", q->self);
        q = q->next;
        if(q)
            printf(", ");
    }
    printf("]\n");
}
