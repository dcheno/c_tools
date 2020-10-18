#ifndef SRC_HASH_MAP_H_
#define SRC_HASH_MAP_H_

#include "linked_list.h"

typedef struct hash_map_struct {
	int num_entries;
	int num_buckets;
	linked_list_node** buckets;
} hash_map;

/**
 * Returns a pointer to a newly initialized hash map of type: key -> int, value -> int.
 */
hash_map* HashMap();

/**
 * Set the value for the given key in the given hash map.
 */
void set_key(hash_map* map, int key, int value);

/**
 * Retrieve the stored value for the given key in the given hash map.
 */
int get_key(hash_map* map, int key);

#endif /* SRC_HASH_MAP_H_ */
