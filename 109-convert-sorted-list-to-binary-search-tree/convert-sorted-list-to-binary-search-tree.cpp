/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head== NULL)             return NULL;
        if(head->next==NULL)         return new TreeNode(head->val);            //if only one ele

        ListNode* slow_prev = NULL;                     //pointers for LL
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL && fast->next!= NULL){      //y linkedlist pointr the so .next use kiy if treenode hote toh 
            slow_prev = slow;                        // ->left ->right use hota and if node then .right
            slow = slow->next;
            fast = fast->next->next;                  //abh jab end mil gaya toh left se coonection todo
        }
        TreeNode* Root = new TreeNode(slow->val);        //root ban gaya slow pointer becox of return type
        slow_prev->next = NULL;                          //slow_prev ka connection toda
        Root->left = sortedListToBST( head);
        Root->right = sortedListToBST(slow->next);
        
        return Root;

    }
};

//A linked list node only connects to the next element in the sequence → so it has a single pointer:
//A binary tree node connects to two subtrees — left and right → so it has:

//. (dot) → when you have an object (not a pointer)

//-> (arrow) → when you have a pointer to an object