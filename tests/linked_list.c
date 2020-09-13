/*
 * linked_list_tests.c
 *
 *  Created on: Jun 27, 2020
 *      Author: dan
 */

#include <stdio.h>
#include <assert.h>

#include "../src/linked_list.h"

void test_LinkedListNode() {
	key_value_pair* value = KeyValuePair(1, 1); // TODO: this should return a pointer.
	struct linked_list_node_struct child;
	linked_list_node* node = LinkedListNode(value, &child);

	assert(node->key_value == value);
	assert(node->child == &child);
	printf("--- PASSED test_LinkedListNode ---\n");
}

void test_get_next() {
	linked_list_node* child = LinkedListNode(0, 0);
	linked_list_node* parent = LinkedListNode(0, child);
	linked_list_node* answer = get_next(parent);
	assert(answer == child);
	printf("--- PASSED test_get_next ---\n");
}

void test_has_next_true() {
	linked_list_node* child = LinkedListNode(0, 0);
	linked_list_node* parent = LinkedListNode(0, child);
	assert(has_next(parent));
	printf("--- PASSED test_has_next_true ---\n");
}

void test_has_next_false() {
	linked_list_node* node = LinkedListNode(0, 0);
	assert(!has_next(node));
	printf("--- PASSED test_has_next_false ---\n");
}

void test_link_parent_to_child() {
	linked_list_node* child = LinkedListNode(0, 0);
	linked_list_node* parent = LinkedListNode(0, 0);

	link_parent_to_child(parent, child);

	assert(has_next(parent));
	assert(!has_next(child));
	assert(get_next(parent) == child);
	printf("--- PASSED test_link_parent_to_child ---\n");
}

int main() {
	test_LinkedListNode();
	test_get_next();
	test_has_next_true();
	test_has_next_false();
	test_link_parent_to_child();
}
