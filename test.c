#include "libg.h"

int main(void)
{
	bool is_error = false;

	struct Dstring input;
	if (init_dstring(&input) == true) {
		is_error = true;
	}

	while (strcmp(input.str, "quit")) {
		if (get_input_dstring(&input) == true) {
			is_error = true;
		}
		printf("%s\n\n", input.str);
	}
	clear_dstring(&input);
	return is_error;
}
