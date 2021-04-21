#include "libg.h"

bool push_dvec(DVec* self, double value) {
	bool is_error = false;

	self->vec[self->len] = value;

	double* temp = realloc(self->vec, sizeof (double) * (self->len + 2));
	if (temp != NULL) {
		self->vec = temp;
		self->len = self->len + 1;
	} else {
		printf("Failed to realloc vec.\n");
		is_error = true;
	}

	return is_error;
}

void pop_dvec(DVec* self) {
	if (self->len >= 1) {
		self->len = self->len - 1;
	}
}

void clear_dvec(DVec* self) {
	free(self->vec);
}

bool init_dvec(DVec* self) {
	bool is_error = false;

	self->len = 0;
	self->vec = calloc(self->len + 1, sizeof (double));
	if (self->vec == NULL) {
		printf("Failed to init vec.\n");
		is_error = true;
	}

	self->push = push_dvec;
	self->pop = pop_dvec;
	self->clear = clear_dvec;

	return is_error;
}