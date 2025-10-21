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
    int countNodes(TreeNode* a) {
        queue<TreeNode* > q;
        q.push(a);
        int cnt = 0;

        while(q.front()){
            a = q.front();
            q.pop();
            cnt++;
            q.push(a->left);
            q.push(a->right);
        }
        return cnt;
    }
};