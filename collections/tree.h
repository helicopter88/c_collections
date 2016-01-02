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
	struct tree_node_s* parent;
	struct tree_node_s* left;
	struct tree_node_s* right;
} tree_node_t;

typedef tree_node_t* node_ptr;

typedef struct tree_s {
	node_ptr root;
} tree_t;

typedef tree_t* tree_ptr;

tree_t init_tree();

T get_tree(tree_ptr tree, int key);

void insert_tree(tree_ptr tree, int key, T value);

#endif
