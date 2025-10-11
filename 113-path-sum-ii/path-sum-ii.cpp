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
    void solve(TreeNode* root, int tsum ,vector<int>& currpath, vector<vector<int>> & ans){
        if(root==NULL)      return ;

        currpath.push_back(root->val);                      // Add current node to path
        
        if(root->left==NULL && root->right==NULL && tsum == root->val){
            ans.push_back(currpath);                         // Found one valid path
        }   
        else{
            solve( root->left, tsum - root->val, currpath, ans );
            solve( root->right, tsum - root->val, currpath, ans );       // otherwise continue search
        }
        currpath.pop_back(); 
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currpath;
        solve(root ,targetSum, currpath, ans);
        return ans;
    }
};