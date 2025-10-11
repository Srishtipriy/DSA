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

// postorder = Left → Right → Root
// inorder   = Left → Root → Right

class Solution {
public:
    int findPosition(vector<int>& inorder, int element, int n) {
        for (int i = 0; i < n; i++) {
            if (inorder[i] == element)
                return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& postindex, int inorderStart,
        int inorderEnd, int n) {
            
        if (postindex < 0 || inorderStart > inorderEnd)
            return NULL;

        int element = postorder[postindex--];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder, element, n);

        root->right = solve(postorder, inorder, postindex, position + 1, inorderEnd, n);
        root->left  = solve(postorder, inorder, postindex, inorderStart, position - 1, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postindex = n - 1;
        return solve(postorder, inorder, postindex, 0, n - 1, n);
    }
};
