#include "pch.h"
#include <vector>
#include <string>

using namespace std;

namespace fizzBuzz {
    // 412. Fizz Buzz
    // https://leetcode.com/problems/fizz-buzz/

    class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> ret;
            for (int i = 1; i <= n; ++i) {
                if (!(i % 3) && !(i % 5)) {
                    ret.push_back("FizzBuzz");
                }
                else if (!(i % 3)) {
                    ret.push_back("Fizz");
                }
                else if (!(i % 5)) {
                    ret.push_back("Buzz");
                }
                else {
                    ret.push_back(std::to_string(i));
                }
            }
            return ret;
        }
    };

    //Example 1:
    //Input: n = 3
    //Output : ["1", "2", "Fizz"]

    //Example 2 :
    //Input : n = 5
    //Output : ["1", "2", "Fizz", "4", "Buzz"]

    //Example 3 :
    //Input : n = 15
    //Output : ["1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"]

    TEST(fizzBuzz, Example1) {
        Solution s;
        const vector<string> expected = { "1", "2", "Fizz" };
        ASSERT_EQ(expected, s.fizzBuzz(3));
    }

    TEST(fizzBuzz, Example2) {
        Solution s;
        const vector<string> expected = { "1", "2", "Fizz", "4", "Buzz" };
        ASSERT_EQ(expected, s.fizzBuzz(5));
    }

    TEST(fizzBuzz, Example3) {
        Solution s;
        const vector<string> expected = { "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz" };
        ASSERT_EQ(expected, s.fizzBuzz(15));
    }

} // namespace fizzBuzz