# Collections

[![Join the chat at https://gitter.im/helicopter88/c_collections](https://badges.gitter.im/helicopter88/c_collections.svg)](https://gitter.im/helicopter88/c_collections?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)
A collection of Java style collections written in C
So far, the collections included are:
* LinkedList
* Heap

These collections include functions such as foreach, map, filter and fold
that can be used to use a functional approach.
Both collections can hold any type, as they take ```void*``` as value for each element

Examples:
* LinkedList:
```C
#include <linked_list.h>

// foreach will take any void function 
// that takes a void* as an argument
void print(void* elem) {
	int* i = (int*)elem;
	printf("%d\n", *i);
}

int main()
{
	list_t l = init_list();
  list_t* list = &l;
  // Adds a value at the end of the list
  add_end(list, &value);
  // as the name implies, this one adds at the start
  add_start(list, &value);
  // will print every value contained in the list
  foreach_list(list, &print);  
}
```

* Heap:
```C
#include "heap.h"
// Anything is valid as a comparator as long as it returns an int and takes 2 void*
inline int min_int(void* elem1, void* elem2) {
	return memcmp(&elem1, &elem2, sizeof(elem1)) < 0;
}

// Exactly same as the print for lists
void print(void* elem) {
	int* i = (int*)elem;
	printf("%d\n", *i);
}

int main() {
  // Initialise a new heap that uses min_int as a comparator
  // This allows us to have a single collection but have various implementations
  // such as max heap, min heap, min heap with strings
  heap_t h = init_heap(256, &min_int);
	heap_t* heap = &h;
	// inserts a value inside the heap
	insert_heap(heap, &value);
	// prints every value contained in the heap
	foreach_heap(heap, &print);
	// Frees the memory used by the heap
	destroy_heap(heap);
}
```
# TODO
* Make this a shared library
* Better commenting in code


