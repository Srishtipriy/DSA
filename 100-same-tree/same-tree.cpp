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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== NULL && q==NULL)     return true;

        if(p==NULL && q!=NULL)      return false;       //q has leaf nodes left (remaining)
        if(p!=NULL && q==NULL)      return false;

        bool L = isSameTree(p->left, q->left);
        bool R = isSameTree(p->right, q->right);

        bool currval = p->val == q->val;            //bool T/F? when it gives ans of p->val and q->val
        if( L && R && currval){
            return true;
        }
        else 
            return false;
    }
};