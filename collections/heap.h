#ifndef HEAP_H
#define HEAP_H
#pragma once

#include "collection.h"

typedef struct node_s {
	T data;
} node_t;

typedef struct heap_s {
	comparator comparator;
	node_t* nodes;
	int size;
} heap_t;

typedef int    (*equals_heap) (T, T);

heap_t init_heap(comparator cmp);

int contains_heap(heap_t *heap, T elem, equals_heap e);

void insert_heap(heap_t* heap, T elem);

void destroy_heap(heap_t* heap);

void foreach_heap(heap_t* heap, foreach f);

heap_t map_heap(heap_t* src, mapper m);

#endif