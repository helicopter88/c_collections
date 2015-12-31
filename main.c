#include <stdio.h>
#include <stdlib.h>
#include "collections/heap.h"

int comp(T m, T n) {
    return 1;
}

void doubler(void* num) {
    int* n = (int*) num;
    *n = *n * 2;
}

void print(T elem) {
    int* x = (int*) elem;
    printf("%d", *x);
    printf("\t");
}

int eq(T n1, T n2) {
    node_t* node1 = (node_t*) n1;
    node_t* node2 = (node_t*) n2;

    return node1->data == node2->data;
}

int main(int argc, char** argv)
{
    heap_t h = init_heap(&comp);
    heap_t* heap = &h;

    for (int i = 0; i < 10; i++) {
        int* iP = (int *) malloc(sizeof(int));
        iP = &i;
        insert_heap(heap, iP);
    }




//    printf(heap->nodes[2].data);

    printf("\n");

    foreach_heap(heap, &print);

    foreach_heap(heap, &doubler);

    printf("%d", contains_heap(heap, 0, &eq));
    printf("\n");

//    printf(contains_heap(heap, 15, eq));
//    printf("\n");

    printf("Hello, world!\n");
}
