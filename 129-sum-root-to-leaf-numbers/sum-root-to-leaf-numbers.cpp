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
    int solve(TreeNode* root, int sum){
        sum = sum*10 + root->val;

        if(root->left && root->right){
            return solve( root->left ,sum ) + solve( root->right , sum);
        }

        if(root->left)  return solve(root->left , sum);
        if(root->right) return solve(root->right, sum);

        return sum;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root , 0);
    }
};