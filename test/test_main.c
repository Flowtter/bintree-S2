#include "main.h"
#include "test_queue.h"
#include "test_bintree.h"

int main() {
    category("\nQUEUE TESTS\n");
    create_queue_test();
    create_queue_bintree_test();
    dequeue_test();
    queue_is_empty_test();
    category("\nBINTREE TESTS\n");
    size_test();
    height_test();
    breadth_first_search_test();
    equality_test();
    is_sub_tree_test();
    is_degenerate_test();
    is_perfect_test();
    return 0;
}
