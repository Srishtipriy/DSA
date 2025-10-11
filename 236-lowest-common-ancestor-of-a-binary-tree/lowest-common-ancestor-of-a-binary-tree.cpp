/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)        
            return NULL;
        if( root== p ||  root== q ){       //root->val== q && root->val== p if they are no.s
            return root;                   //root->val;
        }
        TreeNode* leftans = lowestCommonAncestor(root->left, p, q );
        TreeNode* rightans = lowestCommonAncestor(root->right, p, q );

        if(leftans!= NULL && rightans!= NULL)       return root;  //jab dono m value h iska mtb common node h yeh 

        if(leftans== NULL && rightans!= NULL)       return rightans;

        if(leftans!= NULL && rightans== NULL)       return leftans;

        else return NULL;
    }
};