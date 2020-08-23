#include <iostream>
#include <string>

#include "gtest/gtest.h"

namespace
{
    TEST(FailTest, Zero)
    {
        EXPECT_EQ(1, 0);
    }

    TEST(PassTest, Zero)
    {
        EXPECT_EQ(1, 1);
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}