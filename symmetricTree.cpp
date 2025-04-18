#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/description/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// The number of nodes in the tree is in the range[1, 1000].
// - 100 <= Node.val <= 100
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true; // An empty tree is symmetric
        }
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true; // Both subtrees are empty
        }
        if (!left || !right) {
            return false; // One subtree is empty, the other is not
        }
        return (left->val == right->val) // Values must match
            && isMirror(left->left, right->right) // Left subtree of left matches right subtree of right
            && isMirror(left->right, right->left); // Right subtree of left matches left subtree of right
    }

    bool isSymmetric2(TreeNode* root) {
        if (!root) {
            return true;
        }

        if (!root->left && !root->right) {
            return true;
        }

        std::vector<int> leftList;
        preorderLeft(root->left, leftList);
        std::vector<int> rightList;
        preorderRight(root->right, rightList);

        return leftList == rightList;
    }

    void preorderLeft(TreeNode* node, std::vector<int>& preorderList) {
        if (!node) {
            preorderList.push_back(-101);
            return;
        }

        preorderList.push_back(node->val);
        preorderLeft(node->left, preorderList);
        preorderLeft(node->right, preorderList);
    }

    void preorderRight(TreeNode* node, std::vector<int>& preorderList) {
        if (!node) {
            preorderList.push_back(-101);
            return;
        }

        preorderList.push_back(node->val);
        preorderRight(node->right, preorderList);
        preorderRight(node->left, preorderList);
    }
};

// Example1
// Input: root = [1, 2, 2, 3, 4, 4, 3]
// Output : true
/*
              1
           /    \
          2      2
         / \    / \
        3   4  4   3
*/
TEST(isSymmetric, Example1) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    ASSERT_EQ(true, s.isSymmetric(root));
}

// Example2
// Input : root = [1, 2, 2, null, 3, null, 3]
// Output : false
/*
             1
           /    \
          2      2
           \      \
            3      3
*/
TEST(isSymmetric, Example2) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);

    ASSERT_EQ(false, s.isSymmetric(root));
}

TEST(isSymmetric, Example3) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    ASSERT_EQ(true, s.isSymmetric(root));
}

TEST(isSymmetric, Example4) {
    Solution s;
    TreeNode* root = nullptr;
    ASSERT_EQ(true, s.isSymmetric(root));
}

// [1,2,2,null,3,3]
/*
              1
           /    \
          2      2
         /  \    / \
        null 3   3   null
*/

TEST(isSymmetric, Example5) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    ASSERT_EQ(true, s.isSymmetric(root));
}