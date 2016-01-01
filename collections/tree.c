#include "tree.h"
#include <stdlib.h>

void set_right(node_ptr this, node_ptr new_right)
{
	// I may need an equals instead of ==
	if (this->right != NULL && this->right->parent == this) {
		this->right->parent = NULL;
	}

	this->right = new_right;
	if (new_right != NULL) {
		new_right->parent = this;
	}
}

void set_left(node_ptr this, node_ptr new_left)
{
	// I may need an equals instead of ==
	if (this->left != NULL && this->left->parent == this) {
		this->left->parent = NULL;
	}

	this->left = new_left;
	if (new_left != NULL) {
		new_left->parent = this;
	}
}

tree_t init_tree() {
	tree_t tree;
	tree.root = NULL;
	return tree;
}


T search(node_ptr node, int key)
{
	if (node == NULL)
		return NULL;

	if (node->key == key)
		return node->value;

	if (key < node->key)
	{
		return search(node->left, key);
	}
	return search(node->right, key);
}

T get(tree_ptr tree, int key)
{
	if(tree->root == NULL)
	{
		return NULL;
	}
	return search(tree->root, key);
}

node_ptr rotate_right(node_ptr node)
{
	node_ptr old_parent = node->parent;
	node_ptr old_left = node->left;
	// TODO: Check for nullity
	set_left(node, node->left->right);
	// reparent
	old_left->parent = old_parent;
	set_right(old_left, node);
	return old_left;
}

node_ptr rotate_left(node_ptr node)
{
	node_ptr old_parent = node->parent;
	node_ptr old_right = node->right;
	// TODO: Check for nullity
	set_left(node, node->right->left);
	// reparent
	old_right->parent = old_parent;
	set_left(old_right, node);
	return old_right;
}


/*
 Initialise a node
*/
void init_node(int key, T value, node_ptr* node, colour c, node_ptr left, node_ptr right, node_ptr parent)
{
	*node = malloc(sizeof(tree_node_t));
	(*node)->c = c;
	(*node)->key = key;
	(*node)->value = value;
	(*node)->parent = parent;
	(*node)->left = left;
	(*node)->right = right;
}

void insert_elem(tree_ptr tree, node_ptr node, int key, T value)
{
		
}

void insert_tree(tree_ptr tree, int key, T value) {
	if(tree->root == NULL)
	{
		node_ptr node;
		init_node(key, value, &node, BLACK, NULL, NULL, NULL);
		tree->root = node;
		return;
	}
	// TODO: Recurse
}
