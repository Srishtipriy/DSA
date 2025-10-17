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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr!= NULL){
            if(curr->left){                      //jab tak left node ho
                                     
                TreeNode* prev = curr-> left;  

                while(prev->right){                 // jab tak right exists karta h 
                    prev = prev->right;             //move right till end rightmost node
                }
                prev->right = curr->right;          //change the directions of rightmost->cur right
                curr->right = curr->left;           //change curr right to left
                curr->left = NULL;
            }
            curr = curr->right;                     //next iteration.
        }
        
    }
};