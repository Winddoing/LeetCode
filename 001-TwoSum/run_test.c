#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>

#include "cmockery/cmockery.h"

// A test case that does nothing and succeeds.
void null_test_success(void **state) {
    printf("===> func: %s, line: %d\n", __func__, __LINE__);
}

int main(int argc, char* argv[]) {
    const UnitTest tests[] = {
        unit_test(null_test_success),
    };
    return run_tests(tests, "run");
}
