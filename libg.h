#ifndef LIBG
#define LIBG

#define TYPE int

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int64_t i64;
typedef uint64_t u64;

// Dstring
//--------------------------------------------------------------------------

typedef struct Dstring Dstring;

struct Dstring {
	u64 len;
	char* string;

	bool (*get_input)(Dstring*);
	bool (*push_char)(Dstring*, char);
	bool (*push_string)(Dstring*, char*);
	bool (*set_string)(Dstring*, char*);
	void (*clear)(Dstring*);
};

bool get_input_dstring(Dstring* self);
bool push_char_dstring(Dstring* self, char c);
bool push_string_dstring(Dstring* self, char *str);
void clear_dstring(Dstring* self);
bool init_dstring(Dstring* self);


// IVec
//-------------------------------------------------------------------------

typedef struct IVec IVec;

struct IVec {
	u64 len;
	i64* vec;

	bool (*push)(IVec*, i64);
	void (*pop)(IVec*);
	void (*clear)(IVec*);
};

bool push_ivec(IVec* self, i64 value);
void pop_ivec(IVec* self);
void clear_ivec(IVec* self);
bool init_ivec(IVec* self);


// DVec
//-------------------------------------------------------------------------

typedef struct DVec DVec;

struct DVec {
	u64 len;
	double* vec;

	bool (*push)(DVec*, double);
	void (*pop)(DVec*);
	void (*clear)(DVec*);
};

bool push_dvec(DVec* self, double value);
void pop_dvec(DVec* self);
void clear_dvec(DVec* self);
bool init_dvec(DVec* self);

// DDouble
//-------------------------------------------------------------------------

/*
enum ddouble_special_char {
	dot = 10, neg,
};

typedef struct DDouble DDouble;

struct DDouble {
	u64 len;
	u64* num;

	bool (*set_num)(DDouble*, char*);
	void (*print_num)(DDouble*);
	void (*clear)(DDouble*);
};

bool is_ddouble_num(char c);
bool set_ddouble_num(DDouble* self, char* str);
void clear_ddouble_num(DDouble* self);
bool init_ddouble_num(DDouble* self);
*/

#endif