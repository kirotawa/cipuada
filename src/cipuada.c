/* Copyright 2020 Leonidas S. Barbosa <lndsbarbosa@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in the
Software without restriction, including without limitation the rights to use, copy,
modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <regex.h>
#include <cipuada.h>

// Test function signature
typedef void (*cipuada_test)(void);

void __cipuada_failed_print(const char *msg, const char *file, const char* func, int line)
{
	fprintf(stderr, "%s in line %d in file %s after evaluate: %s - FAILED\n", func, line, file, msg);
}

void __cipuada_assert_equal_print(const char *ex1, const char *ex2, const char *file, const char *func, int line)
{
	fprintf(stderr, "%s in line %d in file %s expected %s, but %s was given instead FAILED\n", func, line, file, ex1, ex2);
}

void __cipuada_success_print(const char *func)
{
	fprintf(stdout, "%s finished OK\n", func);
}

void __cipuada_regex_match_failed(const char*pattern, const char* target_str, const char*file, const char* func, int line)
{
	const char* no_match_msg = "No match found!";
	char buff[200];

	snprintf(buff, sizeof(buff), "%s for pattern %s and target %s", no_match_msg, pattern, target_str);

	__cipuada_failed_print(buff, file, func, line);
}

bool __cipuada_assert_match(const char* pattern, const char* target_str)
{
	regex_t regex;
	int ret = 0;

	ret = regcomp(&regex, pattern, REG_EXTENDED);
	if (ret) {
		fprintf(stderr, "Could not compile regex\n");
		return false;
	}

	ret = regexec(&regex, target_str, 0, NULL, 0);

	if (!ret) {
		return true;
	} else if (ret == REG_NOMATCH) {
		return false;
	} else {
		return false; // some error that should be handle by regerror had occurred.
	}
}
