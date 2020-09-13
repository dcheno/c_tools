/*
 * key_value.h
 *
 *  Created on: Sep 12, 2020
 *      Author: dan
 */

#ifndef SRC_KEY_VALUE_H_
#define SRC_KEY_VALUE_H_

/* A key value pair of type:
   key: int
   value: int */
typedef struct key_value_struct {
  int key;
  int value;
} key_value_pair;

/* Returns a pointer to a key value pair with the given key and value */
key_value_pair* KeyValuePair(int key, int value);

#endif /* SRC_KEY_VALUE_H_ */
