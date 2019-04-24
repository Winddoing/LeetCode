#include <stdio.h>
#include <stdlib.h>

#include <setjmp.h>
#include <stdint.h>

#include "cmockery/cmockery.h"

#include "solution.h"

// A test case that does nothing and succeeds.
void solution_test(void **state)
{
    //assert_memory_equal(test_func(), ret, 2);
}

int main(int argc, char* argv[])
{
    const UnitTest tests[] = {
        unit_test(solution_test),
    };
    return run_tests(tests, "run");
}
