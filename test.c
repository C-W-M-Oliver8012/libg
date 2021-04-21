#include "libg.h"

int main(void) {
	Dstring input;
	init_dstring(&input);

	while (strcmp(input.string, "quit") != 0) {
		input.get_input(&input);
		printf("%s\n\n", input.string);
	}

	input.clear(&input);
	return 0;
}