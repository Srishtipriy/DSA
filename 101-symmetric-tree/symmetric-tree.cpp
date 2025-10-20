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
    bool issametree(TreeNode* p, TreeNode* q){
         if(p == NULL || q ==NULL){
            return ( p == q );
        }

        return (p-> val == q-> val) && issametree(p->left , q->right) &&
                                       issametree(p->right, q->left );
       
    }
    bool isSymmetric(TreeNode* root) {
        return issametree(root->left, root->right);
    }
};