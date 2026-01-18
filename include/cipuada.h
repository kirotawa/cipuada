#ifndef __CIPUADA__

#include <stdbool.h>


void __cipuada_assert(const char*, const char*, const char*, int);
void __cipuada_success_print(const char*);
void __cipuada_assert_equal_print(const char*, const char*, const char*, const char*, int);
bool __cipuada_assert_match(const char*, const char*);
void __cipuada_regex_match_failed(const char*, const char*, const char*, const char*, int);


#define cipuada_assert(EX) { \
		if((EX)) __cipuada_success_print(__func__); \
       		else __cipuada_assert(#EX, __FILE__, __func__, __LINE__); \
	}
#define cipuada_assert_equal(EX1, EX2) (void)((EX1 == EX2) || \
		     (__cipuada_assert_equal_print(#EX1, #EX2, __FILE__, __func__, __LINE__), 0))
#define cipuada_assert_true(EX) cipuada_assert(EX == true)
#define cipuada_assert_false(EX) cipuada_assert(EX == false)
#define cipuada_assert_match(EX1, EX2) { \
		if(__cipuada_assert_match(EX1, EX2)) __cipuada_success_print(__func__); \
	        else __cipuada_regex_match_failed(EX1, EX2, __FILE__, __func__, __LINE__); \
	}

#endif // __CIPUADA__
