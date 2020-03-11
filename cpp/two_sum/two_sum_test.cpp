#include "two_sum.hpp"
#include "gtest/gtest.h"

TEST(twoSum, checkTwoSum) {
    std::vector<int> testCase1Set = { 2, 7, 11, 15};
    std::vector<int> testCase2Set = { 1, 3, 5, 7, 11, 15};
    std::vector<int> testCase3Set = { 1, 3, 5, 7, 9, 12, 15};
    std::vector<unsigned int> testCase1Result = { 0, 1 }; // int promijenjen u unsigned
    std::vector<unsigned int> testCase2Result = { 0, 2 }; // zbog errora koji je bazel
    std::vector<unsigned int> testCase3Result = { 2, 4 }; // javljao

    EXPECT_EQ(twoSum(testCase1Set, 9), testCase1Result);
    EXPECT_EQ(twoSum(testCase2Set, 6), testCase2Result);
    EXPECT_EQ(twoSum(testCase3Set, 14), testCase3Result);
}