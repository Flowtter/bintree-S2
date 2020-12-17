#include "test_queue.h"
#include "test_bintree.h"

int main() {
    printf("\nQUEUE TESTS\n");
    create_queue_test();
    create_queue_bintree_test();
    dequeue_test();
    queue_is_empty_test();
    printf("\nBINTREE TESTS\n");
    size_test();
    height_test();
    breadth_first_search_test();
    equality_test();
    is_sub_tree_test();
    is_degenerate_test();
    return 0;
}
