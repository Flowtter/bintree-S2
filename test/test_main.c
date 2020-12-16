#include "test_queue.h"
#include "test_bintree.h"

int main() {
    create_queue_test();
    create_queue_bintree_test();
    dequeue_test();
    queue_is_empty_test();

    size_test();
    height_test();
    breadth_first_search_test();
    return 0;
}
