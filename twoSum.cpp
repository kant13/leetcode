#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return { i, j };
                }
            }
        }
        return {};
    }
};

//Example 1:
//Input: nums = [2, 7, 11, 15], target = 9
//Output : [0, 1]
//Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].
//
//Example 2 :
//Input : nums = [3, 2, 4], target = 6
//Output : [1, 2]
//
//Example 3 :
//Input : nums = [3, 3], target = 6
//Output : [0, 1]

TEST(twoSum, Example1) {
    Solution s;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> expected = { 0, 1 };
    ASSERT_EQ(s.twoSum(nums, target), expected);
}

TEST(twoSum, Example2) {
    Solution s;
    vector<int> nums = { 3, 2, 4 };
    int target = 6;
    vector<int> expected = { 1, 2 };
    ASSERT_EQ(s.twoSum(nums, target), expected);
}

TEST(twoSum, Example3) {
    Solution s;
    vector<int> nums = { 3, 3 };
    int target = 6;
    vector<int> expected = { 0, 1 };
    ASSERT_EQ(s.twoSum(nums, target), expected);
}
