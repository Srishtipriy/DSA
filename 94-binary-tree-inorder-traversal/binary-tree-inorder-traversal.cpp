class Solution {
public:
    vector<int> getInorder(TreeNode* root) {       
        vector<int> inorder;                       
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                inorder.push_back(cur->val);       // CHANGED: same action, name changed
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = cur;             //from here push_back moved down
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    inorder.push_back(cur->val);   // CHANGED: moved push_back here (visit AFTER restoring link)
                    cur = cur->right;
                }
            }
        }

        return inorder;                            
    }

    vector<int> inorderTraversal(TreeNode* root) { 
        return getInorder(root);                   
    }
};
