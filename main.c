#include <stdio.h>
#include "collections/heap.h"

int comp(int* m, int* n) {
    return 1;
}

void doubler(int* n) {
    *n = *n * 2;
}

int eq(node_t* n1, node_t* n2) {
    return (int) n1->data == (int) n2->data;
}

int main(int argc, char** argv)
{
    heap_t h = init_heap(comp);
    heap_t* heap = &h;

    for (int i = 0; i < 10; i++) {
        int* iP = &i;
        insert_heap(heap, iP);
    }


//    printf(heap->nodes[2].data);

    foreach_heap(heap, &doubler);

//    printf(contains_heap(heap, 0, eq));
    printf("\n");

//    printf(contains_heap(heap, 15, eq));
//    printf("\n");

    printf("Hello, world!\n");
}