#include <gtest/gtest.h>
#include <vector>
#include <stack>

using namespace std;

// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                if (st.empty()) return false;
                char top = st.top();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

//Example 1:
//Input: s = "()"
//Output : true
//
//Example 2 :
//    Input : s = "()[]{}"
//    Output : true
//
//Example 3 :
//Input : s = "(]"
//Output : false
//
//Example 4 :
//Input : s = "([])"
//Output : true

TEST(ValidParentheses, Example1) {
    Solution s;
    string input = "()";
    ASSERT_EQ(true, s.isValid(input));
}

TEST(ValidParentheses, Example2) {
    Solution s;
    string input = "()[]{}";
    ASSERT_EQ(true, s.isValid(input));
}

TEST(ValidParentheses, Example3) {
    Solution s;
    string input = "(]";
    ASSERT_EQ(false, s.isValid(input));
}

TEST(ValidParentheses, Example4) {
    Solution s;
    string input = "([])";
    ASSERT_EQ(true, s.isValid(input));
}

TEST(ValidParentheses, Example5) {
    Solution s;
    string input = "([{}])";
    ASSERT_EQ(true, s.isValid(input));
}

TEST(ValidParentheses, Example54) {
    Solution s;
    string input = "([)]";
    ASSERT_EQ(false, s.isValid(input));
}

TEST(ValidParentheses, Example78) {
    Solution s;
    string input = "((";
    ASSERT_EQ(false, s.isValid(input));
}

TEST(ValidParentheses, Example84) {
    Solution s;
    string input = "(){}}{";
    ASSERT_EQ(false, s.isValid(input));
}

TEST(ValidParentheses, Example87) {
    Solution s;
    string input = "({{{{}}}))";
    ASSERT_EQ(false, s.isValid(input));
}
