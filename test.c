#include "libg.h"

#define TEST_SIZE 15

int main(void) {
	Mem_Hash mem_hash;
	init_mem_hash(&mem_hash);

	int n[TEST_SIZE];
	for (int i = 0; i < TEST_SIZE; i++) {
		add_mem_item_to_mem_hash(&mem_hash, &n[i]);
	}
	print_mem_hash(&mem_hash);

	printf("\n");
	for (int i = 0; i < TEST_SIZE; i++) {
		if (contains_ptr_mem_hash(&mem_hash, &n[i]) == true) {
			printf("true\n");
		} else {
			printf("false\n");
		}
	}
	
	int d = 45;
	if (contains_ptr_mem_hash(&mem_hash, &d) == true) {
		printf("true\n");
	} else {
		printf("false\n");
	}

	delete_mem_hash(mem_hash.hash_map, mem_hash.len);

	return 0;
}