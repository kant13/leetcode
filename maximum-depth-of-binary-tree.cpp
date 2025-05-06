#include <gtest/gtest.h>

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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
};

// Example 1
// Input: root = [3,9,20,null,null,15,7]
// Output: 3
/*
        3
       / \
      9   20
         /  \
        15   7
*/
TEST(maxDepth, Example1) {
    Solution s;
    TreeNode* root = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20, new TreeNode(15), new TreeNode(7))
    );
    EXPECT_EQ(s.maxDepth(root), 3);
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
}

// Example 2
// Input: root = [1,null,2]
// Output: 2
/*
        1
         \
          2
*/
TEST(maxDepth, Example2) {
    Solution s;
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2));
    EXPECT_EQ(s.maxDepth(root), 2);
    delete root->right;
    delete root;
}

TEST(maxDepth, NullTree) {
    Solution s;
    TreeNode* root = nullptr;
    EXPECT_EQ(s.maxDepth(root), 0);
}

TEST(maxDepth, SingleNodeTree) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    EXPECT_EQ(s.maxDepth(root), 1);
    delete root;
}

TEST(maxDepth, LeftSkewedTree) {
    Solution s;
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    EXPECT_EQ(s.maxDepth(root), 3);
    delete root->left->left;
    delete root->left;
    delete root;
}

TEST(maxDepth, RightSkewedTree) {
    Solution s;
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    EXPECT_EQ(s.maxDepth(root), 3);
    delete root->right->right;
    delete root->right;
    delete root;
}

TEST(maxDepth, BalancedTree) {
    Solution s;
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    EXPECT_EQ(s.maxDepth(root), 2);
    delete root->left;
    delete root->right;
    delete root;
}

TEST(maxDepth, ComplexTree) {
    Solution s;
    TreeNode* root = new TreeNode(1, 
        new TreeNode(2, new TreeNode(4), new TreeNode(5)), 
        new TreeNode(3, nullptr, new TreeNode(6, new TreeNode(7), nullptr))
    );
    EXPECT_EQ(s.maxDepth(root), 4);
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
}