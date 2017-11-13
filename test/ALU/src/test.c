#include <stdio.h>
#include "minunit.h"
#include "operations.h"


 int tests_run = 0;

/*
 * This tests to see if the add function can properly add two ints with the
 * standard overflow
 */
static char *test_add()
{
    mu_assert("Error in add: test 1 failed", add(0,0) == 0);
    mu_assert("Error in add: test 2 failed", add(-4,4) == 0);
    mu_assert("Error in add: test 3 failed", add(INT_MAX,1) == INT_MIN);
    mu_assert("Error in add: test 4 failed", add(1,1) == 2);

    return 0;
}
/*
 * This tests to see if the subtract function can properly subtract two ints with the
 * standard overflow
 */
static char *test_subtract()
{
    mu_assert("Error in subtract: test 1 failed", subtract(0,0) == 0);
    mu_assert("Error in subtract: test 2 failed", subtract(-4,4) == -8);
    mu_assert("Error in subtract: test 3 failed", subtract(INT_MAX,1) == INT_MAX - 1);
    mu_assert("Error in subtract: test 4 failed", subtract(INT_MIN,1) == INT_MAX);

    return 0;
}
/*
 * This tests to see if the mulitply function can properly multiply two ints
 * with the standard overflow
 */
static char *test_multiply()
{
    mu_assert("Error in multiply: test 1 failed", multiply(0,0) == 0);
    mu_assert("Error in multiply: test 2 failed", multiply(INT_MAX,-1) == INT_MAX * -1);
    mu_assert("Error in multiply: test 3 failed", multiply(-3, 2) == -6);
    mu_assert("Error in multiply: test 4 failed", multiply(INT_MIN,-1) == INT_MIN);

    return 0;
}
/*
 * This tests to see if the divide function can properly multiply two ints
 * with the standard overflow. It also tests to see if division by 0 returns
 * division error
 */
static char *test_divide()
{
    mu_assert("Error in divide: test 1 failed", divide(0,1) == 0);
    mu_assert("Error in divide: test 2 failed", divide(-15,5) == -3);
    mu_assert("Error in divide: test 3 failed", divide(0,0) == DIVISION_ERROR);
    mu_assert("Error in divide: test 4 failed", divide(INT_MAX, -1) == -INT_MAX);

    return 0;
}

static char *all_tests()
{
    mu_run_test(test_add);
    mu_run_test(test_subtract);
    mu_run_test(test_multiply);
    mu_run_test(test_divide);

    return 0;
}


 int main(int argc, char **argv)
 {
    char *result = all_tests();

    if (result != 0)
    {
        printf("%s\n", result);
    }

    else
    {
        printf("All Tests Passed!\n");
    }

    printf("Tests run: %d\n", tests_run);

    return result != 0;
 }
