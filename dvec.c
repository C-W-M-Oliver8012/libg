#include "libg.h"

bool push_dvec(struct DVec *self, double value)
{
	bool is_error = false;

	self->vec[self->len] = value;

	double *temp = realloc(self->vec, sizeof(double) * (self->len + 2));
	if (temp != NULL) {
		self->vec = temp;
		self->len = self->len + 1;
	} else {
		printf("Failed to realloc vec.\n");
		is_error = true;
	}

	return is_error;
}

void pop_dvec(struct DVec *self)
{
	if (self->len >= 1) {
		self->len = self->len - 1;
	}
}

void clear_dvec(struct DVec *self)
{
	free(self->vec);
}

bool init_dvec(struct DVec *self)
{
	bool is_error = false;

	self->len = 0;
	self->vec = calloc(self->len + 1, sizeof(double));
	if (self->vec == NULL) {
		printf("Failed to init vec.\n");
		is_error = true;
	}

	return is_error;
}