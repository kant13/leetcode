#include <gtest/gtest.h>
#include <string>
#include <iostream>

using namespace std;

// Easy 28. Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/


class Solution {
public:
    int strStr(string haystack, string needle) {
        const size_t id = haystack.find(needle);
        return id == string::npos ? -1 : id;
    }

    int strStr2(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i < n - m + 1; ++i) {
            int j = 0;
            for (; j < m; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == m) {
                return i;
            }
        }
        return -1;
    }

    // KMP String Matching Algorithm
    // Assuming the length of the string haystack is n
    // and the length of the string needle is m,
    // the time complexity is O(n + m), and the space
    // complexity is O(m).

    // Rabin-Karp String Matching Algorithm
    // Assuming the length of the string haystack is n
    // and the length of the string needle is m,
    // the time complexity is O(n + m), and the space
    // complexity is O(1).
};

//Example 1:
//
//Input: haystack = "sadbutsad", needle = "sad"
//Output : 0
//Explanation : "sad" occurs at index 0 and 6.
//The first occurrence is at index 0, so we return 0.
//Example 2 :
//
//Input : haystack = "leetcode", needle = "leeto"
//Output : -1
//Explanation : "leeto" did not occur in "leetcode", so we return -1.

TEST(strStr, Example1) {
    Solution solution;
    string haystack = "sadbutsad";
    string needle = "sad";
    EXPECT_EQ(solution.strStr(haystack, needle), 0);
}

TEST(strStr, Example2) {
    Solution solution;
    string haystack = "leetcode";
    string needle = "leeto";
    EXPECT_EQ(solution.strStr(haystack, needle), -1);
}
