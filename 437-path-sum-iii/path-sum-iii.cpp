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
    int ans=0;

    void dfs(TreeNode* root, long long sum){
        if(!root) return;               //if root is null
        if(root->val==sum) ans++;       //root value alone is equal to ans

        dfs( root->left, sum-root->val );
        dfs( root->right, sum-root->val );
    }

    int pathSum(TreeNode* root, int sum) {
        if(root){
            dfs ( root,sum );                          //count paths starting at curr node
            pathSum( root->left, sum );                // check paths starting in left subtree
            pathSum( root->right, sum );
        }
        return ans;
    }
};