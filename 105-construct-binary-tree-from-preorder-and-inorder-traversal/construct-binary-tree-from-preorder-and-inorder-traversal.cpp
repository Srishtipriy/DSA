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
    int pre_index = 0;
    unordered_map<int,int> indices;
public:
    TreeNode* dfs(vector<int>& preorder, int left, int right){

        if( left>right )          return NULL;

        int rootval = preorder[pre_index++];
        TreeNode* root = new TreeNode(rootval);

        int mid = indices[rootval];      //indices hashmap to find where this root is located in the inorder array

        root->left = dfs(preorder, left, mid-1);
        root->right = dfs(preorder, mid+1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0 ; i<inorder.size(); i++){
            indices[inorder[i]] = i;                        // store indices for O(1) lookup
        }        
        return dfs(preorder, 0, inorder.size()-1);
    }
};