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
    void inorder(TreeNode* root , vector<int> &in){           //firsst make the inorder
        if(root ==NULL)     return;

        inorder(root->left , in);
        in.push_back(root->val);
        inorder(root->right , in);
    }
    TreeNode * inordertoBST( int s , int e, vector<int>& in){
        if(s>e)     return NULL;                              //take mid and divide

        int mid = (s+e) /2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = inordertoBST( s, mid-1 , in);
        root->right= inordertoBST( mid+1 , e, in);
        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderesult;
        inorder(root , inorderesult);               //call

        return inordertoBST( 0 , inorderesult.size()-1 , inorderesult);
    }
};