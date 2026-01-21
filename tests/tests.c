#include <cipuada.h>

void test_if_true(void){
    cipuada_assert_true((42 == 42));
}

void test_if_equal(void) {
    cipuada_assert_equal(2,2);
}

void test_if_nequal(void) {
    cipuada_assert_nequal(2,3);
}

void test_if_false(void) {
    cipuada_assert_false(false);
}

void test_if_false2(void) {
    cipuada_assert_false((4 == 2*3))
}

void test_assert(void) {
    cipuada_assert(7>5);
}

void test_assert2(void) {
    cipuada_assert(2>-1);
}

void test_assert_match(void) {
    cipuada_assert_match("a[[:alnum:]]+c", "abc");
}

// run all tests
cipuada_run_tests()
    test_if_true,
    test_if_equal,
    test_if_nequal,
    test_if_false,
    test_if_false2,
    test_assert,
    test_assert2,
    test_assert_match,
end_tests

