#include <gtest/gtest.h>
#include <vector>

using namespace std;

// 344. Reverse String
// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {

    }
};

//Example 1:
//Input: s = ["h", "e", "l", "l", "o"]
//Output : ["o", "l", "l", "e", "h"]
//
//Example 2 :
//Input : s = ["H", "a", "n", "n", "a", "h"]
//Output : ["h", "a", "n", "n", "a", "H"]

TEST(reverseString, Example1) {
    Solution s;
    vector<char> input = { 'h', 'e', 'l', 'l', 'o' };
    s.reverseString(input);
    const vector<char> expected = { 'o', 'l', 'l', 'e', 'h' };
    ASSERT_EQ(expected, input);
}

TEST(reverseString, Example2) {
    Solution s;
    vector<char> input = { 'H', 'a', 'n', 'n', 'a', 'h' };
    s.reverseString(input);
    vector<char> expected = { 'h', 'a', 'n', 'n', 'a', 'H' };
    ASSERT_EQ(expected, input);
}