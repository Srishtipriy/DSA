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
    pair<int, int> dfs(TreeNode* root){         //Maximum sum if we rob this node 1int--> rob ,2int-->not rob
        if(!root) return {0, 0};                // if root is null

        auto left = dfs(root->left);                //auto ki jagah pair<in><int> bhi likh sakte h 
        auto right = dfs(root->right);              //.first ->sum if that child is robbed

        
        //we take the node’s value + the “not rob” values of its child
        int rob_this = root->val + left.second + right.second;
        //we don’t rob this node, we’re free to rob or not rob its children-->we take the better
        int not_rob_this = max(left.first, left.second) + max(right.first, right.second);

        return {rob_this, not_rob_this};
    }
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};