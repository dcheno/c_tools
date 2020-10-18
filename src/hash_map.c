#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "hash_map.h"
#include "key_value.h"
#include "linked_list.h"

static int hash_key(hash_map*, int key);
static void maybe_resize(hash_map* map);
static void resize(hash_map* map);
static void assign(hash_map* map, int key, int value, int hash);

static int initial_size = 10;
static float retry_threshold = 0.75;


hash_map* HashMap() {
  hash_map* map = malloc(sizeof(hash_map));
  map->num_entries = 0;
  map->buckets = malloc(sizeof(linked_list_node*) * initial_size);
  map->num_buckets = initial_size;
  return map;
}

void set_key(hash_map* map, int key, int value) {
  int hash = hash_key(map, key);

  linked_list_node* found = search_for_key(map->buckets[hash], key);

  if (found) {
	  found->key_value->value = value;
  } else {
	  assign(map, key, value, hash);
	  map->num_entries++;
	  maybe_resize(map);
  }
}

int get_key(hash_map* map, int key) {
  int hash = hash_key(map, key);
  linked_list_node* holder = search_for_key(map->buckets[hash], key);
  return holder->key_value->value;
}

static void assign(hash_map* map, int key, int value, int hash) {
	linked_list_node* new_node = LinkedListNode(KeyValuePair(key, value), map->buckets[hash]);
	map->buckets[hash] = new_node;
}

static void maybe_resize(hash_map* map) {
	float full = (float) map->num_entries / map->num_buckets;
	if (full >= retry_threshold) {
		// printf("trying a resize at %d keys with %d buckets\n", map->num_entries, map->num_buckets);
		resize(map);
	}
}

static void resize(hash_map* map) {
	int new_size = map->num_buckets * 2;
	linked_list_node** old_buckets = map->buckets;
	linked_list_node** new_buckets = malloc(sizeof(linked_list_node*) * new_size);
	map->buckets = new_buckets;

	for (int i = 0; i < map->num_buckets; i++) {
		linked_list_node* next = old_buckets[i];
		while (next != NULL) {
			assign(map, next->key_value->key, next->key_value->value, hash_key(map, next->key_value->key));
			next = next->child;
		}
	}
	map->num_buckets = new_size;
}

static int hash_key(hash_map* map, int key) {
	return key % map->num_buckets;
}

