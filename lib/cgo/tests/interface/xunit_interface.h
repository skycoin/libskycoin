#ifndef LIB_SKYCOIN_TEST_X_UNIT_TEST
#define LIB_SKYCOIN_TEST_X_UNIT_TEST

#include <stdbool.h>

typedef  struct {
 void (*assert_msg) (bool expr, const char * format, ...);
 void (*assert) (bool expr);
} xUnitTest;

#endif  // LIB_SKYCOIN_TEST_X_UNIT_TEST
