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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 1;
        
        if(head == NULL)   return NULL;

        while(temp != NULL && count < k){
            temp = temp->next;
            count ++;
        }
        ListNode* slow = head;
        ListNode* fast = temp;

        while(fast->next != NULL ){
            fast = fast->next;
            slow = slow->next;
        }

    swap(temp->val , slow-> val);

    return head;
    }
};