#ifndef LIBG
#define LIBG

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int_least64_t i64;
typedef int_least32_t i32;
typedef int_least16_t i16;
typedef int_least8_t i8;

typedef uint_least64_t u64;
typedef uint_least32_t u32;
typedef uint_least16_t u16;
typedef uint_least8_t u8;

// Dstring
//------------------------------------------------------------------------------

#define DSTRING_INC 50

struct Dstring 
{
	uintmax_t len;
	uintmax_t allocated_size;
	char *str;
};

bool write_file_dstring(struct Dstring *self, char *filename);
bool append_file_dstring(struct Dstring *self, char *filename);
bool read_file_dstring(struct Dstring *self, char *filename);
bool get_input_dstring(struct Dstring *self);
bool push_char_dstring(struct Dstring *self, char c);
bool push_string_dstring(struct Dstring *self, char *str);
bool set_string_dstring(struct Dstring *self, char *str);
void clear_dstring(struct Dstring *self);
bool init_dstring(struct Dstring *self);


// IVec
//------------------------------------------------------------------------------

struct IVec
{
	uintmax_t len;
	intmax_t *vec;
};

bool push_ivec(struct IVec *self, intmax_t value);
void pop_ivec(struct IVec *self);
void clear_ivec(struct IVec *self);
bool init_ivec(struct IVec *self);


// DVec
//------------------------------------------------------------------------------

struct DVec
{
	uintmax_t len;
	double *vec;
};

bool push_dvec(struct DVec *self, double value);
void pop_dvec(struct DVec *self);
void clear_dvec(struct DVec *self);
bool init_dvec(struct DVec *self);

#endif