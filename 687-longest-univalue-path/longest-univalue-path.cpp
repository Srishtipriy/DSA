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
    int ans = 0;

    int checkpath(TreeNode* root) {
        if (!root) return 0;

        int left = checkpath(root->left);
        int right = checkpath(root->right);

        int leftPath = 0, rightPath = 0;

        // extend path if same value
        if (root->left && root->left->val == root->val)
            leftPath = left + 1;

        if (root->right && root->right->val == root->val)
            rightPath = right + 1;

        // update global answer
        ans = max(ans, leftPath + rightPath);

        // return longest single direction
        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        checkpath(root);
        return ans;
    }
};