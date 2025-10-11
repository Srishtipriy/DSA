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
 //preorder = root - left - right
 //inorder  = left - root - right
class Solution {
public:
    int findposition(vector<int>&inorder, int element, int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == element)               return i;
        }
        return -1;
    }
    TreeNode* solve( vector<int>& preorder, vector<int>& inorder, int&preOindex, int inorderstart, int inorderend,int n) {
        if(preOindex == n || inorderstart > inorderend){
            return NULL;
        }
        int element = preorder[preOindex++];
        TreeNode* nroot = new TreeNode(element);
        int position = findposition(inorder, element, n);

        //recursive calls
        nroot->left = solve(preorder,inorder, preOindex, inorderstart , position-1 , n);
        nroot->right = solve(preorder,inorder, preOindex, position+1 , inorderend , n);

        return nroot;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOindex = 0;
        int n = preorder.size();
        TreeNode* ans= solve(preorder, inorder, preOindex, 0, n-1, n);          //0 is inoindex
        return ans;
    }
};