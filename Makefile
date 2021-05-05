cc:= clang
lib_flags:= -std=c17 -Wall -Wextra -Werror
debug_flags:= -std=c17 -Wall -Wextra -Werror -g
release_flags:= -std=c17 -Wall -Wextra -Werror -static

library: dstring.c ivec.c dvec.c
	$(cc) $(lib_flags) -c dstring.c
	$(cc) $(lib_flags) -c ivec.c
	$(cc) $(lib_flags) -c dvec.c
	ar rcs libg.a dstring.o ivec.o dvec.o
	rm dstring.o ivec.o dvec.o

debug: test.c
	$(cc) $(debug_flags) test.c libg.a -o test

release: dstring.c ivec.c test.c
	$(cc) $(release_flags) test.c libg.a -o test
