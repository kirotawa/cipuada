#include <cipuada.h>

void test_if_true(void){
    cipuada_assert_true((42 == 12));
}

void test_if_equal(void) {
    cipuada_assert_equal(2,3);
}

void test_if_false(void){
    cipuada_assert_false(false);
}

void test_assert(void) {
    cipuada_assert(2>5);
}

void test_assert2(void) {
    cipuada_assert(2>-1);
}

// run the tests
int main(void) {
    // Expected to fail
    test_if_true();
    // Expected to fail
    test_if_equal();
    // Expect to work
    test_if_false();
    // Expected to fail
    test_assert();
    // Expected to work
    test_assert2();
    return 0;
}
