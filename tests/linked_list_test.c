#include <stdio.h>
#include <assert.h>

#include "../src/linked_list.h"

void test_LinkedListNode() {
	// Create a list of two nodes, make sure they are tied together.
	key_value_pair* value = KeyValuePair(1, 1);
	struct linked_list_node_struct child;
	linked_list_node* node = LinkedListNode(value, &child);

	assert(node->key_value == value);
	assert(node->child == &child);
	printf("--- PASSED test_LinkedListNode\n");
}

void test_get_next() {
	linked_list_node* child = LinkedListNode(0, 0);
	linked_list_node* parent = LinkedListNode(0, child);
	linked_list_node* answer = get_next(parent);
	assert(answer == child);
	printf("--- PASSED test_get_next\n");
}

void test_has_next_true() {
	linked_list_node* child = LinkedListNode(0, 0);
	linked_list_node* parent = LinkedListNode(0, child);
	assert(has_next(parent));
	printf("--- PASSED test_has_next_true\n");
}

void test_has_next_false() {
	linked_list_node* node = LinkedListNode(0, 0);
	assert(!has_next(node));
	printf("--- PASSED test_has_next_false\n");
}

void test_link_parent_to_child() {
	linked_list_node* child = LinkedListNode(0, 0);
	linked_list_node* parent = LinkedListNode(0, 0);

	link_parent_to_child(parent, child);

	assert(has_next(parent));
	assert(!has_next(child));
	assert(get_next(parent) == child);
	printf("--- PASSED test_link_parent_to_child\n");
}

void test_search_for_key() {
	linked_list_node* head = LinkedListNode(KeyValuePair(1, 1), LinkedListNode(KeyValuePair(2, 2), LinkedListNode(KeyValuePair(3, 3), NULL)));
	linked_list_node* should_find = search_for_key(head, 2);

	assert(2 == should_find->key_value->key);
	assert(2 == should_find->key_value->value);

	linked_list_node* shouldnt_find = search_for_key(head, 0);
	assert(NULL == shouldnt_find);
	printf("--- PASSED test_search_for_key\n");
}

int main() {
	test_LinkedListNode();
	test_get_next();
	test_has_next_true();
	test_has_next_false();
	test_link_parent_to_child();
	test_search_for_key();
}
