hash_map: linked_list
	gcc -o src/hash_map.o src/hash_map.c src/linked_list.o
linked_list: key_value
	gcc -c -o src/linked_list.o src/linked_list.c
key_value:
	gcc -c -o src/key_value.o src/key_value.c
	