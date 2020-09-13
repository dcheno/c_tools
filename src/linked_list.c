/*
 * linked_list.c
 *
 *  Created on: Sep 12, 2020
 *      Author: dan
 */
#include<stdbool.h>
#include<stdlib.h>

#include "linked_list.h"
#include "key_value.h" // TODO: can this just be a generic pointer? try using a void pointer

/*
 * Creates and returns a linked list node.
 * @param key_value_pair* key_value: the key_value pair to associate with the node.
 * @param linked_list_node* child
 * @return linked_list_node*
 */
linked_list_node* LinkedListNode(
			key_value_pair* key_value,
			linked_list_node* child
		) {
	linked_list_node* node = malloc(sizeof(linked_list_node)); // Don't forget to free stuff.
	node->key_value = key_value;
	node->child = child;

	return node;
}

/*
 * Connects two nodes, the first as the parent of the second.
 */
void link_parent_to_child(linked_list_node* parent, linked_list_node* child) {
	parent->child = child;
}

/*
 * Determines if the given node has a child node.
 * @return true of the node has a child
 */
bool has_next(linked_list_node* node) {
	if (node->child) {
		return true;
	} else {
		return false;
	}
}

linked_list_node* get_next(linked_list_node* node) {
	return node->child;
}

