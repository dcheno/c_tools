/*
 * linked_list.h
 *
 *  Created on: Sep 12, 2020
 *      Author: dan
 */

#ifndef SRC_LINKED_LIST_H_
#define SRC_LINKED_LIST_H_

#include<stdbool.h>

#include "key_value.h"

/* A single direction linked node. Operates on a key_value_pair of ints */
typedef struct linked_list_node_struct {
	key_value_pair* key_value;
	struct linked_list_node_struct* child;
} linked_list_node;


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

linked_list_node* get_next(linked_list_node* node);

#endif /* SRC_LINKED_LIST_H_ */
