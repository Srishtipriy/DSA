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
    //brute force approach
    //time complexity: O(n)
    //space complexity: O(n)
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        //base case
        if(root==NULL)
            return {};

        vector<vector<int>> arr;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();                  
            vector<int> level;                  //to store nodes at current level

            for(int i=0;i<size;i++)
            {
                TreeNode* ptr=q.front();
                q.pop();
                level.push_back(ptr->val);          //inserting curr node value in 'level'

                //inserting 'left' child in queue(if it exists)
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
            }
            arr.push_back(level);                   //inserting current 'level' into 'arr'
        }
        return arr;
    }
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        vector<vector<int>> levels  = levelOrder(root);   

        //inserting 'last element' of each level into vector 'ans'
        for(int i=0;i<levels.size();i++)
            ans.push_back(levels[i].back());
        return ans;
    }
};