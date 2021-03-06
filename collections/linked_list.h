#pragma once
#ifndef LIST_H
#define LIST_H
#include "collection.h"

typedef struct list_elem_s list_elem_t;

typedef struct list_elem_s {
	list_elem_t* next;
	T value;
} list_elem_t;

typedef struct {
	list_elem_t* head;
	list_elem_t* last;
	int size;
} list_t;

list_t init_list(void);

void destroy_list(list_t * list);

void add_start(list_t* list, T value);

void add_end(list_t* list, T value);

void* pop(list_t* list);

void push(list_t* list, T elem);

void foreach_list(list_t*, foreach f);

list_t map_list(list_t* src, mapper m);

T fold_list(list_t* src, T base, folder f);

list_t filter_list(list_t* src, predicate p);

#endif
