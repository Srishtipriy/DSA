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
class Solution {
public:
    bool solve(TreeNode* &root) {
        if (!root) return true;

        bool left = solve(root->left);
        bool right = solve(root->right);

        // isolate child if prune found
        if (left) {
            root->left = NULL;
        }
        if (right) {
            root->right = NULL;
        }

        // if curr become leaf node with val = 0
        return (root->val == 0 && !root->left && !root->right);
    }

    TreeNode* pruneTree(TreeNode* root) {
        // if curr become leaf node with val = 0
        if (solve(root)) {
            return NULL;
        }
    return root;
    }
};