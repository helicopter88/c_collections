#ifndef TREE_H
#define TREE_H
#pragma once
#include "collection.h"

typedef enum {
	RED,
	BLACK
} colour;

typedef struct tree_node_s {
	int key;
	T value;
	colour c;
	tree_node_t* parent;
	tree_node_t* left;
	tree_node_t* right;
} tree_node_t;

typedef tree_node_t* node_ptr;

typedef struct tree_s {
	node_ptr root;
} tree_t;

typedef tree_t* tree_ptr;

#endif