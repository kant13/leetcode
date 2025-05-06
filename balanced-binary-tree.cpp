#include <gtest/gtest.h>

#include <iostream>
#include <algorithm>

using namespace std;

// Easy 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/


// Definition for a binary tree node.
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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight) + 1;
    }
};

// Input: root = [3, 9, 20, null, null, 15, 7]
// Output : true
TEST(BalancedBinaryTreeTest, Example1) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution solution;
    EXPECT_TRUE(solution.isBalanced(root));

    // Clean up
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;
}

// Input : root = [1, 2, 2, 3, 3, null, null, 4, 4]
// Output : false
TEST(BalancedBinaryTreeTest, Example2) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)), new TreeNode(3));
    root->right = new TreeNode(2);

    Solution solution;
    EXPECT_FALSE(solution.isBalanced(root));

    // Clean up
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}

// Input : root = []
// Output : true
TEST(BalancedBinaryTreeTest, Example3) {
    TreeNode* root = nullptr;

    Solution solution;
    EXPECT_TRUE(solution.isBalanced(root));
}
