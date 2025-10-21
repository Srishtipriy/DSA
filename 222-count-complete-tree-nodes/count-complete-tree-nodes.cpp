/**
 * Definition for root binary tree node.
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
    int countNodes(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        int cnt = 0;

        while(q.front()){
            root = q.front();
            q.pop();
            cnt++;
            q.push(root->left);
            q.push(root->right);
        }
        return cnt;
    }
};