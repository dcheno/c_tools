#ifndef SRC_LINKED_LIST_H_
#define SRC_LINKED_LIST_H_

#include<stdbool.h>

#include "key_value.h"

/* A single direction linked node. Operates on a key_value_pair of ints */
typedef struct linked_list_node_struct {
	key_value_pair* key_value;
	struct linked_list_node_struct* child;
} linked_list_node;

/**
 * Returns a pointer to a newly initialized LinkedListNode
 */
linked_list_node* LinkedListNode(
			key_value_pair* key_value,
			linked_list_node* child
		);

/*
 * Connects two nodes, the first as the parent of the second.
 */
void link_parent_to_child(linked_list_node* parent, linked_list_node* child);

/*
 * Determines if the given node has a child node.
 * @return true of the node has a child
 */
bool has_next(linked_list_node* node);

/*
 * Returns the next node in the list. Maybe not that useful given you can access the child.
 */
linked_list_node* get_next(linked_list_node* node);

/*
 * Searches the linked list for the first node with the given key starting from the given node. Returns NULL
 * if the list does not contain a linked list node with a key value pair with that key.
 */
linked_list_node* search_for_key(linked_list_node* node, int key);

#endif /* SRC_LINKED_LIST_H_ */
