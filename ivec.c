#include "libg.h"

bool push_ivec(struct IVec *self, intmax_t value)
{
	bool is_error = false;
	
	self->vec[self->len] = value;

	intmax_t* temp = 
		realloc(self->vec, sizeof(intmax_t) * (self->len + 2));
	if (temp != NULL) {
		self->vec = temp;
		self->len = self->len + 1;
	} else {
		printf("Failed to realloc vec.\n");
		is_error = true;
	}

	return is_error;
}

void pop_ivec(struct IVec *self)
{
	if (self->len >= 1)
		self->len = self->len - 1;
}

void clear_ivec(struct IVec *self)
{
	free(self->vec);
}

bool init_ivec(struct IVec *self)
{
	bool is_error = false;

	self->len = 0;
	self->vec = calloc(self->len + 1, sizeof(intmax_t));
	if (self->vec == NULL) {
		printf("Failed to init vec.\n");
		is_error = true;
	}

	return is_error;
}