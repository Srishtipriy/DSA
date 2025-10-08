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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root ==NULL)    return result;

        queue<TreeNode*> q;
        q.push(root);
        bool lefttoRight = true;

        while(!q.empty()){

            int size = q.size();
            vector<int> ans(size);

            for(int i=0 ; i<size ; i++){
                TreeNode* Fnode = q.front();
                q.pop();

                int index = lefttoRight ? i : size - i- 1;

                ans[index] = Fnode->val;

                if(Fnode->left)
                    q.push(Fnode-> left);
                if(Fnode->right)
                    q.push(Fnode->right);
            }
            lefttoRight =! lefttoRight;
            result.push_back(ans);
        }
        return result;
    }
};