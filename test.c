#include "libg.h"

int main(void)
{
	bool is_error = false;

	Dstring input;
	if (init_dstring(&input) == true) {
		is_error = true;
	}

	while (strcmp(input.string, "quit")) {
		if (input.get_input(&input) == true) {
			is_error = true;
		}
		printf("%s\n\n", input.string);
	}
	input.clear(&input);
	return is_error;
}
