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
    // Collect inorder traversal values
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    // Build right-skewed BST from inorders
    TreeNode* makeBST(const vector<int>& ans) {
        if (ans.empty()) return nullptr;

        TreeNode* newRoot = new TreeNode(ans[0]);
        TreeNode* curr = newRoot;

        for (int i = 1; i < ans.size(); i++) {
            curr->right = new TreeNode(ans[i]);
            curr = curr->right;
        }

        return newRoot;
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);      // Step 1: Get inorder values
        return makeBST(ans);     // Step 2: Build new tree
    }
};
