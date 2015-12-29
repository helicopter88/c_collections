#include <stdio.h>
#include "collections/heap.h"

int comp(int* m, int* n) {
    return 1;
}

void doubler(int m, int* n) {
    *n = *n * 2;
}

//int eq(node_t* n1, node_t* n2) {
//    return (int) n1->data == (int) n2->data;
//}

int main(int argc, char** argv)
{
    heap_t h = init_heap(comp);
    heap_t* heap = &h;

    insert_heap(heap, 1);
    insert_heap(heap, 2);
    insert_heap(heap, 3);
    insert_heap(heap, 4);
    insert_heap(heap, 5);
    insert_heap(heap, 6);
    insert_heap(heap, 7);
    insert_heap(heap, 8);
    insert_heap(heap, 9);
    insert_heap(heap, 0);

    foreach_heap(heap, doubler);

//    printf(contains_heap(heap, 0, eq));
//    printf("\n");
//    printf(contains_heap(heap, 15, eq));
//    printf("\n");

    printf("Hello, world!\n");
}