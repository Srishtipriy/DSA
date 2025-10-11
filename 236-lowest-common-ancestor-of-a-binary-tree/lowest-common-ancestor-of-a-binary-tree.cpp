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

        return !leftans ? rightans : !rightans ? leftans : root;

    }
};
        /*
            !leftans → means “if leftans is NULL”. yes then right print kro usme value hogi
            if leftans is not null ---> and rightans is null----> leftans.
            if leftans is not null ---> and rightans is not null ----> root.

            if (leftans && rightans) return root;
            if (leftans) return leftans;
            if (rightans) return rightans;
            return NULL;                                                */