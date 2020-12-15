#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>


typedef struct queue queue;
struct queue {
    void *self;
    queue *next;
};

queue* queue_init();
size_t is_empty(queue *q);
void enqueue(queue *q, void *elt);
queue* dequeue(queue *q);
void queue_print(queue *q);

#endif // QUEUE
