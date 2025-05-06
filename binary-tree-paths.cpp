#include <gtest/gtest.h>

#include <iostream>
#include <algorithm>

using namespace std;

// Easy 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/description/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root) {
            dfs(root, "", paths);
        }
        return paths;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        // Append the current node's value to the path
        path += to_string(node->val);

        // If it's a leaf node, add the path to the result
        if (!node->left && !node->right) {
            paths.push_back(path);
        }
        else {
            // Otherwise, continue the path with "->" and recurse
            path += "->";
            if (node->left) dfs(node->left, path, paths);
            if (node->right) dfs(node->right, path, paths);
        }
    }
};

// Input: root = [1, 2, 3, null, 5]
// Output : ["1->2->5", "1->3"]
/*
      1
     / \
     2  3
     \
      5
*/
TEST(binaryTreePaths, Example1) {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2, nullptr, new TreeNode(5));
	root->right = new TreeNode(3);

	Solution solution;
	vector<string> result = solution.binaryTreePaths(root);
	EXPECT_EQ(result.size(), 2);
	EXPECT_EQ(result[0], "1->2->5");
	EXPECT_EQ(result[1], "1->3");

	// Clean up
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;

}

// Input: root = [1]
// Output : ["1"]
TEST(binaryTreePaths, Example2) {
	TreeNode* root = new TreeNode(1);
	Solution solution;

	vector<string> result = solution.binaryTreePaths(root);
	EXPECT_EQ(result.size(), 1);
	EXPECT_EQ(result[0], "1");

	// Clean up
	delete root;
}