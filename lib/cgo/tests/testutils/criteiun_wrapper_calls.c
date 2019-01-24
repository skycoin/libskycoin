#include "criteiun_wrapper_calls.h"

#include <stdbool.h>
#include <stdio.h>

#include <criterion/criterion.h>
#include <criterion/new/assert.h>

void assert_msg(bool condition, const char * format, ...) {
	char err_msg[50];
	snprintf(err_msg, sizeof(err_msg), format);
	cr_assert(condition, "%s", err_msg);
}

void assert(bool condition) {
	cr_assert(condition);
}

xUnitTest create_test_framework_wrapper() {
	xUnitTest criteriun_test_wrapper;
	criteriun_test_wrapper.assert_msg = assert_msg;
	criteriun_test_wrapper.assert = assert;
	return criteriun_test_wrapper;
}

