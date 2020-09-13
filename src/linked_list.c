#include<stdbool.h>
#include<stdlib.h>

#include "linked_list.h"
#include "key_value.h" // TODO: can this just be a generic pointer? try using a void pointer


linked_list_node* LinkedListNode(
			key_value_pair* key_value,
			linked_list_node* child
		) {
	linked_list_node* node = malloc(sizeof(linked_list_node)); // Don't forget to free stuff.
	node->key_value = key_value;
	node->child = child;

	return node;
}

void link_parent_to_child(linked_list_node* parent, linked_list_node* child) {
	parent->child = child;
}

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

linked_list_node* search_for_key(linked_list_node* start, int key) {
	linked_list_node* check = start;
	while (check != NULL) {
		if (check->key_value->key == key) {
			return check;
		} else {
			check = check->child;
		}
	}
	return NULL;
}

