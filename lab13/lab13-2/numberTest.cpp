#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <number.h>

using namespace testing;

TEST(IsFirstTest, Test1){
    ASSERT_EQ(true, isPrime(1, 2));
}
TEST(IsFirstTest, Test2){
    ASSERT_EQ(true, isPrime(2, 2));
}
TEST(IsFirstTest, Test3){
    ASSERT_EQ(true, isPrime(3, 2));
}
TEST(IsFirstTest, Test4){
    ASSERT_EQ(true, isPrime(4, 2));
}
TEST(IsFirstTest, Test5){
    ASSERT_EQ(true, isPrime(5, 2));
}
