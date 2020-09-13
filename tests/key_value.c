#include<stdio.h>
#include<assert.h>
#include "../src/key_value.h"


int main() {
  int key = 1;
  int value = 2;
  key_value_pair* pair = KeyValuePair(1,2);
  assert(key == pair->key);
  assert(value == pair->value);
  printf("passed just one test\n");
}
