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
    int inorderTraversal(TreeNode* root, int& val, int& mindif){        //inorder so L-Root-R
        if(root== NULL)     return 0;                       

        inorderTraversal(root->left, val, mindif);
        
        if(val >= 0)
            mindif = min(mindif , (root->val - val) );
        val = root->val;

        inorderTraversal(root->right, val, mindif);
        return mindif;
    }
    int getMinimumDifference(TreeNode* root) {
        auto mindif = INT_MAX;
        int val = -1;
        return inorderTraversal(root , val , mindif);
    }
};