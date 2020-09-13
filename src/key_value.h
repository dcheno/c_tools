#ifndef SRC_KEY_VALUE_H_
#define SRC_KEY_VALUE_H_

typedef struct key_value_struct {
  int key;
  int value;
} key_value_pair;

/**
 * Returns a pointer to a newly initialized KeyValuePair or type: key -> int, value -> int
 */
key_value_pair* KeyValuePair(int key, int value);

#endif /* SRC_KEY_VALUE_H_ */
