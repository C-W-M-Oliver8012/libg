#include "libg.h"

bool get_input_dstring(Dstring* self) {
	bool is_error = false;
	self->len = 0;
	char c;
	while ((c = getc(stdin))) {
		if (c == EOF) {
			printf("Error reading char.\n");
			is_error = true;
			break;
		} else if (c == '\n') {
			break;
		}

		is_error = self->push_char(self, c);
		if (is_error == true) {
			break;
		}
	}
	return is_error;
}

bool push_char_dstring(Dstring* self, char c) {
	bool is_error = false;
	
	self->string[self->len] = c;
	if (self->len + 1 == self->allocated_size) {
		self->allocated_size = self->allocated_size + DSTRING_INC;
		char* temp = realloc(self->string, sizeof (char) * self->allocated_size);
		if (temp != NULL) {
			self->len = self->len + 1;
			self->string = temp;
		} else {
			printf("Failed to realloc string.\n");
			is_error = true;
		}
	} else {
		self->len = self->len + 1;
	}
	self->string[self->len] = '\0';

	return is_error;
}

bool push_string_dstring(Dstring* self, char *str) {
	bool is_error = false;
	u64 length = strlen(str);

	for (u64 i = 0; i < length; i++) {
		is_error = self->push_char(self, str[i]);
		if (is_error == true) {
			break;
		}
	}
	return is_error;
}

bool set_string_dstring(Dstring* self, char *str) {
	bool is_error = false;
	self->len = 0;
	u64 length = strlen(str);

	for (u64 i = 0; i < length; i++) {
		is_error = self->push_char(self, str[i]);
		if (is_error == true) {
			break;
		}
	}
	return is_error;
}

void clear_dstring(Dstring* self) {
	free(self->string);
}

bool init_dstring(Dstring* self) {
	bool is_error = false;

	self->len = 0;
	self->allocated_size = DSTRING_INC;
	self->string = calloc(self->allocated_size, sizeof (char));
	if (self->string == NULL) {
		printf("Failed to init string.\n");
		is_error = true;
	}

	self->get_input = get_input_dstring;
	self->push_char = push_char_dstring;
	self->push_string = push_string_dstring;
	self->set_string = set_string_dstring;
	self->clear = clear_dstring;

	return is_error;
}