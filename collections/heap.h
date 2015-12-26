#ifndef HEAP_H
#define HEAP_H
#pragma once

#include "collection.h"

typedef struct node_s {
	void* data;
} node_t;

typedef struct heap_s {
	comparator comparator;
	node_t* nodes;
	int size;
} heap_t;

heap_t init_heap(comparator cmp);

void insert_heap(heap_t * heap, void * elem);

void destroy_heap(heap_t * heap);

void foreach_heap(heap_t* heap, foreach f);

heap_t map_heap(heap_t* src, mapper m);

#endif