#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {

    }
};

// Example1
//Input: root = [1, 2, 2, 3, 4, 4, 3]
//Output : true
//
// Example2
//Input : root = [1, 2, 2, null, 3, null, 3]
//Output : false

void add(TreeNode* head, const vector<int>& in) {
    int pair = 0;
    for (int i = 0; i < in.size(); i) {
        pair++;
        if (pair == 1) {
            if (in[i] != 101) {
                head->left = new TreeNode(in[i]);
            }
        }
        if (pair == 2) {
            if (in[i] != 101) {
                head->right = new TreeNode(in[i]);
            }
            pair = 0;
        }
    }
}


TEST(isSymmetric, Example1) {
    Solution s;
    TreeNode head;
    const vector<int> input = { 1, 2, 2, 3, 4, 4, 3 };
    add(&head, input);
    ASSERT_EQ(true, s.isSymmetric(&head));
}

TEST(isSymmetric, Example2) {
    Solution s;
    TreeNode head;
    const vector<int> input = { 1, 2, 2, -101, 3, -101, 3 };
    add(&head, input);
    ASSERT_EQ(true, s.isSymmetric(&head));
}