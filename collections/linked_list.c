#include "linked_list.h"
#include "collection.h"
#include <stdlib.h>
#include <string.h>

void elem_free(T elem) {
	free(elem);
}

/* initialises an empty list */
list_t init_list(void) {
	list_t list;
	list.head = NULL;
	list.last = NULL;
	list.size = 0;
	return list;
}

void destroy_list(list_t* list) {
	foreach_list(list, &elem_free);
}

/* Adds an element to the start of the list*/
void add_start(list_t* list, T value) {
	list_elem_t* elem = (list_elem_t*)malloc(sizeof(list_elem_t));
	memcpy(&elem->value, &value, sizeof(value));
	elem->next = NULL;
	if (list->size == 0) {
		list->head = elem;
		list->last = elem;
	}
	else {
		elem->next = list->head;
		list->head = elem;
	}
	list->size++;

}

/* Adds an element to the end of the list*/
void add_end(list_t* list, T value) {
	list_elem_t* elem = (list_elem_t*)malloc(sizeof(list_elem_t));
	memcpy(&elem->value, &value, sizeof(value));
	elem->next = NULL;
	if (list->last == NULL) {
		list->head = elem;
		list->last = elem;
	}
	else {
		list->last->next = elem;
		list->last = elem;
	}
	list->size++;
}

/* Pops the first element of the list*/
void* pop(list_t* list) {
	list_elem_t* elem = list->head;
	list->size--;
	list->head = elem->next;
	return elem;
}

void push(list_t* list, T elem) {
	add_end(list, elem);
}

void foreach_list(list_t* list, foreach f) {
	list_elem_t* elem = list->head;
	while (elem != NULL) {
		f(elem->value);
		elem = elem->next;
	}
}

list_t map_list(list_t* src, mapper m) {
	list_t list = init_list();
	list_elem_t* elem = src->head;
	while (elem != NULL) {
		add_end(&list, m(elem->value));
		elem = elem->next;
	}
	return list;
}

T fold_list(list_t* src, T base, folder f) {
	void* accumulator = f(NULL, base);
	list_elem_t* elem = src->head;
	while (elem != NULL) {
		f(accumulator, elem->value);
		elem = elem->next;
	}
	return accumulator;
}

list_t filter_list(list_t* src, predicate p) {
	list_t dst = init_list();
	list_elem_t* elem = src->head;
	while (elem != NULL) {
		if (p(elem->value))
			add_end(&dst, elem->value);
		elem = elem->next;
	}
	return dst;
}
