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
// inorder   = Left → Root → Right                  inorder  = [9, 3, 15, 20, 7]  n = 5
class Solution {
public:
    void createMapping( vector<int>& inorder, map<int ,int>& nodeToindex , int n) {
        for (int i = 0; i < n; i++) {
            //map[1st digit in inorder]           nodeToindex[9] = 0-->{9: 0} =>nodeToindex[3] = 1-->{9: 0, 3: 1}
            nodeToindex[inorder[i]] =i;                 //inorder of i ko map kar do index ke saath
        }               
    }
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int& postindex, int inorderStart,
        int inorderEnd, int n, map<int, int>& nodeToindex) {

        if (postindex < 0 || inorderStart > inorderEnd)
            return NULL;

        int element = postorder[postindex--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToindex[element];

        root->right = solve(postorder, inorder, postindex, position + 1, inorderEnd, n, nodeToindex );
        root->left  = solve(postorder, inorder, postindex, inorderStart, position - 1, n, nodeToindex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postindex = n - 1;
        map<int,int> nodeToindex;
        createMapping(inorder, nodeToindex , n);
        return solve(postorder, inorder, postindex, 0, n - 1, n, nodeToindex);
    }
};
