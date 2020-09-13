/*
 * hash_map.c
 *
 *  Created on: Sep 12, 2020
 *      Author: dan
 */
#include <stdlib.h>

#include "hash_map.h"
#include "key_value.h"

/* Returns an initialized hash map of type k: int, v: int. */
hash_map* HashMap() {
  hash_map* map = malloc(sizeof(hash_map));
  map->used_keys = 0;
  map->keys = sizeof(map->buckets);
  return map;
}

/* For the given hash map, assign the given value to the given key */
void set_key(hash_map* map, int key, int value) {
  int hash = map->keys % key;
  map->buckets[hash] = KeyValuePair(key, value);
}

/* For the given hash map, retrieve the value assigned to the given
   key */
int get_key(hash_map* map, int key) {
  int hash = map->keys % key;
  return map->buckets[hash]->value; // TODO: using linked list this will need to be checked.
}

