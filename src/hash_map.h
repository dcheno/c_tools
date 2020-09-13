/*
 * hash_map.h
 *
 *  Created on: Sep 12, 2020
 *      Author: dan
 */

#ifndef SRC_HASH_MAP_H_
#define SRC_HASH_MAP_H_

#include "key_value.h"

typedef struct hash_map_struct {
	int used_keys;
	int keys;
	key_value_pair* buckets[10]; // TODO: this should be an array of linked list nodes
} hash_map;

hash_map* HashMap();

void set_key(hash_map* map, int key, int value);

int get_key(hash_map* map, int key);

#endif /* SRC_HASH_MAP_H_ */
