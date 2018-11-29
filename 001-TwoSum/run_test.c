#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>

#include "cmockery/cmockery.h"

#include "solution.h"

// A test case that does nothing and succeeds.
void solution_test(void **state) {
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int cnt = sizeof(nums) / sizeof(*nums);
    int ret[2] = {0, 1}; 

    assert_memory_equal(twosum(nums, cnt, target), ret, 2);
}

int main(int argc, char* argv[]) {
    const UnitTest tests[] = {
        unit_test(solution_test),
    };
    return run_tests(tests, "run");
}
