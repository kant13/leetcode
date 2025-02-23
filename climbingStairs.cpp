#include <gtest/gtest.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) { return n; }
        int first = 1, second = 1;
        for (int i = 2; i <= n; ++i) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;

    }
};

//Example 1:
//Input: n = 2
//Output : 2
//Explanation : There are two ways to climb to the top.
//1. 1 step + 1 step
//2. 2 steps

//Example 2 :
//Input : n = 3
//Output : 3
//Explanation : There are three ways to climb to the top.
//1. 1 step + 1 step + 1 step
//2. 1 step + 2 steps
//3. 2 steps + 1 step

TEST(climbStairs, Example1) {
    Solution s;
    int n = 2;
    int expected = 2;
    ASSERT_EQ(s.climbStairs(n), expected);
}

TEST(climbStairs, Example2) {
    Solution s;
    int n = 3;
    int expected = 3;
    ASSERT_EQ(s.climbStairs(n), expected);
}

TEST(climbStairs, Example3) {
    Solution s;
    int n = 1;
    int expected = 1;
    ASSERT_EQ(s.climbStairs(n), expected);
}

TEST(climbStairs, Example4) {
    Solution s;
    int n = 4;
    int expected = 5;
    ASSERT_EQ(s.climbStairs(n), expected);
}
