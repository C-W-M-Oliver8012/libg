#include "libg.h"

bool read_file_dstring(struct Dstring *self, char *filename)
{
	bool is_error = false;

	self->len = 0;
	FILE *file = fopen(filename, "r");
	char c;
	if (file != NULL) {
		while (!is_error) {
			c = fgetc(file);
			if (c == EOF)
				break;

			if (push_char_dstring(self, c))
				is_error = true;
		}
		fclose(file);
	} else {
		printf("Failed to open file '%s'.\n", filename);
		is_error = true;
	}

	return is_error;
}

bool get_input_dstring(struct Dstring *self)
{
	bool is_error = false;

	self->len = 0;
	char c;
	while (!is_error) {
		c = fgetc(stdin);
		if (c == EOF) {
			printf("Error reading char.\n");
			is_error = true;
		} else if (c == '\n') {
			break;
		}

		if (push_char_dstring(self, c))
			is_error = true;
	}
	return is_error;
}

bool realloc_dstring(struct Dstring *self)
{
	bool is_error = false;

	self->allocated_size = self->allocated_size + DSTRING_INC;
	char *temp = realloc(self->str, 
		sizeof(char) * self->allocated_size);
	if (temp != NULL) {
		self->len = self->len + 1;
		self->str = temp;
	} else {
		printf("Failed to realloc string.\n");
		is_error = true;
	}

	return is_error;
}

bool push_char_dstring(struct Dstring *self, char c)
{
	bool is_error = false;
	
	self->str[self->len] = c;
	if (self->len + 1 == self->allocated_size) {
		if (realloc_dstring(self))
			is_error = true;
	} else {
		self->len = self->len + 1;
	}

	self->str[self->len] = '\0';

	return is_error;
}

bool push_string_dstring(struct Dstring *self, char *str)
{
	bool is_error = false;

	u64 length = strlen(str);

	for (u64 i = 0; i < length; i++) {
		is_error = push_char_dstring(self, str[i]);
		if (is_error)
			break;
	}

	return is_error;
}

bool set_string_dstring(struct Dstring *self, char *str)
{
	bool is_error = false;
	self->len = 0;
	u64 length = strlen(str);

	for (u64 i = 0; i < length; i++) {
		is_error = push_char_dstring(self, str[i]);
		if (is_error)
			break;
	}
	
	return is_error;
}

void clear_dstring(struct Dstring *self)
{
	free(self->str);
}

bool init_dstring(struct Dstring *self)
{
	bool is_error = false;

	self->len = 0;
	self->allocated_size = DSTRING_INC;
	self->str = calloc(self->allocated_size, sizeof(char));
	if (self->str == NULL) {
		printf("Failed to init string.\n");
		is_error = true;
	}

	return is_error;
}