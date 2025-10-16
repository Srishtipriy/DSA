class Solution {
public:
    vector<int> getPreorder(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                preorder.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Make a temporary link and visit node (preorder: visit before going left)
                    preorder.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // Remove the temporary link
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }

        return preorder;
    }

    // \U0001f447 rename this function to match the problem name
    vector<int> preorderTraversal(TreeNode* root) {
        return getPreorder(root);
    }
};
