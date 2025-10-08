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
    void solve(TreeNode* node, string path,  vector<string>& result){
        if(node== NULL)     
            return;
        path += to_string(node-> val);
        
        if(  node->left==NULL && node->right==NULL  ){
            result.push_back(path);
        }
        else{
            solve(node->left, path+"->" , result);
            solve(node->right, path+"->" , result);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        solve(root ,"", result);
        return result;

    }
};