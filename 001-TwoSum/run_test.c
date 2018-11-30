#include <stdio.h>
#include <stdlib.h>

/*#include <stdarg.h>*/
/*#include <stddef.h>*/
#include <setjmp.h>
#include <stdint.h>

#include "cmockery/cmockery.h"

#include "solution.h"

// A test case that does nothing and succeeds.
void solution1_test(void **state)
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int cnt = sizeof(nums) / sizeof(*nums);
    int ret[2] = {0, 1};

    assert_memory_equal(twoSum1(nums, cnt, target), ret, 2);
}

void solution2_test(void **state)
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int cnt = sizeof(nums) / sizeof(*nums);
    int ret[2] = {0, 1};

    assert_memory_equal(twoSum2(nums, cnt, target), ret, 2);
}

void solution3_test(void **state)
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int cnt = sizeof(nums) / sizeof(*nums);
    int ret[2] = {0, 1};

    assert_memory_equal(twoSum3(nums, cnt, target), ret, 2);
}

int main(int argc, char* argv[])
{
    const UnitTest tests[] = {
        unit_test(solution1_test),
        unit_test(solution2_test),
        unit_test(solution3_test),
    };
    return run_tests(tests, "run");
}
