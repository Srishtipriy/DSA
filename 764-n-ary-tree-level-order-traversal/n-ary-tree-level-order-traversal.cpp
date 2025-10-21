/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)    return {};

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            
            int n = q.size();
            vector<int> level;      // level to store all the node values at the curr lvl

            for(int i =0; i<n ; i++)
            {
                Node* node = q.front();     //get the first node from the queue
                q.pop();
                level.push_back(node->val);   // add it to level
                for(auto n : node->children)  // this node may include other nodes, we add them all in q
                    q.push(n);
            }
            ans.push_back(level);       // we've processed this level, add it to ans
        }
        return ans;         //final ans
    }
};