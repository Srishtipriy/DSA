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
#include <queue>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0; 

        queue<pair<TreeNode*, int>> q;  // q to store nodes along with their depth
        q.push({root, 1});  // Start with the root node at depth 1
        
        while (!q.empty()) {
            auto [node, depth] = q.front();  // Get the front node and its depth
            q.pop();
            
            if (!node->left && !node->right) {          // If this is a leaf node, return its depth
                return depth;
            }
            
            // If there is a left child, add it the q with depth + 1
            if (node->left) {
                q.push({node->left, depth + 1});
            }
            
            // If right child, add it to the q with depth + 1
            if (node->right) {
                q.push({node->right, depth + 1});
            }
        }
        
        return 0;  // This line will never be reached if the tree is valid
    }
};