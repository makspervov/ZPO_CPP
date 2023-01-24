#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <number.h>

using namespace testing;

TEST(IsFirstTest, Test1){
    EXPECT_THROW(reverse(1), std::runtime_error);
}
TEST(IsFirstTest, Test2){
    EXPECT_THROW(reverse(2), std::runtime_error);
}
TEST(IsFirstTest, Test3){
    EXPECT_THROW(reverse(3), std::runtime_error);
}
TEST(IsFirstTest, Test4){
    EXPECT_THROW(reverse(0), std::runtime_error);
}
TEST(IsFirstTest, Test5){
    EXPECT_THROW(reverse(5), std::runtime_error);
}
