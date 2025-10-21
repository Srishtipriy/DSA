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
    vector<int> preorder(Node* root) {
        if(root== NULL)     return {};

        vector<int> res;
        res.push_back(root->val);

        for (Node* child : root->children) {

            vector<int> childRes = preorder(child);
            for (int val : childRes) {
                res.push_back(val);
            }
        }

        return res;
    }
};
/*
Binary tree → left and right.
N-ary tree → children vector.
To traverse an N-ary tree, always iterate over root->children
*/