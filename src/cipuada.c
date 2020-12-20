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
#include <cipuada.h>

void __cipuada_assert(const char *msg, const char *file, const char* func, int line)
{
	fprintf(stderr, "%s in line %d in file %s with expression %s FAILED\n", func, line, file, msg);
}

void __cipuada_assert_equal_print(const char *ex1, const char *ex2, const char *file, const char *func, int line)
{
	fprintf(stderr, "%s in line %d in file %s expected %s, but %s was given instead FAILED\n", func, line, file, ex1, ex2);
}

void __cipuada_success_print(const char *func)
{
	fprintf(stdout, "%s finished OK\n", func);
}
