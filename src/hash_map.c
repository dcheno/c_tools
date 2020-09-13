#include <stdlib.h>
#include <stdbool.h>

#include "hash_map.h"
#include "key_value.h"
#include "linked_list.h"

/*
 * TODO: this is pretty slow at large numbers of of key/values (see hash_map_test).
 *       need to try expanding the buckets as the map grows.
 */

hash_map* HashMap() {
  hash_map* map = malloc(sizeof(hash_map));
  map->used_keys = 0;
  map->keys = sizeof(map->buckets) / sizeof(map->buckets[0]);
  return map;
}

void set_key(hash_map* map, int key, int value) {
  int hash = key % map->keys;

  linked_list_node* found = search_for_key(map->buckets[hash], key);

  if (found) {
	  found->key_value->value = value;
  } else {
	  linked_list_node* new_node = LinkedListNode(KeyValuePair(key, value), map->buckets[hash]);
	  map->buckets[hash] = new_node;
  }
}

int get_key(hash_map* map, int key) {
  int hash = key % map->keys;
  linked_list_node* holder = search_for_key(map->buckets[hash], key);
  return holder->key_value->value;
}

