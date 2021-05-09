#include "libg.h"

int main(void)
{
	bool is_error = false;

	struct Dstring input;
	if (init_dstring(&input))
		is_error = true;

	while (strcmp(input.str, "quit")) {
		if (get_input_dstring(&input))
			is_error = true;
		printf("%s\n\n", input.str);
	}

	read_file_dstring(&input, "hello_world.txt");
	printf("%s", input.str);

	clear_dstring(&input);

	return is_error;
}
