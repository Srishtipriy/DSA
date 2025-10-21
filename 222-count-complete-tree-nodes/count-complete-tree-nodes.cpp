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
Complete binary tree, if the height of the leftmost path equals the height of the rightmost path, it means You can compute the number of nodes directly using:  nodes=2ℎ−1
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root== NULL)     return 0;
        
        int heightL = 0 , heightR = 0;
        TreeNode* L = root , *R  = root;

        while(L != NULL)
        {   heightL ++;
            L = L->left;
        }
        while( R != NULL){
            heightR ++;
             R = R->right;
        }
        if(heightL == heightR) 
            return pow(2 , heightL )-1;
        
        return 1+ countNodes(root->left) + countNodes(root->right);

    }
};