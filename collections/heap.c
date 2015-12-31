#include <stdlib.h>
#include <string.h>
#include "heap.h"

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) x / 2
#define TRUE 1
#define FALSE 0

heap_t init_heap(comparator cmp) {
    heap_t heap;
    heap.size = 0;
    heap.comparator = cmp;
    return heap;
}

int contains_helper(heap_t *heap, T elem, equals_heap e, int i) {
    if (e(&heap->nodes[i].data, elem)) {
        return TRUE;
    }
    if (LCHILD(i) < heap->size) {
        contains_helper(heap, elem, e, LCHILD(i));
    }
    if (RCHILD(i) < heap->size) {
        contains_helper(heap, elem, e, RCHILD(i));
    }
}

int contains_heap(heap_t *heap, T elem, equals_heap e) {
    return contains_helper(heap, elem, e, 0);
}

void insert_heap(heap_t *heap, T elem) {
    if (heap->size) {
        heap->nodes = realloc(heap->nodes, (heap->size + 1) * sizeof(node_t));
    } else {
        heap->nodes = (node_t *) malloc(sizeof(node_t));
    }

    node_t node = {NULL};
    node.data = elem;

    int i = (heap->size)++;
    while (i && heap->comparator(&node.data, &heap->nodes[PARENT(i)].data)) {
        heap->nodes[i].data = heap->nodes[PARENT(i)].data;
        i = PARENT(i);
    }
    memcpy(&heap->nodes[i], &node, sizeof(node));
}

void swap(node_t *n1, node_t *n2) {

    node_t temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void heap_rebuild(heap_t *heap, int i) {
    int smallest = (LCHILD(i) < heap->size) &&
                   heap->comparator(heap->nodes[LCHILD(i)].data, heap->nodes[i].data)
                   ? LCHILD(i) : i;
    if (RCHILD(i) < heap->size &&
        heap->comparator(heap->nodes[RCHILD(i)].data, heap->nodes[smallest].data)) {
        smallest = RCHILD(i);
    }
    if (smallest != i) {
        swap(&(heap->nodes[i]), &(heap->nodes[smallest]));
        heap_rebuild(heap, smallest);
    }
}

void delete_node(heap_t *heap) {
    if (heap->size) {
        heap->nodes[0] = heap->nodes[--(heap->size)];
        heap->nodes = realloc(heap->nodes, heap->size * sizeof(node_t));
        heap_rebuild(heap, 0);
    } else {
        free(heap->nodes);
    }
}

void foreach_helper(foreach f, heap_t *heap, int i) {
    if (LCHILD(i) < heap->size) {
        foreach_helper(f, heap, LCHILD(i));
    }
    f(&heap->nodes[i].data);
    if (RCHILD(i) < heap->size) {
        foreach_helper(f, heap, RCHILD(i));
    }
}

void array_ordered(heap_t *heap, foreach f) {
    for (int i = 0; i < heap->size; i++) {
        f(heap->nodes[i].data);
    }
}

void foreach_heap(heap_t *heap, foreach f) {
    foreach_helper(f, heap, 0);
}

void destroy_heap(heap_t *heap) {
    for (int i = 0; i <= heap->size; i++) {
        delete_node(heap);
    }
}

void map_helper(mapper f, heap_t *src, heap_t *dst, int i) {
    if (LCHILD(i) < src->size) {
        map_helper(f, src, dst, LCHILD(i));
    }
    insert_heap(dst, f(&src->nodes[i].data));
    if (RCHILD(i) < src->size) {
        map_helper(f, src, dst, RCHILD(i));
    }
}

heap_t map_heap(heap_t *src, mapper m) {
    heap_t h = init_heap(src->comparator);
    map_helper(m, src, &h, 0);
    return h;
}