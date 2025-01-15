#include <gtest/gtest.h>
#include "vs_cmake_template_lib.h"

TEST(Test, Add12) {
    EXPECT_EQ(3, Add(1, 2));
}

TEST(Test, Add21)
{
    EXPECT_EQ(3, Add(2, 1));
}
3