#include "libg.h"

bool is_ddouble_num(char c) {
	switch (c) {
		case '0': return true;
		case '1': return true;
		case '2': return true;
		case '3': return true;
		case '4': return true;
		case '5': return true;
		case '6': return true;
		case '7': return true;
		case '8': return true;
		case '9': return true;
		default: return false;
	}
}

bool set_ddouble_num(DDouble* self, char* str) {
	bool is_error = false;

	u64 str_len = strlen(str);
	u64* temp = realloc(self->num, str_len * sizeof (u64));
	if (temp != NULL) {
		self->num = temp;
		self->len = str_len;
	} else {
		printf("Failed to realloc for ddouble.\n");
		is_error = true;
	}

	if (is_error == false) {
		u64 num_dots = 0;
		for (u64 i = 0; i < self->len; i++) {
			if (i == 0 && str[i] == '-') {
				self->num[i] = neg;
			} else if (is_ddouble_num(str[i]) == true) {
				self->num[i] = str[i] - '0';
			} else if (str[i] == '.') {
				if (num_dots >= 1) {
					printf("Cannot have more than one dot in num.\n");
					self->num[i] = 0;
					is_error = true;
				} else {
					self->num[i] = dot;
				}
			} else {
				self->num[i] = 0;
				printf("Invalid character for number.\n");
				is_error = true;
			}
		}
	}

	return is_error;
}

void print_ddouble_num(DDouble* self) {
	for (u64 i = 0; i < self->len; i++) {
		if (self->num[i] == dot) {
			printf(".");
		} else if (self->num[i] == neg) {
			printf("-");
		} else {
			printf("%lu", self->num[i]);
		}
	}
}

void clear_ddouble_num(DDouble* self) {
	free(self->num);
}

bool init_ddouble_num(DDouble* self) {
	bool is_error = false;

	self->len = 0;
	self->num = calloc(1, sizeof (double));

	if (self->num == NULL) {
		printf("Failed to allocate num.\n");
		is_error = true;
	}

	self->set_num = set_ddouble_num;
	self->print_num = print_ddouble_num;
	self->clear = clear_ddouble_num;

	return is_error;
}