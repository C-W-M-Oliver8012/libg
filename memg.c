#include "libg.h"

bool is_prime(u64 num) {
    if (num == 2 || num == 3) {
        return true;
    }
    for (u64 i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

u64 next_prime(u64 current_prime) {
    current_prime = current_prime * 2;

    while (is_prime(current_prime) == false) {
        current_prime++;
    }
    return current_prime;
}

bool init_mem_hash(Mem_Hash* self) {
    bool is_error = false;

    self->is_changing_size = false;
    self->len = MEM_HASH_START_SIZE;
    self->len_size = 0;
    self->size = 0;
    self->hash_map = malloc(sizeof (Mem_Item*) * self->len);

    if (self->hash_map != NULL) {
        for (u64 i = 0; i < self->len; i++) {
            self->hash_map[i] = NULL;
        }
    } else {
        printf("Failed to allocated memory for memory hash map.\n");
        is_error = true;
    }

    return is_error;
}

bool add_mem_item_to_mem_hash(Mem_Hash* self, void* ptr) {
    bool is_error = false;

    Mem_Item* new_mem_item = malloc(sizeof (Mem_Item));

    if (new_mem_item != NULL) {
        new_mem_item->ptr = ptr;
        new_mem_item->next = NULL;
    } else { 
        printf("Failed to create new memory item.\n");
        is_error = true;
    }

    if (is_error == false) {
        u64 hash_key = (uintptr_t)ptr % self->len;

        if (self->hash_map[hash_key] == NULL) {
            self->hash_map[hash_key] = new_mem_item;
            self->len_size = self->len_size + 1;
        } else {
            Mem_Item* current_item = self->hash_map[hash_key];

            while (current_item->next != NULL) {
                current_item = current_item->next;
            }
            current_item->next = new_mem_item;
        }
        self->size = self->size + 1;

        if (self->len_size == self->len && self->is_changing_size == false) {
            if (increase_len_mem_hash(self) == true) {
                is_error = true;
            }
        }
    }

    return is_error;
}

bool increase_len_mem_hash(Mem_Hash* self) {
    bool is_error = false;

    u64 old_len = self->len;

    self->is_changing_size = true;
    self->len = next_prime(self->len);
    self->len_size = 0;
    self->size = 0;

    Mem_Item** old_hash_map = self->hash_map;
    self->hash_map = malloc(sizeof (Mem_Item*) * self->len);

    if (self->hash_map != NULL) {
        for (u64 i = 0; i < self->len; i++) {
            self->hash_map[i] = NULL;
        }
    } else {
        printf("Failed to allocated memory for memory hash map.\n");
        is_error = true;
    }

    if (is_error == false) {
        for (u64 i = 0; i < old_len; i++) {
            if (old_hash_map[i] != NULL) {
                Mem_Item* current_item = old_hash_map[i];

                while (current_item->next != NULL) {
                    add_mem_item_to_mem_hash(self, current_item->ptr);
                    current_item = current_item->next;
                }
                add_mem_item_to_mem_hash(self, current_item->ptr);
            }
        }
        delete_mem_hash(old_hash_map, old_len);
    }
    self->is_changing_size = false;

    return is_error;
}

void delete_mem_hash(Mem_Item** hash_map, u64 len) {
    for (u64 i = 0; i < len; i++) {
        if (hash_map[i] != NULL) {
            Mem_Item* current_item = hash_map[i];
            Mem_Item* previous_item = current_item;

            while (current_item->next != NULL) {
                current_item = current_item->next;
                free(previous_item);
                previous_item = current_item;
            }
            free(previous_item);
        }
    }
    free(hash_map);
}

bool contains_ptr_mem_hash(Mem_Hash* self, void* ptr) {
    bool contains_ptr = false;

    u64 hash_key = (uintptr_t)ptr % self->len;

    if (self->hash_map[hash_key] != NULL) {
        Mem_Item* current_item = self->hash_map[hash_key];

        while (current_item->next != NULL) {
            if (current_item->ptr == ptr) {
                contains_ptr = true;
            }
            current_item = current_item->next;
        }
        if (current_item->ptr == ptr) {
            contains_ptr = true;
        }
    }

    return contains_ptr;
}

void print_mem_hash(Mem_Hash* self) {
    for (u64 i = 0; i < self->len; i++) {
        printf("%lu: ", i);
        if (self->hash_map[i] == NULL) {
            printf("Empty\n");
        } else {
            Mem_Item* current_item = self->hash_map[i];

            while (current_item->next != NULL) {
                printf("%lu, ", (uintptr_t)current_item->ptr);
                current_item = current_item->next;
            }
            printf("%lu\n", (uintptr_t)current_item->ptr);
        }
    }
}