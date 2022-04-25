#include <gtest/gtest.h>

#include "cls/UMLOperation.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(Operation, BasicAssertions)
{
    UMLOperation el = UMLOperation(std::string("here"));
    EXPECT_STREQ("here", el.name.c_str());
}