#pragma once
#ifndef HEAP_H
#define HEAP_H

#include "collection.h"

#define HEAP_DEFAULT_SIZE 256

typedef struct node_s {
	void* data;
} node_t;

typedef struct heap_s {
	comparator comparator;
	node_t* nodes;
	int size;
} heap_t;

heap_t init_heap(int size, comparator cmp);

void insert_heap(heap_t * heap, void * elem);

void destroy_heap(heap_t * heap);

void foreach_heap(heap_t* heap, foreach f);

heap_t map_heap(heap_t* src, mapper m);

#endif