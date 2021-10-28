// Copyright 2021 @jxwleong. All rights reserved.

#ifdef TEST

#include "unity.h"

#include "../src/foo.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_foo_NeedToImplement(void) {
    TEST_IGNORE_MESSAGE("Need to Implement foo");
}


void test_foo_bar_expect_return_haha(void) {
    TEST_ASSERT_EQUAL_STRING("haha", bar());
}


#endif  // TEST
