#include "libg.h"

bool push_ivec(IVec* self, i64 value)
{
	bool is_error = false;
	
	self->vec[self->len] = value;

	i64* temp = realloc(self->vec, sizeof (i64) * (self->len + 2));
	if (temp != NULL) {
		self->vec = temp;
		self->len = self->len + 1;
	} else {
		printf("Failed to realloc vec.\n");
		is_error = true;
	}

	return is_error;
}

void pop_ivec(IVec* self)
{
	if (self->len >= 1) {
		self->len = self->len - 1;
	}
}

void clear_ivec(IVec* self)
{
	free(self->vec);
}

bool init_ivec(IVec* self)
{
	bool is_error = false;

	self->len = 0;
	self->vec = calloc(self->len + 1, sizeof (i64));
	if (self->vec == NULL) {
		printf("Failed to init vec.\n");
		is_error = true;
	}

	self->push = push_ivec;
	self->pop = pop_ivec;
	self->clear = clear_ivec;

	return is_error;
}