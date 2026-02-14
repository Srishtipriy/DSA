/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };*/
class Solution {
public:
    int maxSum = INT_MIN;       //global variable so multiple times crete na ho

    int solve(TreeNode* root){    

        if(root == NULL)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int neeche_se_milega_ans = l + r + root->val;   //1

        int koi_ek_acha = max(l,r) + root->val;         //2

        int sirf_root_acha = root->val;                 //3

        maxSum = max(maxSum, max( neeche_se_milega_ans, max (koi_ek_acha, sirf_root_acha)));

        //important part 2 3 taken only
        return max( koi_ek_acha, sirf_root_acha);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};