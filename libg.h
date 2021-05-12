#ifndef LIBG
#define LIBG

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef __int128_t i128;
typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

typedef __uint128_t u128;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

// Dstring
//------------------------------------------------------------------------------

#define DSTRING_INC 50

struct Dstring 
{
	size_t len;
	size_t allocated_size;
	char *str;
};

bool read_file_dstring(struct Dstring *self, char *filename);
bool get_input_dstring(struct Dstring *self);
bool push_char_dstring(struct Dstring *self, char c);
bool push_string_dstring(struct Dstring *self, char *str);
void clear_dstring(struct Dstring *self);
bool init_dstring(struct Dstring *self);


// IVec
//------------------------------------------------------------------------------

struct IVec
{
	size_t len;
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
	size_t len;
	double *vec;
};

bool push_dvec(struct DVec *self, double value);
void pop_dvec(struct DVec *self);
void clear_dvec(struct DVec *self);
bool init_dvec(struct DVec *self);

#endif